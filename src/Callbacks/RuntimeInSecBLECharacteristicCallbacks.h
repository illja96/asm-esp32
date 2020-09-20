#ifndef RuntimeInSecBLECharacteristicCallbacks_H_
#define RuntimeInSecBLECharacteristicCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

class RuntimeInSecBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  static const std::string _EspLogTag;

  RuntimeInSecBLECharacteristicCallbacks();
  friend class AirsoftSmartMineBLECharacteristicCallbacks;

public:
  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};

#endif
