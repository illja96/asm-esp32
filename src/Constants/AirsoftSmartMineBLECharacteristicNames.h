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
  static const std::string Version;
  static const std::string RuntimeInSec;
  static const std::string Mode;
  static const std::string IsExploded;
  static const std::string ExplodeDurationInMs;
  static const std::string IsForceExplodeViaBleInitiated;

  static const std::string All[AirsoftSmartMineBLECharacteristics::AllLength];
};

#endif
