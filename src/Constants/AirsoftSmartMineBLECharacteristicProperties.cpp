#include "AirsoftSmartMineBLECharacteristicProperties.h"

const uint32_t AirsoftSmartMineBLECharacteristicProperties::Version = BLECharacteristic::PROPERTY_READ;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::RuntimeInSec = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::Mode = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::IsExploded = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::ExplodeDurationInMs = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::IsForceExplodeViaBleInitiated = BLECharacteristic::PROPERTY_WRITE;

const uint32_t AirsoftSmartMineBLECharacteristicProperties::All[AirsoftSmartMineBLECharacteristics::AllLength] = {
    AirsoftSmartMineBLECharacteristicProperties::Version,
    AirsoftSmartMineBLECharacteristicProperties::RuntimeInSec,
    AirsoftSmartMineBLECharacteristicProperties::Mode,
    AirsoftSmartMineBLECharacteristicProperties::IsExploded,
    AirsoftSmartMineBLECharacteristicProperties::ExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristicProperties::IsForceExplodeViaBleInitiated};