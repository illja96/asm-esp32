#include "IsExplodedBLECharacteristicCallbacks.h"

void IsExplodedBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onRead");
}

void IsExplodedBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onWrite");
}

void IsExplodedBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onNotify");
}

void IsExplodedBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(EspLogTag, "onStatus");
}
