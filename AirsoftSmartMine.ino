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

#define ESP_LOG_TAG "Main"

AirsoftSmartMineBLEServerCallbacks *airsoftSmartMineBLEServerCallbacks = nullptr;
AirsoftSmartMineSettings *airsoftSmartMineSettings = nullptr;

BLEServer *bleServer = nullptr;

BLEService *batteryBleService = nullptr;
BLECharacteristic *batteryBleCharacteristic = nullptr;
int batteryLevel = 100;

BLEService *customBleService = nullptr;
BLECharacteristic *customBleCharacteristics[AirsoftSmartMineBLECharacteristics::AllLength];

void setup()
{
  Serial.begin(115200);

  ESP_LOGI(ESP_LOG_TAG, "setup");

  airsoftSmartMineBLEServerCallbacks = new AirsoftSmartMineBLEServerCallbacks();
  airsoftSmartMineSettings = new AirsoftSmartMineSettings();

  AirsoftSmartMineBLECharacteristicCallbacks::Initialize(airsoftSmartMineSettings);

  ESP_LOGI(ESP_LOG_TAG, "Initializing BLE device");
  BLEDevice::setPower(ESP_PWR_LVL_N12);
  BLEDevice::init("AirsoftSmartMine");

  ESP_LOGI(ESP_LOG_TAG, "Creating BLE server");
  bleServer = BLEDevice::createServer();
  bleServer->setCallbacks(airsoftSmartMineBLEServerCallbacks);

  ESP_LOGI(ESP_LOG_TAG, "Creating battery BLE service");
  batteryBleService = bleServer->createService(BLEUUID((uint16_t)0x180F));

  ESP_LOGI(ESP_LOG_TAG, "Creating battery BLE characteristic");
  batteryBleCharacteristic = batteryBleService->createCharacteristic(
      BLEUUID((uint16_t)0x2A19),
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE);
  batteryBleCharacteristic->setValue(batteryLevel);

  ESP_LOGI(ESP_LOG_TAG, "Creating custom BLE service");
  customBleService = bleServer->createService(AirsoftSmartMineBLECharacteristics::ServiceUUID);

  ESP_LOGI(ESP_LOG_TAG, "Creating custom BLE characteristics");
  for (int i = 0; i < AirsoftSmartMineBLECharacteristics::AllLength; i++)
  {
    ESP_LOGI(
        ESP_LOG_TAG,
        "Creating custom BLE characteristic with %s (%s) with %d as default value",
        AirsoftSmartMineBLECharacteristicNames::All[i],
        AirsoftSmartMineBLECharacteristics::All[i],
        AirsoftSmartMineBLECharacteristicDefaultValues::All[i]);

    customBleCharacteristics[i] = customBleService->createCharacteristic(
        AirsoftSmartMineBLECharacteristics::All[i],
        AirsoftSmartMineBLECharacteristicProperties::All[i]);

    customBleCharacteristics[i]->setCallbacks(AirsoftSmartMineBLECharacteristicCallbacks::All[i]);
  }

  ESP_LOGI(ESP_LOG_TAG, "Starting battery BLE service");
  batteryBleService->start();

  ESP_LOGI(ESP_LOG_TAG, "Starting custom BLE service");
  customBleService->start();

  ESP_LOGI(ESP_LOG_TAG, "Starting BLE server");
  bleServer->getAdvertising()->start();
}

void loop()
{
  delay(1000);
  // customBleCharacteristics[AirsoftSmartMineBLECharacteristicIndexes::RuntimeInSec]->notify();
}
