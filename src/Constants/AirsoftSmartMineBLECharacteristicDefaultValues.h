#ifndef AirsoftSmartMineBLECharacteristicDefaultValues_H_
#define AirsoftSmartMineBLECharacteristicDefaultValues_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "../AirsoftSmartMineMode.h"
#include "AirsoftSmartMineBLECharacteristics.h"

class AirsoftSmartMineBLECharacteristicDefaultValues
{
public:
  static const int Version;
  static const int RuntimeInSec;
  static const int Mode;
  static const int IsExploded;
  static const int BeepBeforeExplodeDurationInMs;
  static const int ExplodeDurationInMs;
  static const int IsForceExplodeViaBleInitiated;

  static const int All[AirsoftSmartMineBLECharacteristics::AllLength];
};

#endif
