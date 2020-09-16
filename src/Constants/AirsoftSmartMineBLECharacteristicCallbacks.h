#ifndef AirsoftSmartMineBLECharacteristicCallbacks_H_
#define AirsoftSmartMineBLECharacteristicCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "AirsoftSmartMineBLECharacteristics.h"

#include "../Callbacks/RuntimeInSecBLECharacteristicCallbacks.h"
#include "../Callbacks/ModeBLECharacteristicCallbacks.h"
#include "../Callbacks/IsExplodedBLECharacteristicCallbacks.h"
#include "../Callbacks/BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks.h"
#include "../Callbacks/ExplodeDurationInMsBLECharacteristicCallbacks.h"
#include "../Callbacks/IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks.h"

class AirsoftSmartMineBLECharacteristicCallbacks
{
public:
  static BLECharacteristicCallbacks RuntimeInSec;
  static BLECharacteristicCallbacks Mode;
  static BLECharacteristicCallbacks IsExploded;
  static BLECharacteristicCallbacks BeepBeforeExplodeDurationInMs;
  static BLECharacteristicCallbacks ExplodeDurationInMs;
  static BLECharacteristicCallbacks IsForceExplodeViaBleInitiated;

  static BLECharacteristicCallbacks All[sizeof(AirsoftSmartMineBLECharacteristics::All)];
};

#endif
