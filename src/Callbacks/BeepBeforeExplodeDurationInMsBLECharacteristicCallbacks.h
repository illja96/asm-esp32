#include <Arduino.h>
#include <BLEDevice.h>

class BeepBeforeExplodeDurationInMsBLECharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
  const char *EspLogTag = "AirsoftSmartMineBLEServerCallbacks";

public:
  void onRead(BLECharacteristic *pCharacteristic);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onNotify(BLECharacteristic *pCharacteristic);
  void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
};
