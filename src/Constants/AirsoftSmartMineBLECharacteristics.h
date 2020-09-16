#ifndef AirsoftSmartMineBLECharacteristics_H_
#define AirsoftSmartMineBLECharacteristics_H_

#include <Arduino.h>
#include <BLEDevice.h>

class AirsoftSmartMineBLECharacteristics
{
public:
  static const char *ServiceUUID;

  static const char *RuntimeInSec;
  static const char *Mode;
  static const char *IsExploded;
  static const char *BeepBeforeExplodeDurationInMs;
  static const char *ExplodeDurationInMs;
  static const char *IsForceExplodeViaBleInitiated;

  static const char *All[6];
};

#endif
