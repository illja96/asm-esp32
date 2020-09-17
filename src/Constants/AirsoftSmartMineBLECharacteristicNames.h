#ifndef AirsoftSmartMineBLECharacteristicNames_H_
#define AirsoftSmartMineBLECharacteristicNames_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "AirsoftSmartMineBLECharacteristics.h"

class AirsoftSmartMineBLECharacteristicNames
{
private:
  AirsoftSmartMineBLECharacteristicNames();

public:
  static const char *Version;
  static const char *RuntimeInSec;
  static const char *Mode;
  static const char *IsExploded;
  static const char *BeepBeforeExplodeDurationInMs;
  static const char *ExplodeDurationInMs;
  static const char *IsForceExplodeViaBleInitiated;

  static const char *All[AirsoftSmartMineBLECharacteristics::AllLength];
};

#endif
