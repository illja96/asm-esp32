#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLE2902.h>
#include <stdio.h>

#include "src/AirsoftSmartMineSettings.h"

#include "src/Constants/AirsoftSmartMineBLECharacteristics.h"
#include "src/Constants/AirsoftSmartMineBLECharacteristicNames.h"
#include "src/Constants/AirsoftSmartMineBLECharacteristicDefaultValues.h"
#include "src/Constants/AirsoftSmartMineBLECharacteristicProperties.h"
#include "src/Constants/AirsoftSmartMineBLECharacteristicCallbacks.h"
#include "src/Callbacks/AirsoftSmartMineBLEServerCallbacks.h"
#include "src/Callbacks/AirsoftSmartMineBLEServerSecurityCallbacks.h"

const std::string _EspLogTag = "AirsoftSmartMine";

AirsoftSmartMineBLEServerCallbacks *airsoftSmartMineBleServerCallbacks = nullptr;
AirsoftSmartMineBLEServerSecurityCallbacks *airsoftSmartMineBleServerSecurityCallbacks = nullptr;
AirsoftSmartMineSettings *airsoftSmartMineSettings = nullptr;

BLEServer *bleServer = nullptr;
BLEAdvertising *bleAdvertising = nullptr;
BLESecurity *bleSecurity = nullptr;
bool isClientConnected = false;

BLEService *batteryBleService = nullptr;
BLECharacteristic *batteryBleCharacteristic = nullptr;
uint8_t batteryLevel = 0;

BLEService *customBleService = nullptr;
BLECharacteristic *customBleCharacteristics[AirsoftSmartMineBLECharacteristics::AllLength];

void setup()
{
  Serial.begin(115200);

  ESP_LOGI(_EspLogTag, "setup");

  airsoftSmartMineBleServerCallbacks = new AirsoftSmartMineBLEServerCallbacks();
  airsoftSmartMineBleServerSecurityCallbacks = new AirsoftSmartMineBLEServerSecurityCallbacks();
  airsoftSmartMineSettings = new AirsoftSmartMineSettings();

  AirsoftSmartMineBLECharacteristicCallbacks::Initialize(airsoftSmartMineSettings);

  ESP_LOGI(_EspLogTag, "Initializing BLE device");
  BLEDevice::init("Airsoft smart mine");

  std::string bleAddress = BLEDevice::getAddress().toString();
  ESP_LOGD(_EspLogTag, "bleAddress = %s", bleAddress.c_str());

  bleAddress.erase(std::remove(bleAddress.begin(), bleAddress.end(), ':'), bleAddress.end());
  ESP_LOGD(_EspLogTag, "bleAddress = %s", bleAddress.c_str());

  std::string bleDeviceName = "ASM " + bleAddress;
  ESP_LOGD(_EspLogTag, "bleDeviceName = %s", bleDeviceName.c_str());

  BLEDevice::deinit();
  BLEDevice::init(bleDeviceName);

  BLEDevice::setPower(ESP_PWR_LVL_N12);
  BLEDevice::setEncryptionLevel(ESP_BLE_SEC_ENCRYPT);
  BLEDevice::setSecurityCallbacks(airsoftSmartMineBleServerSecurityCallbacks);

  ESP_LOGI(_EspLogTag, "Creating BLE server");
  bleServer = BLEDevice::createServer();
  bleServer->setCallbacks(airsoftSmartMineBleServerCallbacks);

  ESP_LOGI(_EspLogTag, "Creating battery BLE service");
  batteryBleService = bleServer->createService("0000180f-0000-1000-8000-00805f9b34fb");

  ESP_LOGI(_EspLogTag, "Creating battery BLE characteristic");
  batteryBleCharacteristic = batteryBleService->createCharacteristic(
      "00002a19-0000-1000-8000-00805f9b34fb",
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE);
  batteryBleCharacteristic->setValue(&batteryLevel, 1);
  batteryBleCharacteristic->addDescriptor(new BLE2902());

  ESP_LOGI(_EspLogTag, "Creating custom BLE service");
  customBleService = bleServer->createService(AirsoftSmartMineBLECharacteristics::ServiceUUID, 30);

  ESP_LOGI(_EspLogTag, "Creating custom BLE characteristics");
  for (uint8_t i = 0; i < AirsoftSmartMineBLECharacteristics::AllLength; i++)
  {
    ESP_LOGI(
        _EspLogTag,
        "Creating %s (%s) BLE characteristic",
        AirsoftSmartMineBLECharacteristicNames::All[i].c_str(),
        AirsoftSmartMineBLECharacteristics::All[i].c_str());

    customBleCharacteristics[i] = customBleService->createCharacteristic(
        AirsoftSmartMineBLECharacteristics::All[i],
        AirsoftSmartMineBLECharacteristicProperties::All[i]);

    customBleCharacteristics[i]->setCallbacks(AirsoftSmartMineBLECharacteristicCallbacks::All[i]);
    customBleCharacteristics[i]->addDescriptor(new BLE2902());
  }

  ESP_LOGI(_EspLogTag, "Starting battery BLE service");
  batteryBleService->start();

  ESP_LOGI(_EspLogTag, "Starting custom BLE service");
  customBleService->start();

  ESP_LOGI(_EspLogTag, "Starting BLE advertising");
  bleAdvertising = bleServer->getAdvertising();
  bleAdvertising->start();

  ESP_LOGI(_EspLogTag, "Creating BLE security");
  bleSecurity = new BLESecurity();

  uint32_t staticPassKey = AirsoftSmartMineBLEServerSecurityCallbacks::Pin;
  esp_ble_gap_set_security_param(ESP_BLE_SM_SET_STATIC_PASSKEY, &staticPassKey, sizeof(uint32_t));

  bleSecurity->setAuthenticationMode(ESP_LE_AUTH_REQ_SC_MITM_BOND);
  bleSecurity->setCapability(ESP_IO_CAP_OUT);
  bleSecurity->setKeySize(16);

  uint8_t authOption = ESP_BLE_ONLY_ACCEPT_SPECIFIED_AUTH_DISABLE;
  esp_ble_gap_set_security_param(ESP_BLE_SM_ONLY_ACCEPT_SPECIFIED_SEC_AUTH, &authOption, sizeof(uint32_t));

  uint8_t encryptionKey = ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK;
  bleSecurity->setInitEncryptionKey(encryptionKey);
  esp_ble_gap_set_security_param(ESP_BLE_SM_SET_RSP_KEY, &encryptionKey, sizeof(uint32_t));
}

