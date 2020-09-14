#ifndef AirsoftSmartMineBLEConstants_H_
#define AirsoftSmartMineBLEConstants_H_

#include <Arduino.h>
#include <BLEDevice.h>
#include <stdio.h>

#include "AirsoftSmartMineMode.h"

class AirsoftSmartMineBLECharacteristicDefaultValues
{
public:
  static const int RuntimeInSec;
  static const int Mode;
  static const int IsExploded;
  static const int BeepBeforeExplodeDurationInMs;
  static const int ExplodeDelayInMs;
  static const int IsForceExplodeViaBleInitiated;

  static const int All[6];
};

class AirsoftSmartMineBLECharacteristicDescriptorValues
{
public:
  static const char *RuntimeInSec;
  static const char *Mode;
  static const char *IsExploded;
  static const char *BeepBeforeExplodeDurationInMs;
  static const char *ExplodeDelayInMs;
  static const char *IsForceExplodeViaBleInitiated;

  static const char *All[6];
};

class AirsoftSmartMineBLECharacteristicProperties
{
public:
  static const uint32_t RuntimeInSec;
  static const uint32_t Mode;
  static const uint32_t IsExploded;
  static const uint32_t BeepBeforeExplodeDurationInMs;
  static const uint32_t ExplodeDelayInMs;
  static const uint32_t IsForceExplodeViaBleInitiated;

  static const uint32_t All[6];
};

class AirsoftSmartMineBLECharacteristics
{
public:
  static const char *ServiceUUID;

  static const char *RuntimeInSec;
  static const char *Mode;
  static const char *IsExploded;
  static const char *BeepBeforeExplodeDurationInMs;
  static const char *ExplodeDelayInMs;
  static const char *IsForceExplodeViaBleInitiated;

  static const char *All[6];

  static const AirsoftSmartMineBLECharacteristicProperties Properties;
  static const AirsoftSmartMineBLECharacteristicDescriptorValues DescriptorValues;
  static const AirsoftSmartMineBLECharacteristicDefaultValues DefaultValues;
};

class AirsoftSmartMineBLEServices
{
public:
  static AirsoftSmartMineBLECharacteristics Characteristics;
};

class AirsoftSmartMineBLEConstants
{
public:
  static AirsoftSmartMineBLEServices Services;
};

#endif
