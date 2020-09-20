#include "AirsoftSmartMineBLECharacteristicNames.h"

const std::string AirsoftSmartMineBLECharacteristicNames::Version = "Version";
const std::string AirsoftSmartMineBLECharacteristicNames::RuntimeInSec = "RuntimeInSec";
const std::string AirsoftSmartMineBLECharacteristicNames::Mode = "Mode";
const std::string AirsoftSmartMineBLECharacteristicNames::IsExploded = "IsExploded";
const std::string AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs = "ExplodeDurationInMs";
const std::string AirsoftSmartMineBLECharacteristicNames::IsForceExplodeViaBleInitiated = "IsForceExplodeViaBleInitiated";

const std::string AirsoftSmartMineBLECharacteristicNames::All[AirsoftSmartMineBLECharacteristics::AllLength] = {
    AirsoftSmartMineBLECharacteristicNames::Version,
    AirsoftSmartMineBLECharacteristicNames::RuntimeInSec,
    AirsoftSmartMineBLECharacteristicNames::Mode,
    AirsoftSmartMineBLECharacteristicNames::IsExploded,
    AirsoftSmartMineBLECharacteristicNames::ExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristicNames::IsForceExplodeViaBleInitiated};