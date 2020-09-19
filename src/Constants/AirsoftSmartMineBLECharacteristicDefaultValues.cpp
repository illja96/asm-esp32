#include "AirsoftSmartMineBLECharacteristicDefaultValues.h"

const int AirsoftSmartMineBLECharacteristicDefaultValues::Version = 0;
const int AirsoftSmartMineBLECharacteristicDefaultValues::RuntimeInSec = 0;
const int AirsoftSmartMineBLECharacteristicDefaultValues::Mode = (int)AirsoftSmartMineMode::Any;
const int AirsoftSmartMineBLECharacteristicDefaultValues::IsExploded = false;
const int AirsoftSmartMineBLECharacteristicDefaultValues::ExplodeDurationInMs = 0;
const int AirsoftSmartMineBLECharacteristicDefaultValues::IsForceExplodeViaBleInitiated = false;

const int AirsoftSmartMineBLECharacteristicDefaultValues::All[AirsoftSmartMineBLECharacteristics::AllLength] = {
    AirsoftSmartMineBLECharacteristicDefaultValues::Version,
    AirsoftSmartMineBLECharacteristicDefaultValues::RuntimeInSec,
    AirsoftSmartMineBLECharacteristicDefaultValues::Mode,
    AirsoftSmartMineBLECharacteristicDefaultValues::IsExploded,
    AirsoftSmartMineBLECharacteristicDefaultValues::ExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristicDefaultValues::IsForceExplodeViaBleInitiated};