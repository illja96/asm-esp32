#include "AirsoftSmartMineBLECharacteristicCallbacks.h"

const std::string AirsoftSmartMineBLECharacteristicCallbacks::_EspLogTag = "AirsoftSmartMineBLECharacteristicCallbacks";

BLECharacteristicCallbacks *AirsoftSmartMineBLECharacteristicCallbacks::Battery = nullptr;
BLECharacteristicCallbacks *AirsoftSmartMineBLECharacteristicCallbacks::Version = nullptr;
BLECharacteristicCallbacks *AirsoftSmartMineBLECharacteristicCallbacks::RuntimeInSec = nullptr;
BLECharacteristicCallbacks *AirsoftSmartMineBLECharacteristicCallbacks::Mode = nullptr;
BLECharacteristicCallbacks *AirsoftSmartMineBLECharacteristicCallbacks::IsExploded = nullptr;
BLECharacteristicCallbacks *AirsoftSmartMineBLECharacteristicCallbacks::ExplodeDurationInMs = nullptr;
BLECharacteristicCallbacks *AirsoftSmartMineBLECharacteristicCallbacks::IsForceExplodeViaBleInitiated = nullptr;

BLECharacteristicCallbacks *AirsoftSmartMineBLECharacteristicCallbacks::All[AirsoftSmartMineBLECharacteristics::AllLength];

void AirsoftSmartMineBLECharacteristicCallbacks::Initialize(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  ESP_LOGI(_EspLogTag, "Initialize");

  AirsoftSmartMineBLECharacteristicCallbacks::Battery = new BatteryBLECharacteristicCallbacks(airsoftSmartMineSettings);

  AirsoftSmartMineBLECharacteristicCallbacks::Version = new VersionBLECharacteristicCallbacks();
  AirsoftSmartMineBLECharacteristicCallbacks::All[AirsoftSmartMineBLECharacteristicIndexes::Version] = AirsoftSmartMineBLECharacteristicCallbacks::Version;

  AirsoftSmartMineBLECharacteristicCallbacks::RuntimeInSec = new RuntimeInSecBLECharacteristicCallbacks();
  AirsoftSmartMineBLECharacteristicCallbacks::All[AirsoftSmartMineBLECharacteristicIndexes::RuntimeInSec] = AirsoftSmartMineBLECharacteristicCallbacks::RuntimeInSec;

  AirsoftSmartMineBLECharacteristicCallbacks::Mode = new ModeBLECharacteristicCallbacks(airsoftSmartMineSettings);
  AirsoftSmartMineBLECharacteristicCallbacks::All[AirsoftSmartMineBLECharacteristicIndexes::Mode] = AirsoftSmartMineBLECharacteristicCallbacks::Mode;

  AirsoftSmartMineBLECharacteristicCallbacks::IsExploded = new IsExplodedBLECharacteristicCallbacks(airsoftSmartMineSettings);
  AirsoftSmartMineBLECharacteristicCallbacks::All[AirsoftSmartMineBLECharacteristicIndexes::IsExploded] = AirsoftSmartMineBLECharacteristicCallbacks::IsExploded;

  AirsoftSmartMineBLECharacteristicCallbacks::ExplodeDurationInMs = new ExplodeDurationInMsBLECharacteristicCallbacks(airsoftSmartMineSettings);
  AirsoftSmartMineBLECharacteristicCallbacks::All[AirsoftSmartMineBLECharacteristicIndexes::ExplodeDurationInMs] = AirsoftSmartMineBLECharacteristicCallbacks::ExplodeDurationInMs;

  AirsoftSmartMineBLECharacteristicCallbacks::IsForceExplodeViaBleInitiated = new IsForceExplodeViaBleInitiatedBLECharacteristicCallbacks(airsoftSmartMineSettings);
  AirsoftSmartMineBLECharacteristicCallbacks::All[AirsoftSmartMineBLECharacteristicIndexes::IsForceExplodeViaBleInitiated] = AirsoftSmartMineBLECharacteristicCallbacks::IsForceExplodeViaBleInitiated;
}