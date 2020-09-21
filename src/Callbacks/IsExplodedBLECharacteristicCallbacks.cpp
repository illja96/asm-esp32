#include "IsExplodedBLECharacteristicCallbacks.h"

const std::string IsExplodedBLECharacteristicCallbacks::_EspLogTag = "IsExplodedBLECharacteristicCallbacks";

IsExplodedBLECharacteristicCallbacks::IsExplodedBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  ESP_LOGI(_EspLogTag, "IsExplodedBLECharacteristicCallbacks");

  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void IsExplodedBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  bool isExploded = _airsoftSmartMineSettings->GetIsExploded();
  ESP_LOGD(_EspLogTag, "isExploded = %d", isExploded);

  char isExplodedString[2];
  sprintf(isExplodedString, "%d", isExploded);
  ESP_LOGD(_EspLogTag, "isExplodedString = %s", isExplodedString);

  pCharacteristic->setValue(isExplodedString);
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

  ESP_LOGD(_EspLogTag, "s = %d", s);
  ESP_LOGD(_EspLogTag, "code = %lu", code);
}
