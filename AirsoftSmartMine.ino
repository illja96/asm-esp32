#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLE2902.h>
#include <stdio.h>

#define ESP_LOG_TAG "ASM"

#define BLE_SERVICE_UUID "00000001-0001-0001-0001-000000000000"

#define BLE_CHARACTERISTICS_MODE_UUID "00000001-0001-0001-0001-000000000001"
#define BLE_CHARACTERISTICS_IS_EXPLODED_UUID "00000001-0001-0001-0001-000000000002"
#define BLE_CHARACTERISTICS_BEEP_BEFORE_EXPLODE_DURATION_IN_MS_UUID "00000001-0001-0001-0001-000000000003"
#define BLE_CHARACTERISTICS_EXPLODE_DELAY_IN_MS_UUID "00000001-0001-0001-0001-000000000004"
#define BLE_CHARACTERISTICS_FORCE_EXPLODE_UUID "00000001-0001-0001-0001-000000000005"
#define BLE_CHARACTERISTICS_RUNTIME_IN_SEC_UUID "00000001-0001-0001-0001-000000000006"

enum Mode
{
  Any = 0,
  SensorOnly = 1,
  BleOnly = 2
};

Mode modeDefaultValue = Mode::Any;
int isExplodedDefaultValue = 0;
int isExplodedExplodedValue = 0;
int beepBeforeExplodeDurationInMsDefaultValue = 1000;
int explodeDelayInMsDefaultValue = 0;
int forceExplodeDefaultValue = 0;
int runtimeInSecDefaultValue = 0;

class MineBleServerCallbacks : public BLEServerCallbacks
{
public:
  MineBleServerCallbacks()
  {
    pinMode(2, OUTPUT);
  }

  void onConnect(BLEServer *bleServer)
  {
    digitalWrite(2, HIGH);
  };

  void onDisconnect(BLEServer *bleServer)
  {
    digitalWrite(2, LOW);
  }
};

BLEServer *bleServer;
BLEService *bleService;
BLECharacteristic *bleCharacteristics[6];
BLEDescriptor *bleDescriptors[6];

void setup()
{
  Serial.begin(115200);

  BLEDevice::setPower(ESP_PWR_LVL_N12);
  BLEDevice::init("AirsoftSmartMine");

  bleServer = BLEDevice::createServer();
  bleServer->setCallbacks(new MineBleServerCallbacks());

  bleService = bleServer->createService(BLE_SERVICE_UUID);

  bleCharacteristics[0] = bleService->createCharacteristic(
      BLE_CHARACTERISTICS_MODE_UUID,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE);
  bleCharacteristics[0]->setValue((int &)modeDefaultValue);
  bleDescriptors[0] = new BLE2902();
  bleDescriptors[0]->setValue("Mode");
  bleCharacteristics[0]->addDescriptor(bleDescriptors[0]);
  ESP_LOGI(ESP_LOG_TAG, "Creating characteristic with %s UUID with %d as default value", BLE_CHARACTERISTICS_MODE_UUID, modeDefaultValue);

  bleCharacteristics[1] = bleService->createCharacteristic(
      BLE_CHARACTERISTICS_IS_EXPLODED_UUID,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE);
  bleCharacteristics[0]->setValue(isExplodedDefaultValue);
  bleDescriptors[1] = new BLE2902();
  bleDescriptors[1]->setValue("IsExploaded");
  bleCharacteristics[1]->addDescriptor(bleDescriptors[1]);
  ESP_LOGI(ESP_LOG_TAG, "Creating characteristic with %s UUID with %d as default value", BLE_CHARACTERISTICS_IS_EXPLODED_UUID, isExplodedDefaultValue);

  bleCharacteristics[2] = bleService->createCharacteristic(
      BLE_CHARACTERISTICS_BEEP_BEFORE_EXPLODE_DURATION_IN_MS_UUID,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE);
  bleCharacteristics[2]->setValue(beepBeforeExplodeDurationInMsDefaultValue);
  bleDescriptors[2] = new BLE2902();
  bleDescriptors[2]->setValue("BeepBeforeExplodeDurationInMs");
  bleCharacteristics[2]->addDescriptor(bleDescriptors[2]);
  ESP_LOGI(ESP_LOG_TAG, "Creating characteristic with %s UUID with %d as default value", BLE_CHARACTERISTICS_BEEP_BEFORE_EXPLODE_DURATION_IN_MS_UUID, beepBeforeExplodeDurationInMsDefaultValue);

  bleCharacteristics[3] = bleService->createCharacteristic(
      BLE_CHARACTERISTICS_EXPLODE_DELAY_IN_MS_UUID,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE);
  bleCharacteristics[3]->setValue(explodeDelayInMsDefaultValue);
  bleDescriptors[3] = new BLE2902();
  bleDescriptors[3]->setValue("ExplodeDelayInMs");
  bleCharacteristics[3]->addDescriptor(bleDescriptors[3]);
  ESP_LOGI(ESP_LOG_TAG, "Creating characteristic with %s UUID with %d as default value", BLE_CHARACTERISTICS_EXPLODE_DELAY_IN_MS_UUID, explodeDelayInMsDefaultValue);

  bleCharacteristics[4] = bleService->createCharacteristic(
      BLE_CHARACTERISTICS_FORCE_EXPLODE_UUID,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE);
  bleCharacteristics[4]->setValue(forceExplodeDefaultValue);
  bleDescriptors[4] = new BLE2902();
  bleDescriptors[4]->setValue("ForceExplode");
  bleCharacteristics[4]->addDescriptor(bleDescriptors[4]);
  ESP_LOGI(ESP_LOG_TAG, "Creating characteristic with %s UUID with %d as default value", BLE_CHARACTERISTICS_FORCE_EXPLODE_UUID, forceExplodeDefaultValue);

  bleCharacteristics[5] = bleService->createCharacteristic(
      BLE_CHARACTERISTICS_RUNTIME_IN_SEC_UUID,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE);
  bleCharacteristics[5]->setValue(runtimeInSecDefaultValue);
  bleDescriptors[5] = new BLE2902();
  bleDescriptors[5]->setValue("RuntimeInSec");
  bleCharacteristics[5]->addDescriptor(bleDescriptors[5]);
  ESP_LOGI(ESP_LOG_TAG, "Creating characteristic with %s UUID with %d as default value", BLE_CHARACTERISTICS_RUNTIME_IN_SEC_UUID, runtimeInSecDefaultValue);

  bleService->start();
  bleServer->getAdvertising()->start();
  ESP_LOGI(ESP_LOG_TAG, "Starting BLE");
}

