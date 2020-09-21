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
  ESP_LOGD(_EspLogTag, "runtimeInMs = %lu", runtimeInMs);

  uint32_t runtimeInSec = (runtimeInMs / 1000) - (runtimeInMs / 1000) % 10;
  ESP_LOGD(_EspLogTag, "runtimeInSec = %lu", runtimeInSec);

  char runtimeInSecString[11];
  sprintf(runtimeInSecString, "%d", runtimeInSec);
  ESP_LOGD(_EspLogTag, "runtimeInSecString = %s", runtimeInSecString);

  pCharacteristic->setValue(runtimeInSecString);
}

void RuntimeInSecBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");
}

void RuntimeInSecBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");
}

void RuntimeInSecBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");

  ESP_LOGD(_EspLogTag, "s = %d", s);
  ESP_LOGD(_EspLogTag, "code = %lu", code);
}