void loop()
{
  ESP_LOGI(_EspLogTag, "loop");

  isClientConnected = airsoftSmartMineBleServerCallbacks->isClientConnected();

  bool isExploded = airsoftSmartMineSettings->GetIsExploded();
  if (!isExploded)
  {
    checkForExplosionInitiationViaSensor();
    checkForExplosionInitiationViaBle();
  }

  updateBatteryLevel();
  notifyRuntimeInSecCharacteristics();

  vTaskDelay(1000 / portTICK_PERIOD_MS);
}

void updateBatteryLevel()
{
  ESP_LOGI(_EspLogTag, "updateBatteryLevel");

  // TODO: Get battery level from real source
  const uint8_t currentBatteryLevel = 0;
  if (currentBatteryLevel != batteryLevel)
  {
    batteryLevel = currentBatteryLevel;
    batteryBleCharacteristic->setValue(&batteryLevel, 1);

    if (isClientConnected)
    {
      batteryBleCharacteristic->notify();
      batteryBleCharacteristic->indicate();
    }
  }
}

void checkForExplosionInitiationViaSensor()
{
  ESP_LOGI(_EspLogTag, "checkForExplosionInitiationViaSensor");

  // TODO: Get sensor value from real source
  const uint8_t sensorValue = 0;
  if (sensorValue > 0)
  {
    initiateExplosion();
  }
}

void checkForExplosionInitiationViaBle()
{
  ESP_LOGI(_EspLogTag, "checkForExplosionInitiationViaBle");

  const bool isForceExplodeViaBleInitiated = airsoftSmartMineSettings->GetIsForceExplodeViaBleInitiated();
  if (isForceExplodeViaBleInitiated)
  {
    initiateExplosion();
  }
}

void initiateExplosion()
{
  ESP_LOGI(_EspLogTag, "initiateExplosion");

  const uint32_t explodeDurationInMs = airsoftSmartMineSettings->GetExplodeDurationInMs();

  // TODO: Initiate explosion
  airsoftSmartMineSettings->SetIsExploded(true);

  customBleCharacteristics[AirsoftSmartMineBLECharacteristicIndexes::IsExploded]->notify();
  customBleCharacteristics[AirsoftSmartMineBLECharacteristicIndexes::IsExploded]->indicate();
}

void notifyRuntimeInSecCharacteristics()
{
  ESP_LOGI(_EspLogTag, "notifyRuntimeInSecCharacteristics");

  if (isClientConnected)
  {
    customBleCharacteristics[AirsoftSmartMineBLECharacteristicIndexes::RuntimeInSec]->notify();
    customBleCharacteristics[AirsoftSmartMineBLECharacteristicIndexes::RuntimeInSec]->indicate();
  }
}
