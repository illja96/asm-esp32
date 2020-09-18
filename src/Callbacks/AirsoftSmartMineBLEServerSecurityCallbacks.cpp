#include "AirsoftSmartMineBLEServerSecurityCallbacks.h"

AirsoftSmartMineBLEServerSecurityCallbacks::AirsoftSmartMineBLEServerSecurityCallbacks()
{
  ESP_LOGI(_EspLogTag, "AirsoftSmartMineBLEServerSecurityCallbacks");
}

uint32_t AirsoftSmartMineBLEServerSecurityCallbacks::onPassKeyRequest()
{
  ESP_LOGI(_EspLogTag, "onPassKeyRequest");

  return Pin;
}

void AirsoftSmartMineBLEServerSecurityCallbacks::onPassKeyNotify(uint32_t pass_key)
{
  ESP_LOGI(_EspLogTag, "onPassKeyNotify");

  ESP_LOGD(_EspLogTag, "pass_key = %d", pass_key);
}

bool AirsoftSmartMineBLEServerSecurityCallbacks::onSecurityRequest()
{
  ESP_LOGI(_EspLogTag, "onSecurityRequest");

  return true;
}

void AirsoftSmartMineBLEServerSecurityCallbacks::onAuthenticationComplete(esp_ble_auth_cmpl_t cmpl)
{
  ESP_LOGI(_EspLogTag, "onAuthenticationComplete");

  ESP_LOGD(_EspLogTag, "cmpl.success = %d", cmpl.success);
}

bool AirsoftSmartMineBLEServerSecurityCallbacks::onConfirmPIN(uint32_t pin)
{
  ESP_LOGI(_EspLogTag, "onConfirmPIN");

  ESP_LOGD(_EspLogTag, "pin = %d", pin);

  //delay(5000);

  return true;
}
