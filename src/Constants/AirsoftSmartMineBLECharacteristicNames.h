#ifndef AirsoftSmartMineBLECharacteristicSizeOfs_H_
#define AirsoftSmartMineBLECharacteristicSizeOfs_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "AirsoftSmartMineBLECharacteristics.h"

class AirsoftSmartMineBLECharacteristicNames
{
public:
  static const char *RuntimeInSec;
  static const char *Mode;
  static const char *IsExploded;
  static const char *BeepBeforeExplodeDurationInMs;
  static const char *ExplodeDurationInMs;
  static const char *IsForceExplodeViaBleInitiated;

  static const char *All[sizeof(AirsoftSmartMineBLECharacteristics::All)];
};

#endif
