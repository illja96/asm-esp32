#include "AirsoftSmartMineBLEConstants.h"
#include "AirsoftSmartMineMode.h"

const char *AirsoftSmartMineBLECharacteristics::ServiceUUID = "00000001-0001-0001-0001-000000000000";

const char *AirsoftSmartMineBLECharacteristics::RuntimeInSec = "00000001-0001-0001-0001-000000000001";
const char *AirsoftSmartMineBLECharacteristics::Mode = "00000001-0001-0001-0001-000000000002";
const char *AirsoftSmartMineBLECharacteristics::IsExploded = "00000001-0001-0001-0001-000000000003";
const char *AirsoftSmartMineBLECharacteristics::BeepBeforeExplodeDurationInMs = "00000001-0001-0001-0001-000000000004";
const char *AirsoftSmartMineBLECharacteristics::ExplodeDelayInMs = "00000001-0001-0001-0001-000000000005";
const char *AirsoftSmartMineBLECharacteristics::IsForceExplodeViaBleInitiated = "00000001-0001-0001-0001-000000000006";

const char *AirsoftSmartMineBLECharacteristics::All[6] = {
    AirsoftSmartMineBLECharacteristics::RuntimeInSec,
    AirsoftSmartMineBLECharacteristics::Mode,
    AirsoftSmartMineBLECharacteristics::IsExploded,
    AirsoftSmartMineBLECharacteristics::BeepBeforeExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristics::ExplodeDelayInMs,
    AirsoftSmartMineBLECharacteristics::IsForceExplodeViaBleInitiated,
};

const char *AirsoftSmartMineBLECharacteristicDescriptorValues::RuntimeInSec = "RuntimeInSec";
const char *AirsoftSmartMineBLECharacteristicDescriptorValues::Mode = "Mode";
const char *AirsoftSmartMineBLECharacteristicDescriptorValues::IsExploded = "IsExploded";
const char *AirsoftSmartMineBLECharacteristicDescriptorValues::BeepBeforeExplodeDurationInMs = "BeepBeforeExplodeDurationInMs";
const char *AirsoftSmartMineBLECharacteristicDescriptorValues::ExplodeDelayInMs = "ExplodeDelayInMs";
const char *AirsoftSmartMineBLECharacteristicDescriptorValues::IsForceExplodeViaBleInitiated = "IsForceExplodeViaBleInitiated";

const char *AirsoftSmartMineBLECharacteristicDescriptorValues::All[6] = {
    AirsoftSmartMineBLECharacteristicDescriptorValues::RuntimeInSec,
    AirsoftSmartMineBLECharacteristicDescriptorValues::Mode,
    AirsoftSmartMineBLECharacteristicDescriptorValues::IsExploded,
    AirsoftSmartMineBLECharacteristicDescriptorValues::BeepBeforeExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristicDescriptorValues::ExplodeDelayInMs,
    AirsoftSmartMineBLECharacteristicDescriptorValues::IsForceExplodeViaBleInitiated,
};

const uint32_t AirsoftSmartMineBLECharacteristicProperties::RuntimeInSec = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::Mode = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::IsExploded = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::BeepBeforeExplodeDurationInMs = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::ExplodeDelayInMs = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::IsForceExplodeViaBleInitiated = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE;

const uint32_t AirsoftSmartMineBLECharacteristicProperties::All[6] = {
    AirsoftSmartMineBLECharacteristicProperties::RuntimeInSec,
    AirsoftSmartMineBLECharacteristicProperties::Mode,
    AirsoftSmartMineBLECharacteristicProperties::IsExploded,
    AirsoftSmartMineBLECharacteristicProperties::BeepBeforeExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristicProperties::ExplodeDelayInMs,
    AirsoftSmartMineBLECharacteristicProperties::IsForceExplodeViaBleInitiated,
};

const int AirsoftSmartMineBLECharacteristicDefaultValues::RuntimeInSec = 0;
const int AirsoftSmartMineBLECharacteristicDefaultValues::Mode = (int)AirsoftSmartMineMode::Any;
const int AirsoftSmartMineBLECharacteristicDefaultValues::IsExploded = false;
const int AirsoftSmartMineBLECharacteristicDefaultValues::BeepBeforeExplodeDurationInMs = 1000;
const int AirsoftSmartMineBLECharacteristicDefaultValues::ExplodeDelayInMs = 0;
const int AirsoftSmartMineBLECharacteristicDefaultValues::IsForceExplodeViaBleInitiated = false;

const int AirsoftSmartMineBLECharacteristicDefaultValues::All[6] = {
    AirsoftSmartMineBLECharacteristicDefaultValues::RuntimeInSec,
    AirsoftSmartMineBLECharacteristicDefaultValues::Mode,
    AirsoftSmartMineBLECharacteristicDefaultValues::IsExploded,
    AirsoftSmartMineBLECharacteristicDefaultValues::BeepBeforeExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristicDefaultValues::ExplodeDelayInMs,
    AirsoftSmartMineBLECharacteristicDefaultValues::IsForceExplodeViaBleInitiated,
};