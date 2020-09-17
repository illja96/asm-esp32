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
BLEService *bleService = nullptr;
BLECharacteristic *bleCharacteristics[AirsoftSmartMineBLECharacteristics::AllLength];
BLEDescriptor *bleDescriptors[AirsoftSmartMineBLECharacteristics::AllLength];

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

  ESP_LOGI(ESP_LOG_TAG, "Creating BLE service");
  bleService = bleServer->createService(AirsoftSmartMineBLECharacteristics::ServiceUUID);

  ESP_LOGI(ESP_LOG_TAG, "Creating BLE characteristics");
  for (int i = 0; i < AirsoftSmartMineBLECharacteristics::AllLength; i++)
  {
    ESP_LOGI(
        ESP_LOG_TAG,
        "Creating characteristic with %s (%s) with %d as default value",
        AirsoftSmartMineBLECharacteristicNames::All[i],
        AirsoftSmartMineBLECharacteristics::All[i],
        AirsoftSmartMineBLECharacteristicDefaultValues::All[i]);

    bleCharacteristics[i] = bleService->createCharacteristic(
        AirsoftSmartMineBLECharacteristics::All[i],
        AirsoftSmartMineBLECharacteristicProperties::All[i]);

    bleCharacteristics[i]->setCallbacks(AirsoftSmartMineBLECharacteristicCallbacks::All[i]);
  }

  ESP_LOGI(ESP_LOG_TAG, "Starting BLE server");
  bleService->start();
  bleServer->getAdvertising()->start();
}

void loop()
{
  delay(1000);
  bleCharacteristics[AirsoftSmartMineBLECharacteristicIndexes::RuntimeInSec]->notify();
}
