#ifndef AirsoftSmartMineBLECharacteristicCallbacks_H_
#define AirsoftSmartMineBLECharacteristicCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "AirsoftSmartMineBLECharacteristics.h"
#include "AirsoftSmartMineBLECharacteristicIndexes.h"

#include "../Callbacks/VersionBLECharacteristicCallbacks.h"
#include "../Callbacks/RuntimeInSecBLECharacteristicCallbacks.h"
#include "../Callbacks/ModeBLECharacteristicCallbacks.h"
#include "../Callbacks/IsExplodedBLECharacteristicCallbacks.h"
#include "../Callbacks/ExplodeDurationInMsBLECharacteristicCallbacks.h"
#include "../Callbacks/IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks.h"

#include "../AirsoftSmartMineSettings.h"

class AirsoftSmartMineBLECharacteristicCallbacks
{
private:
  static const std::string _EspLogTag;

  AirsoftSmartMineBLECharacteristicCallbacks();

public:
  static void Initialize(AirsoftSmartMineSettings *airsoftSmartMineSettings);

  static BLECharacteristicCallbacks *Version;
  static BLECharacteristicCallbacks *RuntimeInSec;
  static BLECharacteristicCallbacks *Mode;
  static BLECharacteristicCallbacks *IsExploded;
  static BLECharacteristicCallbacks *ExplodeDurationInMs;
  static BLECharacteristicCallbacks *IsForceExplodeViaBleInitiated;

  static BLECharacteristicCallbacks *All[AirsoftSmartMineBLECharacteristics::AllLength];
};

#endif
