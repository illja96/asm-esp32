#include "RuntimeInSecBLECharacteristicCallbacks.h"

const std::string RuntimeInSecBLECharacteristicCallbacks::_EspLogTag = "RuntimeInSecBLECharacteristicCallbacks";

RuntimeInSecBLECharacteristicCallbacks::RuntimeInSecBLECharacteristicCallbacks()
{
  ESP_LOGI(_EspLogTag, "RuntimeInSecBLECharacteristicCallbacks");
}

void RuntimeInSecBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  uint32_t runtimeInMs = millis();
  ESP_LOGD(_EspLogTag, "runtimeInMs = %d", runtimeInMs);

  uint32_t runtimeInSec = runtimeInMs / 1000;
  ESP_LOGD(_EspLogTag, "runtimeInSec = %d", runtimeInSec);

  pCharacteristic->setValue(runtimeInSec);
}

void RuntimeInSecBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");
}

void RuntimeInSecBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");

  uint32_t runtimeInMs = millis();
  ESP_LOGD(_EspLogTag, "runtimeInMs = %d", runtimeInMs);

  uint32_t runtimeInSec = runtimeInMs / 1000;
  ESP_LOGD(_EspLogTag, "runtimeInSec = %d", runtimeInSec);

  pCharacteristic->setValue(runtimeInSec);
}

void RuntimeInSecBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");
}
