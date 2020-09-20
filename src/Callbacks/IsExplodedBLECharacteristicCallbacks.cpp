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

  uint8_t convertedIsExploded = (uint8_t)isExploded;
  ESP_LOGD(_EspLogTag, "convertedIsExploded = %d", convertedIsExploded);

  pCharacteristic->setValue(&convertedIsExploded, 1);
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
