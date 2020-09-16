#include "ExplodeDurationInMsBLECharacteristicCallbacks.h"

void ExplodeDurationInMsBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onRead");
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onWrite");
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onNotify");
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(EspLogTag, "onStatus");
}
