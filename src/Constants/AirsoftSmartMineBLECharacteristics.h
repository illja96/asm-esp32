#ifndef AirsoftSmartMineBLECharacteristics_H_
#define AirsoftSmartMineBLECharacteristics_H_

#include <Arduino.h>
#include <BLEDevice.h>

class AirsoftSmartMineBLECharacteristics
{
private:
  AirsoftSmartMineBLECharacteristics();

public:
  static const std::string ServiceUUID;

  static const std::string Version;
  static const std::string RuntimeInSec;
  static const std::string Mode;
  static const std::string IsExploded;
  static const std::string ExplodeDurationInMs;
  static const std::string IsForceExplodeViaBleInitiated;

  static const uint8_t AllLength = 6;
  static const std::string All[AllLength];
};

#endif
