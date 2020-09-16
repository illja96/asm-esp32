#include "BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks.h"

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic) {
  ESP_LOGI(EspLogTag, "onRead");
}

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic) {
  ESP_LOGI(EspLogTag, "onWrite");
}

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic) {
  ESP_LOGI(EspLogTag, "onNotify");
}

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code) {
  ESP_LOGI(EspLogTag, "onStatus");
}
