#include "AirsoftSmartMineBLEServerCallbacks.h"

AirsoftSmartMineBLEServerCallbacks::AirsoftSmartMineBLEServerCallbacks()
{
  pinMode(2, OUTPUT);
}

void AirsoftSmartMineBLEServerCallbacks::onConnect(BLEServer *bleServer)
{
  digitalWrite(2, HIGH);
};

void AirsoftSmartMineBLEServerCallbacks::onDisconnect(BLEServer *bleServer)
{
  digitalWrite(2, LOW);
}
