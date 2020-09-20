#ifndef AirsoftSmartMineBLECharacteristicIndexes_H_
#define AirsoftSmartMineBLECharacteristicIndexes_H_

#include <Arduino.h>
#include <BLEDevice.h>

class AirsoftSmartMineBLECharacteristicIndexes
{
private:
  AirsoftSmartMineBLECharacteristicIndexes();

public:
  static const uint8_t Version;
  static const uint8_t RuntimeInSec;
  static const uint8_t Mode;
  static const uint8_t IsExploded;
  static const uint8_t ExplodeDurationInMs;
  static const uint8_t IsForceExplodeViaBleInitiated;
};

#endif
