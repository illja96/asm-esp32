#include "AirsoftSmartMineBLECharacteristicDefaultValues.h"

const uint8_t AirsoftSmartMineBLECharacteristicDefaultValues::Version = 0;
const uint32_t AirsoftSmartMineBLECharacteristicDefaultValues::RuntimeInSec = 0;
const AirsoftSmartMineMode AirsoftSmartMineBLECharacteristicDefaultValues::Mode = AirsoftSmartMineMode::Any;
const uint8_t AirsoftSmartMineBLECharacteristicDefaultValues::IsExploded = 0;
const uint32_t AirsoftSmartMineBLECharacteristicDefaultValues::ExplodeDurationInMs = 1000;
const uint8_t AirsoftSmartMineBLECharacteristicDefaultValues::IsForceExplodeViaBleInitiated = 0;