#ifndef IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks_H_
#define IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "../AirsoftSmartMineSettings.h"

class IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  const char *_EspLogTag = "IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks";

  AirsoftSmartMineSettings *_airsoftSmartMineSettings;

  IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings);
  friend class AirsoftSmartMineBLECharacteristicCallbacks;

public:
  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};

#endif
