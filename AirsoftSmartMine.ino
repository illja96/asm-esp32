#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLE2902.h>
#include <stdio.h>

#include "src/Constants/AirsoftSmartMineBLECharacteristics.h"
#include "src/Constants/AirsoftSmartMineBLECharacteristicNames.h"
#include "src/Constants/AirsoftSmartMineBLECharacteristicDefaultValues.h"
#include "src/Constants/AirsoftSmartMineBLECharacteristicProperties.h"
#include "src/Constants/AirsoftSmartMineBLECharacteristicCallbacks.h"
#include "src/Callbacks/AirsoftSmartMineBLEServerCallbacks.h"

#define ESP_LOG_TAG "ASM"

BLEServer *bleServer;
BLEService *bleService;
BLECharacteristic *bleCharacteristics[sizeof(AirsoftSmartMineBLECharacteristics::All)];
BLEDescriptor *bleDescriptors[sizeof(AirsoftSmartMineBLECharacteristics::All)];

void setup()
{
  Serial.begin(115200);

  BLEDevice::setPower(ESP_PWR_LVL_N12);
  BLEDevice::init("AirsoftSmartMine");

  ESP_LOGI(ESP_LOG_TAG, "Creating BLE server");
  bleServer = BLEDevice::createServer();
  bleServer->setCallbacks(new AirsoftSmartMineBLEServerCallbacks());

  ESP_LOGI(ESP_LOG_TAG, "Creating BLE service");
  bleService = bleServer->createService(BLEUUID(AirsoftSmartMineBLECharacteristics::ServiceUUID));

  ESP_LOGI(ESP_LOG_TAG, "Creating BLE characteristics");
  for (int i = 0; i < sizeof(AirsoftSmartMineBLECharacteristics::All); i++)
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

    bleCharacteristics[i]->setCallbacks(&AirsoftSmartMineBLECharacteristicCallbacks::All[i]);
  }

  ESP_LOGI(ESP_LOG_TAG, "Starting BLE");
  bleService->start();
  bleServer->getAdvertising()->start();
}

void loop() {}
