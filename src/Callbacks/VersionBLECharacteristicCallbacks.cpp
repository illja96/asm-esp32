#include "VersionBLECharacteristicCallbacks.h"

const std::string VersionBLECharacteristicCallbacks::_EspLogTag = "VersionBLECharacteristicCallbacks";

VersionBLECharacteristicCallbacks::VersionBLECharacteristicCallbacks()
{
  ESP_LOGI(_EspLogTag, "VersionBLECharacteristicCallbacks");
}

void VersionBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  uint8_t version = AirsoftSmartMineBLECharacteristicDefaultValues::Version;

  pCharacteristic->setValue(&version, 1);
}

void VersionBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");
}

void VersionBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");
}

void VersionBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");
}
