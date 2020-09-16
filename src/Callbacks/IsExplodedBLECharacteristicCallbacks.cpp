#include "IsExplodedBLECharacteristicCallbacks.h"

IsExplodedBLECharacteristicCallbacks::IsExplodedBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void IsExplodedBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  bool isExploded = _airsoftSmartMineSettings->GetIsExploded();
  ESP_LOGD(_EspLogTag, "isExploded = %d", isExploded);

  pCharacteristic->setValue(isExploded);
}

void IsExplodedBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");
}

void IsExplodedBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");
}

void IsExplodedBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");
}
