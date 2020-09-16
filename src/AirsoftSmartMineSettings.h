#ifndef AirsoftSmartMineSettings_H_
#define AirsoftSmartMineSettings_H_

#include <Arduino.h>
#include <Preferences.h>

#include "AirsoftSmartMineMode.h"
#include "Constants/AirsoftSmartMineBLECharacteristicNames.h"

class AirsoftSmartMineSettings
{
private:
  const char *_EspLogTag = "AirsoftSmartMineBLEServerCallbacks";

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

  unsigned long GetBeepBeforeExplodeDurationInMs();
  void SetBeepBeforeExplodeDurationInMs(unsigned long beepBeforeExplodeDurationInMs);

  unsigned long GetExplodeDurationInMs();
  void SetExplodeDurationInMs(unsigned long explodeDurationInMs);

  bool GetIsForceExplodeViaBleInitiated();
  void SetIsForceExplodeViaBleInitiated(bool isForceExplodeViaBleInitiated);
};

#endif
