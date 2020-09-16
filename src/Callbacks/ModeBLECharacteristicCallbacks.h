#include <Arduino.h>
#include <BLEDevice.h>

class ModeBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  const char *EspLogTag = "ModeBLECharacteristicCallbacks";

public:
  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};
