#include "ModeBLECharacteristicCallbacks.h"

const std::string ModeBLECharacteristicCallbacks::_EspLogTag = "ModeBLECharacteristicCallbacks";

ModeBLECharacteristicCallbacks::ModeBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  ESP_LOGI(_EspLogTag, "ModeBLECharacteristicCallbacks");

  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void ModeBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  AirsoftSmartMineMode mode = _airsoftSmartMineSettings->GetMode();
  
  char modeString[2];
  sprintf(modeString, "%d", mode);
  ESP_LOGD(_EspLogTag, "modeString = %s", modeString);

  pCharacteristic->setValue(modeString);
}

void ModeBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");

  std::string modeRaw = pCharacteristic->getValue();
  ESP_LOGD(_EspLogTag, "modeRaw = %s", modeRaw.c_str());

  uint8_t mode = atoi(modeRaw.c_str());
  ESP_LOGD(_EspLogTag, "mode = %d", mode);

  if (mode < AirsoftSmartMineMode::Any || mode > AirsoftSmartMineMode::BleOnly)
  {
    ESP_LOGW(_EspLogTag, "Mode out of range");
    return;
  }

  AirsoftSmartMineMode parsedMode = (AirsoftSmartMineMode)mode;
  ESP_LOGD(_EspLogTag, "parsedMode = %d", parsedMode);

  _airsoftSmartMineSettings->SetMode(parsedMode);
}

void ModeBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");
}

void ModeBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");
  
  ESP_LOGD(_EspLogTag, "s = %d", s);
  ESP_LOGD(_EspLogTag, "code = %lu", code);
}
