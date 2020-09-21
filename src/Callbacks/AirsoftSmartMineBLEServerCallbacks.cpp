#include "AirsoftSmartMineBLEServerCallbacks.h"

const std::string AirsoftSmartMineBLEServerCallbacks::_EspLogTag = "AirsoftSmartMineBLEServerCallbacks";

AirsoftSmartMineBLEServerCallbacks::AirsoftSmartMineBLEServerCallbacks()
{
  ESP_LOGI(_EspLogTag, "AirsoftSmartMineBLEServerCallbacks");

  _isClientConnected = false;
  pinMode(2, OUTPUT);
}

void AirsoftSmartMineBLEServerCallbacks::onConnect(BLEServer *bleServer)
{
  ESP_LOGI(_EspLogTag, "onConnect");

  _isClientConnected = true;
  digitalWrite(2, HIGH);
};

void AirsoftSmartMineBLEServerCallbacks::onDisconnect(BLEServer *bleServer)
{
  ESP_LOGI(_EspLogTag, "onDisconnect");

  _isClientConnected = false;
  digitalWrite(2, LOW);
}

bool AirsoftSmartMineBLEServerCallbacks::isClientConnected()
{
  return _isClientConnected;
}
