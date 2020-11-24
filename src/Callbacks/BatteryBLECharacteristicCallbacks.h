#ifndef BatteryBLECharacteristicCallbacks_H_
#define BatteryBLECharacteristicCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "../AirsoftSmartMineSettings.h"

class BatteryBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  static const std::string _EspLogTag;

  AirsoftSmartMineSettings *_airsoftSmartMineSettings;

  BatteryBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings);
  friend class AirsoftSmartMineBLECharacteristicCallbacks;

public:
  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};

#endif
