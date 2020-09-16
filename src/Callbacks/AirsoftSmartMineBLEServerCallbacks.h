#ifndef AirsoftSmartMineBLEServerCallbacks_H_
#define AirsoftSmartMineBLEServerCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

class AirsoftSmartMineBLEServerCallbacks : public BLEServerCallbacks
{
private:
  const char *EspLogTag = "AirsoftSmartMineBLEServerCallbacks";

public:
  AirsoftSmartMineBLEServerCallbacks();

  void onConnect(BLEServer *bleServer);
  void onDisconnect(BLEServer *bleServer);
};

#endif
