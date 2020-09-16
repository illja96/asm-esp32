#include "BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks.h"

BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  int beepBeforeExplodeDurationInMs = _airsoftSmartMineSettings->GetBeepBeforeExplodeDurationInMs();
  pCharacteristic->setValue(beepBeforeExplodeDurationInMs);
}

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");

  std::string beepBeforeExplodeDurationInMsRaw = pCharacteristic->getValue();
  unsigned long beepBeforeExplodeDurationInMs = atol(beepBeforeExplodeDurationInMsRaw.c_str());

  if (beepBeforeExplodeDurationInMs < 0 || beepBeforeExplodeDurationInMs > 60000)
  {
    ESP_LOGW(_EspLogTag, "BeepBeforeExplodeDurationInMs is out of range");
    return;
  }

  _airsoftSmartMineSettings->SetBeepBeforeExplodeDurationInMs(beepBeforeExplodeDurationInMs);
}

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");

  int beepBeforeExplodeDurationInMs = _airsoftSmartMineSettings->GetBeepBeforeExplodeDurationInMs();
  pCharacteristic->setValue(beepBeforeExplodeDurationInMs);
}

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");
}
