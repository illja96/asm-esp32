#ifndef AirsoftSmartMineBLECharacteristicIndexes_H_
#define AirsoftSmartMineBLECharacteristicIndexes_H_

#include <Arduino.h>
#include <BLEDevice.h>

class AirsoftSmartMineBLECharacteristicIndexes
{
public:
  static const int RuntimeInSec;
  static const int Mode;
  static const int IsExploded;
  static const int BeepBeforeExplodeDurationInMs;
  static const int ExplodeDurationInMs;
  static const int IsForceExplodeViaBleInitiated;
};

#endif