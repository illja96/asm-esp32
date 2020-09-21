# Airsoft Smart Mine ESP32 (ASM ESP32)

ASM ESP32 is a part of ASM solution. This part contains microcontroller code written using Arduino Core for ESP32.

# Requirements

Required:
1. [WEMOS LOLIN32 Lite (CH340)](https://www.aliexpress.com/af/ESP32-CH340.html)
2. [HC-SR501 PIR Motion sensor module](https://www.aliexpress.com/af/HC%25252dSR501.html)
3. [3V Relay](https://www.aliexpress.com/af/3v-relay.html)
4. Battery
5. [Arduino IDE](https://www.arduino.cc/en/main/software)

Optional:
1. [ASMMT](https://github.com/illja96/asm-mt)
2. [3D printed body](https://www.thingiverse.com)

# Setup for development:
1. Install Arduino IDE
2. Install [Arduino core for ESP32](https://github.com/espressif/arduino-esp32)
3. Change `configurations.intelliSenseMode` to `clang-x64` in `.vscode/c_cpp_properties.json`