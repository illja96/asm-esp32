#include "AirsoftSmartMineBLEServerCallbacks.h"

const std::string AirsoftSmartMineBLEServerCallbacks::_EspLogTag = "AirsoftSmartMineBLEServerCallbacks";

AirsoftSmartMineBLEServerCallbacks::AirsoftSmartMineBLEServerCallbacks()
{
  ESP_LOGI(_EspLogTag, "AirsoftSmartMineBLEServerCallbacks");

  _isClientConnected = false;
  pinMode(AirsoftSmartMinePins::BlueLed, OUTPUT);
  digitalWrite(AirsoftSmartMinePins::BlueLed, LOW);
}

void AirsoftSmartMineBLEServerCallbacks::onConnect(BLEServer *bleServer)
{
  ESP_LOGI(_EspLogTag, "onConnect");

  _isClientConnected = true;
  digitalWrite(AirsoftSmartMinePins::BlueLed, HIGH);
};

void AirsoftSmartMineBLEServerCallbacks::onDisconnect(BLEServer *bleServer)
{
  ESP_LOGI(_EspLogTag, "onDisconnect");

  _isClientConnected = false;
  digitalWrite(AirsoftSmartMinePins::BlueLed, LOW);
}

bool AirsoftSmartMineBLEServerCallbacks::isClientConnected()
{
  return _isClientConnected;
}
