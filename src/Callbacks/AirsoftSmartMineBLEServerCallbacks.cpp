#include "AirsoftSmartMineBLEServerCallbacks.h"

AirsoftSmartMineBLEServerCallbacks::AirsoftSmartMineBLEServerCallbacks()
{
  ESP_LOGI(EspLogTag, "AirsoftSmartMineBLEServerCallbacks");

  pinMode(2, OUTPUT);
}

void AirsoftSmartMineBLEServerCallbacks::onConnect(BLEServer *bleServer)
{
  ESP_LOGI(EspLogTag, "onConnect");

  digitalWrite(2, HIGH);
};

void AirsoftSmartMineBLEServerCallbacks::onDisconnect(BLEServer *bleServer)
{
  ESP_LOGI(EspLogTag, "onDisconnect");

  digitalWrite(2, LOW);
}
