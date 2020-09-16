#include "AirsoftSmartMineBLECharacteristicProperties.h"

const uint32_t AirsoftSmartMineBLECharacteristicProperties::RuntimeInSec = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::Mode = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::IsExploded = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::BeepBeforeExplodeDurationInMs = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::ExplodeDurationInMs = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE;
const uint32_t AirsoftSmartMineBLECharacteristicProperties::IsForceExplodeViaBleInitiated = BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE;

const uint32_t AirsoftSmartMineBLECharacteristicProperties::All[sizeof(AirsoftSmartMineBLECharacteristics::All)] = {
    AirsoftSmartMineBLECharacteristicProperties::RuntimeInSec,
    AirsoftSmartMineBLECharacteristicProperties::Mode,
    AirsoftSmartMineBLECharacteristicProperties::IsExploded,
    AirsoftSmartMineBLECharacteristicProperties::BeepBeforeExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristicProperties::ExplodeDurationInMs,
    AirsoftSmartMineBLECharacteristicProperties::IsForceExplodeViaBleInitiated};