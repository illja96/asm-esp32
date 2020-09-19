#include "AirsoftSmartMineBLECharacteristicNames.h"

const char *AirsoftSmartMineBLECharacteristicNames::Version = "Version";
const char *AirsoftSmartMineBLECharacteristicNames::RuntimeInSec = "RuntimeInSec";
const char *AirsoftSmartMineBLECharacteristicNames::Mode = "Mode";
const char *AirsoftSmartMineBLECharacteristicNames::IsExploded = "IsExploded";
const char *AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs = "ExplodeDurationInMs";
const char *AirsoftSmartMineBLECharacteristicNames::IsForceExplodeViaBleInitiated = "IsForceExplodeViaBleInitiated";

const char *AirsoftSmartMineBLECharacteristicNames::All[AirsoftSmartMineBLECharacteristics::AllLength] = {
    AirsoftSmartMineBLECharacteristicNames::Version,
    AirsoftSmartMineBLECharacteristicNames::RuntimeInSec,
    AirsoftSmartMineBLECharacteristicNames::Mode,
    AirsoftSmartMineBLECharacteristicNames::IsExploded,
    AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristicNames::IsForceExplodeViaBleInitiated};