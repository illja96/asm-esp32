#ifndef AirsoftSmartMinePins_H_
#define AirsoftSmartMinePins_H_

#include <Arduino.h>

class AirsoftSmartMinePins
{
private:
  AirsoftSmartMinePins();

public:
  static const uint8_t BlueLed;
  static const uint8_t Battery;
  static const uint8_t ExplosionRelay;
};

#endif
