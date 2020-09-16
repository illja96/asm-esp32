#include <Arduino.h>
#include <BLEDevice.h>

class IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  const char *EspLogTag = "IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks";

public:
  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};
