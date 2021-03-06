#include "ExplodeDurationInMsBLECharacteristicCallbacks.h"

const std::string ExplodeDurationInMsBLECharacteristicCallbacks::_EspLogTag = "ExplodeDurationInMsBLECharacteristicCallbacks";

ExplodeDurationInMsBLECharacteristicCallbacks::ExplodeDurationInMsBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  ESP_LOGI(_EspLogTag, "ExplodeDurationInMsBLECharacteristicCallbacks");

  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  uint32_t explodeDurationInMs = _airsoftSmartMineSettings->GetExplodeDurationInMs();
  ESP_LOGD(_EspLogTag, "explodeDurationInMs = %lu", explodeDurationInMs);

  char explodeDurationInMsString[10];
  sprintf(explodeDurationInMsString, "%lu", explodeDurationInMs);
  ESP_LOGD(_EspLogTag, "explodeDurationInMsString = %s", explodeDurationInMsString);

  pCharacteristic->setValue(explodeDurationInMsString);
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");

  std::string explodeDurationInMsRaw = pCharacteristic->getValue();
  ESP_LOGD(_EspLogTag, "explodeDurationInMsRaw = %s", explodeDurationInMsRaw.c_str());

  uint32_t explodeDurationInMs = atoll(explodeDurationInMsRaw.c_str());
  ESP_LOGD(_EspLogTag, "explodeDurationInMs = %lu", explodeDurationInMs);

  if (explodeDurationInMs < 1 || explodeDurationInMs > 60000)
  {
    ESP_LOGW(_EspLogTag, "ExplodeDurationInMs is out of range");
    return;
  }

  _airsoftSmartMineSettings->SetExplodeDurationInMs(explodeDurationInMs);
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");

  uint32_t explodeDurationInMs = _airsoftSmartMineSettings->GetExplodeDurationInMs();
  ESP_LOGD(_EspLogTag, "explodeDurationInMs = %lu", explodeDurationInMs);

  pCharacteristic->setValue(explodeDurationInMs);
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");

  ESP_LOGD(_EspLogTag, "s = %d", s);
  ESP_LOGD(_EspLogTag, "code = %lu", code);
}
