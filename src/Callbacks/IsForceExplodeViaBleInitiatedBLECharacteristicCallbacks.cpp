#include "IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks.h"

IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  pCharacteristic->setValue(false);
}

void IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");

  std::string isForceExplodeViaBleInitiatedRaw = pCharacteristic->getValue();
  bool isForceExplodeViaBleInitiated = atoi(isForceExplodeViaBleInitiatedRaw.c_str());

  _airsoftSmartMineSettings->SetIsForceExplodeViaBleInitiated(isForceExplodeViaBleInitiated);
}

void IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");
}

void IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");
}
