#include "ExplodeDurationInMsBLECharacteristicCallbacks.h"

ExplodeDurationInMsBLECharacteristicCallbacks::ExplodeDurationInMsBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  ESP_LOGI(_EspLogTag, "ExplodeDurationInMsBLECharacteristicCallbacks");

  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  int explodeDurationInMs = _airsoftSmartMineSettings->GetExplodeDurationInMs();
  ESP_LOGD(_EspLogTag, "explodeDurationInMs = %d", explodeDurationInMs);

  pCharacteristic->setValue(explodeDurationInMs);
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");

  std::string explodeDurationInMsRaw = pCharacteristic->getValue();
  ESP_LOGD(_EspLogTag, "explodeDurationInMsRaw = %s", explodeDurationInMsRaw);

  unsigned long explodeDurationInMs = atol(explodeDurationInMsRaw.c_str());
  ESP_LOGD(_EspLogTag, "explodeDurationInMs = %d", explodeDurationInMs);

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

  int explodeDurationInMs = _airsoftSmartMineSettings->GetExplodeDurationInMs();
  ESP_LOGD(_EspLogTag, "explodeDurationInMs = %d", explodeDurationInMs);

  pCharacteristic->setValue(explodeDurationInMs);
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");
}
