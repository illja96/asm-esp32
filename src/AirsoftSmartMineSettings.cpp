#include "AirsoftSmartMineSettings.h"

Preferences AirsoftSmartMineSettings::_Preferences;

AirsoftSmartMineSettings::AirsoftSmartMineSettings()
{
  _Preferences.begin("nvs", false);

  _isExploded = false;
  _isForceExplodeViaBleInitiated = false;
}

AirsoftSmartMineSettings::~AirsoftSmartMineSettings()
{
  _Preferences.end();
}

AirsoftSmartMineMode AirsoftSmartMineSettings::GetMode()
{
  const AirsoftSmartMineMode defaultMode = AirsoftSmartMineMode::Any;
  return _Preferences.getInt(AirsoftSmartMineBLECharacteristicNames::Mode, defaultMode);
}

void AirsoftSmartMineSettings::SetMode(AirsoftSmartMineMode mode)
{
  _Preferences.putInt(AirsoftSmartMineBLECharacteristicNames::IsExploded, mode);
}

bool AirsoftSmartMineSettings::GetIsExploded()
{
  return _isExploded;
}

void AirsoftSmartMineSettings::SetIsExploded(bool isExploded)
{
  _isExploded = isExploded;
}

unsigned long AirsoftSmartMineSettings::GetBeepBeforeExplodeDurationInMs()
{
  const unsigned long defaultBeepBeforeExplodeDurationInMs = 1000;
  return _Preferences.getULong(AirsoftSmartMineBLECharacteristicNames::BeepBeforeExplodeDurationInMs, defaultBeepBeforeExplodeDurationInMs);
}

void AirsoftSmartMineSettings::SetBeepBeforeExplodeDurationInMs(unsigned long beepBeforeExplodeDurationInMs)
{
  _Preferences.putULong(AirsoftSmartMineBLECharacteristicNames::BeepBeforeExplodeDurationInMs, beepBeforeExplodeDurationInMs);
}

unsigned long AirsoftSmartMineSettings::GetExplodeDurationInMs()
{
  const unsigned long defaultExplodeDurationInMs = 0;
  return _Preferences.getULong(AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs, defaultExplodeDurationInMs);
}

void AirsoftSmartMineSettings::SetExplodeDurationInMs(unsigned long explodeDurationInMs)
{
  _Preferences.putULong(AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs, explodeDurationInMs);
}

bool AirsoftSmartMineSettings::GetIsForceExplodeViaBleInitiated()
{
  return _isForceExplodeViaBleInitiated;
}

void AirsoftSmartMineSettings::SetIsForceExplodeViaBleInitiated(bool isForceExplodeViaBleInitiated)
{
  _isForceExplodeViaBleInitiated = isForceExplodeViaBleInitiated;
}