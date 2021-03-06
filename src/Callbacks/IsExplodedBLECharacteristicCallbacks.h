#ifndef IsExplodedBLECharacteristicCallbacks_H_
#define IsExplodedBLECharacteristicCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "../AirsoftSmartMineSettings.h"

class IsExplodedBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  static const std::string _EspLogTag;

  AirsoftSmartMineSettings *_airsoftSmartMineSettings;

  IsExplodedBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings);
  friend class AirsoftSmartMineBLECharacteristicCallbacks;

public:
  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};

#endif
