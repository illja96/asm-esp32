#ifndef AirsoftSmartMineBLECharacteristicProperties_H_
#define AirsoftSmartMineBLECharacteristicProperties_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "AirsoftSmartMineBLECharacteristics.h"

class AirsoftSmartMineBLECharacteristicProperties
{
public:
  static const uint32_t RuntimeInSec;
  static const uint32_t Mode;
  static const uint32_t IsExploded;
  static const uint32_t BeepBeforeExplodeDurationInMs;
  static const uint32_t ExplodeDurationInMs;
  static const uint32_t IsForceExplodeViaBleInitiated;

  static const uint32_t All[sizeof(AirsoftSmartMineBLECharacteristics::All)];
};

#endif