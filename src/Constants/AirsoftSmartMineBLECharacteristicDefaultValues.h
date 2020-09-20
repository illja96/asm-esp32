#ifndef AirsoftSmartMineBLECharacteristicDefaultValues_H_
#define AirsoftSmartMineBLECharacteristicDefaultValues_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "../AirsoftSmartMineMode.h"
#include "AirsoftSmartMineBLECharacteristics.h"

class AirsoftSmartMineBLECharacteristicDefaultValues
{
private:
  AirsoftSmartMineBLECharacteristicDefaultValues();

public:
  static const uint8_t Version;
  static const uint32_t RuntimeInSec;
  static const AirsoftSmartMineMode Mode;
  static const uint8_t IsExploded;
  static const uint32_t ExplodeDurationInMs;
  static const uint8_t IsForceExplodeViaBleInitiated;
};

#endif
