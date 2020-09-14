#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLE2902.h>
#include <stdio.h>

#include "src/AirsoftSmartMineMode.h"
#include "src/AirsoftSmartMineBleConstants.h"
#include "src/AirsoftSmartMineBLEServerCallbacks.h"

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

  bleServer = BLEDevice::createServer();
  bleServer->setCallbacks(new AirsoftSmartMineBLEServerCallbacks());

  bleService = bleServer->createService(AirsoftSmartMineBLECharacteristics::ServiceUUID);

  for (int i = 0; i < sizeof(bleCharacteristics); i++)
  {
    bleCharacteristics[i] = bleService->createCharacteristic(
        AirsoftSmartMineBLEConstants::Services.Characteristics.All[i],
        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE);
    bleCharacteristics[i]->setValue((int &)AirsoftSmartMineBLECharacteristics::Properties.All[i]);

    bleDescriptors[i] = new BLE2902();
    bleDescriptors[i]->setAccessPermissions(ESP_GATT_PERM_READ_ENCRYPTED | ESP_GATT_PERM_WRITE_ENCRYPTED);
    bleDescriptors[i]->setValue(AirsoftSmartMineBLEConstants::Services.Characteristics.DescriptorValues.All[i]);

    bleCharacteristics[i]->addDescriptor(bleDescriptors[i]);

    ESP_LOGI(
        ESP_LOG_TAG,
        "Creating characteristic with %s UUID with %d as default value",
        AirsoftSmartMineBLEConstants::Services.Characteristics.All[i],
        AirsoftSmartMineBLEConstants::Services.Characteristics.Properties.All[i]);
  }

  bleService->start();
  bleServer->getAdvertising()->start();
  ESP_LOGI(ESP_LOG_TAG, "Starting BLE");
}

void loop()
{
  delay(1000);

  int values[sizeof(bleCharacteristics)];
  for (int i = 0; i < sizeof(bleCharacteristics); i++)
  {
    std::string valueRaw = bleCharacteristics[i]->getValue();
    values[i] = atoi(valueRaw.c_str());

    ESP_LOGD(ESP_LOG_TAG, "%s = %d", AirsoftSmartMineBLEConstants::Services.Characteristics.DescriptorValues.All[i], values[i]);
  }
}
