#ifndef AirsoftSmartMineBLEServerCallbacks_H_
#define AirsoftSmartMineBLEServerCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

#include "../Constants/AirsoftSmartMinePins.h"

class AirsoftSmartMineBLEServerCallbacks : public BLEServerCallbacks
{
private:
  static const std::string _EspLogTag;
  bool _isClientConnected;

public:
  AirsoftSmartMineBLEServerCallbacks();

  void onConnect(BLEServer *bleServer);
  void onDisconnect(BLEServer *bleServer);

  bool isClientConnected();
};

#endif
