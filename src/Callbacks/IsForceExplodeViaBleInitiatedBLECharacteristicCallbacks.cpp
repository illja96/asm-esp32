#include "IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks.h"

const std::string IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::_EspLogTag = "IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks";

IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  ESP_LOGI(_EspLogTag, "IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks");

  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  bool isForceExplodeViaBleInitiated = false;
  uint8_t convertedIsForceExplodeViaBleInitiated = (uint8_t)isForceExplodeViaBleInitiated;

  pCharacteristic->setValue(&convertedIsForceExplodeViaBleInitiated, 1);
}

void IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");

  std::string isForceExplodeViaBleInitiatedRaw = pCharacteristic->getValue();
  ESP_LOGD(_EspLogTag, "isForceExplodeViaBleInitiatedRaw = %s", isForceExplodeViaBleInitiatedRaw.c_str());

  uint8_t parsedIsForceExplodeViaBleInitiated = atoi(isForceExplodeViaBleInitiatedRaw.c_str());
  ESP_LOGD(_EspLogTag, "parsedIsForceExplodeViaBleInitiated = %d", parsedIsForceExplodeViaBleInitiated);

  bool isForceExplodeViaBleInitiated = (bool)parsedIsForceExplodeViaBleInitiated;
  ESP_LOGD(_EspLogTag, "isForceExplodeViaBleInitiated = %d", isForceExplodeViaBleInitiated);

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
