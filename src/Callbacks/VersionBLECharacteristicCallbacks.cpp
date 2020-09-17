#include "VersionBLECharacteristicCallbacks.h"

VersionBLECharacteristicCallbacks::VersionBLECharacteristicCallbacks()
{
  ESP_LOGI(_EspLogTag, "VersionBLECharacteristicCallbacks");
}

void VersionBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  int version = AirsoftSmartMineBLECharacteristicDefaultValues::Version;
  pCharacteristic->setValue(version);
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
