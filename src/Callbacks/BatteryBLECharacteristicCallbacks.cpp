#include "BatteryBLECharacteristicCallbacks.h"

const std::string BatteryBLECharacteristicCallbacks::_EspLogTag = "BatteryBLECharacteristicCallbacks";

BatteryBLECharacteristicCallbacks::BatteryBLECharacteristicCallbacks(AirsoftSmartMineSettings *airsoftSmartMineSettings)
{
  ESP_LOGI(_EspLogTag, "BatteryBLECharacteristicCallbacks");

  _airsoftSmartMineSettings = airsoftSmartMineSettings;
}

void BatteryBLECharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onRead");

  uint8_t batteryLevel = _airsoftSmartMineSettings->GetBattery();
  ESP_LOGD(_EspLogTag, "batteryLevel = %d", batteryLevel);

  char batteryLevelString[4];
  sprintf(batteryLevelString, "%d", batteryLevel);
  ESP_LOGD(_EspLogTag, "batteryLevelString = %s", batteryLevelString);

  pCharacteristic->setValue(batteryLevelString);
}

void BatteryBLECharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onWrite");
}

void BatteryBLECharacteristicCallbacks::onNotify(BLECharacteristic *pCharacteristic)
{
  ESP_LOGI(_EspLogTag, "onNotify");
}

void BatteryBLECharacteristicCallbacks::onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code)
{
  ESP_LOGI(_EspLogTag, "onStatus");

  ESP_LOGD(_EspLogTag, "s = %d", s);
  ESP_LOGD(_EspLogTag, "code = %lu", code);
}
