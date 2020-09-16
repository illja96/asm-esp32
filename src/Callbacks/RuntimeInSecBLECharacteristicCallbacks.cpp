#include "RuntimeInSecBLECharacteristicCallbacks.h"

void RuntimeInSecBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  unsigned long runtimeInMs = millis();
  uint32_t runtimeInSec = runtimeInMs / 1000;

  pCharacteristic->setValue(runtimeInSec);
}

void RuntimeInSecBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");
}

void RuntimeInSecBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");

  unsigned long runtimeInMs = millis();
  uint32_t runtimeInSec = runtimeInMs / 1000;

  pCharacteristic->setValue(runtimeInSec);
}

void RuntimeInSecBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");
}
