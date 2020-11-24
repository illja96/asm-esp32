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

  const char *modeKey = AirsoftSmartMineBLECharacteristicNames::Mode.substr(0, 15).c_str();
  ESP_LOGD(_EspLogTag, "modeKey = %s", modeKey);

  uint8_t mode = _Preferences.getUChar(modeKey, convertedDefaultMode);
  AirsoftSmartMineMode convertedMode = (AirsoftSmartMineMode)mode;

  return convertedMode;
}

void AirsoftSmartMineSettings::SetMode(AirsoftSmartMineMode mode)
{
  ESP_LOGI(_EspLogTag, "SetMode");

  const uint8_t convertedDefaultMode = (uint8_t)mode;

  const char *modeKey = AirsoftSmartMineBLECharacteristicNames::Mode.substr(0, 15).c_str();
  ESP_LOGD(_EspLogTag, "modeKey = %s", modeKey);

  _Preferences.putUChar(modeKey, convertedDefaultMode);
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

  const char *explodeDurationInMsKey = AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs.substr(0, 15).c_str();
  ESP_LOGD(_EspLogTag, "explodeDurationInMsKey = %s", explodeDurationInMsKey);

  return _Preferences.getULong(explodeDurationInMsKey, defaultExplodeDurationInMs);
}

void AirsoftSmartMineSettings::SetExplodeDurationInMs(uint32_t explodeDurationInMs)
{
  ESP_LOGI(_EspLogTag, "SetExplodeDurationInMs");

  const char *explodeDurationInMsKey = AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs.substr(0, 15).c_str();
  ESP_LOGD(_EspLogTag, "explodeDurationInMsKey = %s", explodeDurationInMsKey);

  _Preferences.putULong(explodeDurationInMsKey, explodeDurationInMs);
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

uint8_t AirsoftSmartMineSettings::GetBattery()
{
  ESP_LOGI(_EspLogTag, "GetBattery");

  float batteryVoltage = analogRead(AirsoftSmartMinePins::Battery) / 4096.0 * 7.23;
  ESP_LOGD(_EspLogTag, "batteryVoltage = %f", batteryVoltage);

  const float lowBatteryVoltage = 3.5;
  const float highBatteryVoltage = 4.19;

  uint8_t batteryPercent = 0;

  if (batteryVoltage <= lowBatteryVoltage)
  {
    batteryPercent = 0;
  }

  if (batteryVoltage > lowBatteryVoltage && batteryVoltage <= highBatteryVoltage)
  {
    batteryPercent = 2808.3808 * pow(batteryVoltage, 4) - 43560.9157 * pow(batteryVoltage, 3) + 252848.5888 * pow(batteryVoltage, 2) - 650767.4615 * batteryVoltage + 626532.5703;
  }

  if (batteryVoltage > highBatteryVoltage)
  {
    batteryPercent = 100;
  }

  return batteryPercent;
}