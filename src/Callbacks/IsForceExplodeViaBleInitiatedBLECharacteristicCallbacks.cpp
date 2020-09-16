#include "IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks.h"

void IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onRead");
}

void IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onWrite");
}

void IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onNotify");
}

void IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(EspLogTag, "onStatus");
}
