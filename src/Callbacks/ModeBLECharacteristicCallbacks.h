#ifndef ModeBLECharacteristicCallbacks_H_
#define ModeBLECharacteristicCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "../AirsoftSmartMineSettings.h"

class ModeBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  const char *_EspLogTag = "ModeBLECharacteristicCallbacks";

  AirsoftSmartMineSettings *_airsoftSmartMineSettings;

  ModeBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings);
  friend class AirsoftSmartMineBLECharacteristicCallbacks;

public:
  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};

#endif
