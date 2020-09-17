#ifndef VersionBLECharacteristicCallbacks_H_
#define VersionBLECharacteristicCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "../Constants/AirsoftSmartMineBLECharacteristicDefaultValues.h"

class VersionBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  const char *_EspLogTag = "VersionBLECharacteristicCallbacks";

  VersionBLECharacteristicCallbacks();
  friend class AirsoftSmartMineBLECharacteristicCallbacks;

public:
  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};

#endif
