#include "AirsoftSmartMineSettings.h"

const std::string AirsoftSmartMineSettings::_EspLogTag = "AirsoftSmartMineSettings";
Preferences AirsoftSmartMineSettings::_Preferences;

AirsoftSmartMineSettings::AirsoftSmartMineSettings()
{
  ESP_LOGI(_EspLogTag, "AirsoftSmartMineSettings");

  _isExploded = false;
  _isForceExplodeViaBleInitiated = false;

  esp_err_t err_init = nvs_flash_init();
  if (err_init == ESP_ERR_NVS_NO_FREE_PAGES || err_init == ESP_ERR_NVS_NEW_VERSION_FOUND)
  {
    ESP_ERROR_CHECK(nvs_flash_erase());
    err_init = nvs_flash_init();
  }
  ESP_ERROR_CHECK(err_init);

  _Preferences.begin("nvs", false);
}

AirsoftSmartMineSettings::~AirsoftSmartMineSettings()
{
  ESP_LOGI(_EspLogTag, "~AirsoftSmartMineSettings");

  _Preferences.end();
}

AirsoftSmartMineMode AirsoftSmartMineSettings::GetMode()
{
  ESP_LOGI(_EspLogTag, "GetMode");

  const AirsoftSmartMineMode defaultMode = AirsoftSmartMineBLECharacteristicDefaultValues::Mode;
  const uint8_t convertedDefaultMode = (uint8_t)defaultMode;

  uint8_t mode = _Preferences.getUChar(AirsoftSmartMineBLECharacteristicNames::Mode.c_str(), convertedDefaultMode);
  AirsoftSmartMineMode convertedMode = (AirsoftSmartMineMode)mode;

  return convertedMode;
}

void AirsoftSmartMineSettings::SetMode(AirsoftSmartMineMode mode)
{
  ESP_LOGI(_EspLogTag, "SetMode");

  const uint8_t convertedDefaultMode = (uint8_t)mode;
  _Preferences.putUChar(AirsoftSmartMineBLECharacteristicNames::IsExploded.c_str(), convertedDefaultMode);
}

bool AirsoftSmartMineSettings::GetIsExploded()
{
  ESP_LOGI(_EspLogTag, "GetIsExploded");

  return _isExploded;
}

void AirsoftSmartMineSettings::SetIsExploded(bool isExploded)
{
  ESP_LOGI(_EspLogTag, "SetIsExploded");

  _isExploded = isExploded;
}

uint32_t AirsoftSmartMineSettings::GetExplodeDurationInMs()
{
  ESP_LOGI(_EspLogTag, "GetExplodeDurationInMs");

  const uint32_t defaultExplodeDurationInMs = AirsoftSmartMineBLECharacteristicDefaultValues::ExplodeDurationInMs;
  return _Preferences.getULong(AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs.c_str(), defaultExplodeDurationInMs);
}

void AirsoftSmartMineSettings::SetExplodeDurationInMs(uint32_t explodeDurationInMs)
{
  ESP_LOGI(_EspLogTag, "SetExplodeDurationInMs");

  _Preferences.putULong(AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs.c_str(), explodeDurationInMs);
}

bool AirsoftSmartMineSettings::GetIsForceExplodeViaBleInitiated()
{
  ESP_LOGI(_EspLogTag, "GetIsForceExplodeViaBleInitiated");

  return _isForceExplodeViaBleInitiated;
}

void AirsoftSmartMineSettings::SetIsForceExplodeViaBleInitiated(bool isForceExplodeViaBleInitiated)
{
  ESP_LOGI(_EspLogTag, "SetIsForceExplodeViaBleInitiated");

  _isForceExplodeViaBleInitiated = isForceExplodeViaBleInitiated;
}