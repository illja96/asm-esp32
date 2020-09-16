#include "RuntimeInSecBLECharacteristicCallbacks.h"

void RuntimeInSecBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onRead");

  unsigned long runtimeInMs = millis();
  uint32_t runtimeInSec = runtimeInMs / 1000;

  pCharacteristic->setValue(runtimeInSec);
}

void RuntimeInSecBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onWrite");
}

void RuntimeInSecBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onNotify");
}

void RuntimeInSecBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(EspLogTag, "onStatus");
}
