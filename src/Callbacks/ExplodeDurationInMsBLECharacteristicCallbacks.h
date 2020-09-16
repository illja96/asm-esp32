#ifndef ExplodeDurationInMsBLECharacteristicCallbacks_H_
#define ExplodeDurationInMsBLECharacteristicCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "../AirsoftSmartMineSettings.h"

class ExplodeDurationInMsBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  const char *_EspLogTag = "ExplodeDurationInMsBLECharacteristicCallbacks";

  AirsoftSmartMineSettings *_airsoftSmartMineSettings;

public:
  ExplodeDurationInMsBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings);

  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};

#endif
