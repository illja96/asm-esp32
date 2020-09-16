#include "ExplodeDurationInMsBLECharacteristicCallbacks.h"

ExplodeDurationInMsBLECharacteristicCallbacks::ExplodeDurationInMsBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  int explodeDurationInMs = _airsoftSmartMineSettings->GetExplodeDurationInMs();
  pCharacteristic->setValue(explodeDurationInMs);
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");

  std::string explodeDurationInMsRaw = pCharacteristic->getValue();
  unsigned long explodeDurationInMs = atol(explodeDurationInMsRaw.c_str());

  if (explodeDurationInMs < 1 || explodeDurationInMs > 60000)
  {
    ESP_LOGW(_EspLogTag, "ExplodeDurationInMs is out of range");
    return;
  }

  _airsoftSmartMineSettings->SetBeepBeforeExplodeDurationInMs(explodeDurationInMs);
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");

  int explodeDurationInMs = _airsoftSmartMineSettings->GetExplodeDurationInMs();
  pCharacteristic->setValue(explodeDurationInMs);
}

void ExplodeDurationInMsBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");
}
