#include "AirsoftSmartMineSettings.h"

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

  const AirsoftSmartMineMode defaultMode = AirsoftSmartMineMode::Any;
  const int convertedDefaultMode = (int)defaultMode;

  int mode = _Preferences.getInt(AirsoftSmartMineBLECharacteristicNames::Mode, convertedDefaultMode);
  AirsoftSmartMineMode convertedMode = (AirsoftSmartMineMode)mode;

  return convertedMode;
}

void AirsoftSmartMineSettings::SetMode(AirsoftSmartMineMode mode)
{
  ESP_LOGI(_EspLogTag, "SetMode");

  _Preferences.putInt(AirsoftSmartMineBLECharacteristicNames::IsExploded, mode);
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

unsigned long AirsoftSmartMineSettings::GetBeepBeforeExplodeDurationInMs()
{
  ESP_LOGI(_EspLogTag, "GetBeepBeforeExplodeDurationInMs");

  const unsigned long defaultBeepBeforeExplodeDurationInMs = 1000;
  return _Preferences.getULong(AirsoftSmartMineBLECharacteristicNames::BeepBeforeExplodeDurationInMs, defaultBeepBeforeExplodeDurationInMs);
}

void AirsoftSmartMineSettings::SetBeepBeforeExplodeDurationInMs(unsigned long beepBeforeExplodeDurationInMs)
{
  ESP_LOGI(_EspLogTag, "SetBeepBeforeExplodeDurationInMs");

  _Preferences.putULong(AirsoftSmartMineBLECharacteristicNames::BeepBeforeExplodeDurationInMs, beepBeforeExplodeDurationInMs);
}

unsigned long AirsoftSmartMineSettings::GetExplodeDurationInMs()
{
  ESP_LOGI(_EspLogTag, "GetExplodeDurationInMs");

  const unsigned long defaultExplodeDurationInMs = 0;
  return _Preferences.getULong(AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs, defaultExplodeDurationInMs);
}

void AirsoftSmartMineSettings::SetExplodeDurationInMs(unsigned long explodeDurationInMs)
{
  ESP_LOGI(_EspLogTag, "SetExplodeDurationInMs");

  _Preferences.putULong(AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs, explodeDurationInMs);
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