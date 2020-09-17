#include "BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks.h"

BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  ESP_LOGI(_EspLogTag, "BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks");

  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  int beepBeforeExplodeDurationInMs = _airsoftSmartMineSettings->GetBeepBeforeExplodeDurationInMs();
  ESP_LOGD(_EspLogTag, "beepBeforeExplodeDurationInMs = %d", beepBeforeExplodeDurationInMs);

  pCharacteristic->setValue(beepBeforeExplodeDurationInMs);
}

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");

  std::string beepBeforeExplodeDurationInMsRaw = pCharacteristic->getValue();
  ESP_LOGD(_EspLogTag, "beepBeforeExplodeDurationInMsRaw = %s", beepBeforeExplodeDurationInMsRaw);

  unsigned long beepBeforeExplodeDurationInMs = atol(beepBeforeExplodeDurationInMsRaw.c_str());
  ESP_LOGD(_EspLogTag, "beepBeforeExplodeDurationInMs = %d", beepBeforeExplodeDurationInMs);

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
  ESP_LOGD(_EspLogTag, "beepBeforeExplodeDurationInMs = %d", beepBeforeExplodeDurationInMs);

  pCharacteristic->setValue(beepBeforeExplodeDurationInMs);
}

void BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");
}
