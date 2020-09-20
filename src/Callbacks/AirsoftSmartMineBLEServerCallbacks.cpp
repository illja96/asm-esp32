#include "AirsoftSmartMineBLEServerCallbacks.h"

const std::string AirsoftSmartMineBLEServerCallbacks::_EspLogTag = "AirsoftSmartMineBLEServerCallbacks";

AirsoftSmartMineBLEServerCallbacks::AirsoftSmartMineBLEServerCallbacks()
{
  ESP_LOGI(_EspLogTag, "AirsoftSmartMineBLEServerCallbacks");

  pinMode(2, OUTPUT);
}

void AirsoftSmartMineBLEServerCallbacks::onConnect(BLEServer *bleServer)
{
  ESP_LOGI(_EspLogTag, "onConnect");

  digitalWrite(2, HIGH);
};

void AirsoftSmartMineBLEServerCallbacks::onDisconnect(BLEServer *bleServer)
{
  ESP_LOGI(_EspLogTag, "onDisconnect");

  digitalWrite(2, LOW);
}