void loop()
{
  delay(1000);

  std::string modeRaw = bleCharacteristics[0]->getValue();
  Mode mode = (Mode)atoi(modeRaw.c_str());
  if (mode < 0 || mode > 2)
  {
    ESP_LOGW(ESP_LOG_TAG, "Invalid value in mode characteristics. Resetting to default");
    bleCharacteristics[0]->setValue((int &)modeDefaultValue);
  }
  ESP_LOGD(ESP_LOG_TAG, "mode = %d", mode);

  std::string isExplodedRaw = bleCharacteristics[1]->getValue();
  int isExploded = atoi(isExplodedRaw.c_str());
  if (isExploded < 0 || isExploded > 1)
  {
    ESP_LOGW(ESP_LOG_TAG, "Invalid value in is exploded characteristics. Resetting to default");
    bleCharacteristics[1]->setValue(isExplodedDefaultValue);
  }
  ESP_LOGD(ESP_LOG_TAG, "isExploded = %d", isExploded);

  std::string beepBeforeExplodeDurationInMsRaw = bleCharacteristics[2]->getValue();
  int beepBeforeExplodeDurationInMs = atoi(beepBeforeExplodeDurationInMsRaw.c_str());
  if (beepBeforeExplodeDurationInMs < 0 || beepBeforeExplodeDurationInMs > 60000)
  {
    ESP_LOGW(ESP_LOG_TAG, "Invalid value in beep before explode duration in ms characteristics. Resetting to default");
    bleCharacteristics[1]->setValue(beepBeforeExplodeDurationInMsDefaultValue);
  }
  ESP_LOGD(ESP_LOG_TAG, "beepBeforeExplodeDurationInMs = %d", beepBeforeExplodeDurationInMs);

  std::string explodeDelayInMsRaw = bleCharacteristics[3]->getValue();
  int explodeDelayInMs = atoi(explodeDelayInMsRaw.c_str());
  if (explodeDelayInMs < 0 || explodeDelayInMs > 60000)
  {
    ESP_LOGW(ESP_LOG_TAG, "Invalid value in explode delay in ms characteristics. Resetting to default");
    bleCharacteristics[3]->setValue(explodeDelayInMsDefaultValue);
  }
  ESP_LOGD(ESP_LOG_TAG, "explodeDelayInMs = %d", explodeDelayInMs);

  std::string forceExplodeRaw = bleCharacteristics[4]->getValue();
  int forceExplode = atoi(forceExplodeRaw.c_str());
  if (forceExplode < 0 || forceExplode > 1)
  {
    ESP_LOGW(ESP_LOG_TAG, "Invalid value in force explode characteristics. Resetting to default");
    bleCharacteristics[4]->setValue(forceExplodeDefaultValue);
  }
  ESP_LOGD(ESP_LOG_TAG, "forceExplode = %d", forceExplode);

  int runtimeInMs = millis();
  int runtimeInSec = runtimeInMs / 1000;
  bleCharacteristics[5]->setValue(runtimeInSec);
  ESP_LOGD(ESP_LOG_TAG, "runtimeInSec = %d", runtimeInSec);

  if (isExploded == 1)
  {
    ESP_LOGI(ESP_LOG_TAG, "Mine have already exploded");
    return;
  }

  switch (mode)
  {
  case Mode::Any | Mode::SensorOnly:
    ESP_LOGI(ESP_LOG_TAG, "Checking sensor to initiate explosion");
    break;

  case Mode::Any | Mode::BleOnly:
    ESP_LOGI(ESP_LOG_TAG, "Checking BLE to initiate explosion");

    if (forceExplode == 1)
    {
      ESP_LOGI(ESP_LOG_TAG, "Detected BLE force explosion");

      bleCharacteristics[1]->setValue(isExplodedExplodedValue);
      bleCharacteristics[1]->notify();
    }
    break;

  default:
    ESP_LOGE(ESP_LOG_TAG, "Unknown mode detected");
    break;
  }
}
