#ifndef AirsoftSmartMineBLECharacteristics_H_
#define AirsoftSmartMineBLECharacteristics_H_

#include <Arduino.h>
#include <BLEDevice.h>

class AirsoftSmartMineBLECharacteristics
{
private:
  AirsoftSmartMineBLECharacteristics();

public:
  static const char *ServiceUUID;

  static const char *Version;
  static const char *RuntimeInSec;
  static const char *Mode;
  static const char *IsExploded;
  static const char *ExplodeDurationInMs;
  static const char *IsForceExplodeViaBleInitiated;

  static const int AllLength = 6;
  static const char *All[AllLength];
};

#endif
