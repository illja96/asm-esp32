#include "AirsoftSmartMineBLECharacteristics.h"

const std::string AirsoftSmartMineBLECharacteristics::ServiceUUID = "00000001-0001-0001-0001-000000000000";

const std::string AirsoftSmartMineBLECharacteristics::Version = "00000001-0001-0001-0001-000000000001";
const std::string AirsoftSmartMineBLECharacteristics::RuntimeInSec = "00000001-0001-0001-0001-000000000002";
const std::string AirsoftSmartMineBLECharacteristics::Mode = "00000001-0001-0001-0001-000000000003";
const std::string AirsoftSmartMineBLECharacteristics::IsExploded = "00000001-0001-0001-0001-000000000004";
const std::string AirsoftSmartMineBLECharacteristics::ExplodeDurationInMs = "00000001-0001-0001-0001-000000000005";
const std::string AirsoftSmartMineBLECharacteristics::IsForceExplodeViaBleInitiated = "00000001-0001-0001-0001-000000000006";

const std::string AirsoftSmartMineBLECharacteristics::All[AllLength] = {
    AirsoftSmartMineBLECharacteristics::Version,
    AirsoftSmartMineBLECharacteristics::RuntimeInSec,
    AirsoftSmartMineBLECharacteristics::Mode,
    AirsoftSmartMineBLECharacteristics::IsExploded,
    AirsoftSmartMineBLECharacteristics::ExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristics::IsForceExplodeViaBleInitiated};