#ifndef AirsoftSmartMineBLEServerSecurityCallbacks_H_
#define AirsoftSmartMineBLEServerSecurityCallbacks_H_

#include <Arduino.h>
#include <BLEDevice.h>

class AirsoftSmartMineBLEServerSecurityCallbacks : public BLESecurityCallbacks
{
private:
  static const std::string _EspLogTag;

public:
  static const uint8_t Pin = 123456;

  AirsoftSmartMineBLEServerSecurityCallbacks();

  uint32_t onPassKeyRequest();
  void onPassKeyNotify(uint32_t pass_key);
  bool onSecurityRequest();
  void onAuthenticationComplete(esp_ble_auth_cmpl_t cmpl);
  bool onConfirmPIN(uint32_t pin);
};

#endif
