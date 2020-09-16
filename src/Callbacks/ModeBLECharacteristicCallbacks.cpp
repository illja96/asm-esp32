#include "ModeBLECharacteristicCallbacks.h"

void ModeBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onRead");
}

void ModeBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onWrite");
}

void ModeBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(EspLogTag, "onNotify");
}

void ModeBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(EspLogTag, "onStatus");
}
