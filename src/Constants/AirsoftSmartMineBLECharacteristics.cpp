#include "AirsoftSmartMineBLECharacteristics.h"

const char *AirsoftSmartMineBLECharacteristics::ServiceUUID = "00000001-0001-0001-0001-000000000000";

const char *AirsoftSmartMineBLECharacteristics::Version = "00000001-0001-0001-0001-000000000001";
const char *AirsoftSmartMineBLECharacteristics::RuntimeInSec = "00000001-0001-0001-0001-000000000002";
const char *AirsoftSmartMineBLECharacteristics::Mode = "00000001-0001-0001-0001-000000000003";
const char *AirsoftSmartMineBLECharacteristics::IsExploded = "00000001-0001-0001-0001-000000000004";
const char *AirsoftSmartMineBLECharacteristics::BeepBeforeExplodeDurationInMs = "00000001-0001-0001-0001-000000000005";
const char *AirsoftSmartMineBLECharacteristics::ExplodeDurationInMs = "00000001-0001-0001-0001-000000000006";
const char *AirsoftSmartMineBLECharacteristics::IsForceExplodeViaBleInitiated = "00000001-0001-0001-0001-000000000007";

const char *AirsoftSmartMineBLECharacteristics::All[7] = {
    AirsoftSmartMineBLECharacteristics::Version,
    AirsoftSmartMineBLECharacteristics::RuntimeInSec,
    AirsoftSmartMineBLECharacteristics::Mode,
    AirsoftSmartMineBLECharacteristics::IsExploded,
    AirsoftSmartMineBLECharacteristics::BeepBeforeExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristics::ExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristics::IsForceExplodeViaBleInitiated};