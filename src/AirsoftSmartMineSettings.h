#ifndef AirsoftSmartMineSettings_H_
#define AirsoftSmartMineSettings_H_

#include <Arduino.h>
#include <Preferences.h>
#include <nvs_flash.h>

#include "AirsoftSmartMineMode.h"
#include "Constants/AirsoftSmartMineBLECharacteristicNames.h"
#include "Constants/AirsoftSmartMineBLECharacteristicDefaultValues.h"

class AirsoftSmartMineSettings
{
private:
  static const std::string _EspLogTag;
  static Preferences _Preferences;

  bool _isExploded;
  bool _isForceExplodeViaBleInitiated;

public:
  AirsoftSmartMineSettings();
  ~AirsoftSmartMineSettings();

  AirsoftSmartMineMode GetMode();
  void SetMode(AirsoftSmartMineMode mode);

  bool GetIsExploded();
  void SetIsExploded(bool isExploded);

  uint32_t GetExplodeDurationInMs();
  void SetExplodeDurationInMs(uint32_t explodeDurationInMs);

  bool GetIsForceExplodeViaBleInitiated();
  void SetIsForceExplodeViaBleInitiated(bool isForceExplodeViaBleInitiated);
};

#endif
