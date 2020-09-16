#ifndef BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks_H_
#define BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "../AirsoftSmartMineSettings.h"

class BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  const char *_EspLogTag = "AirsoftSmartMineBLEServerCallbacks";

  AirsoftSmartMineSettings *_airsoftSmartMineSettings;

public:
  BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings);

  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};

#endif
