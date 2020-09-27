FROM illja96/arduino-cli:latest

ARG BUILD_NUMBER
RUN test -n "${BUILD_NUMBER}" || (echo "BUILD_NUMBER argument not provided" && false)

WORKDIR /mnt/src
COPY . ./
RUN sed -i "s|AirsoftSmartMineBLECharacteristicDefaultValues::Version = 0;|AirsoftSmartMineBLECharacteristicDefaultValues::Version = $BUILD_NUMBER;|g" src/Constants/AirsoftSmartMineBLECharacteristicDefaultValues.cpp

RUN arduino-cli core update-index --additional-urls "https://dl.espressif.com/dl/package_esp32_index.json"
RUN arduino-cli core install esp32:esp32 --additional-urls "https://dl.espressif.com/dl/package_esp32_index.json"
RUN arduino-cli compile AirsoftSmartMine.ino --fqbn esp32:esp32:lolin32