FROM illja96/arduino-cli:0.13.0

ARG BUILD_NUMBER
RUN test -n "${BUILD_NUMBER}" || (echo "BUILD_NUMBER argument not provided" && false)

RUN apt install -y python3.9 python3-pip python-is-python3
RUN pip3 install pyserial

RUN arduino-cli core update-index --additional-urls "https://dl.espressif.com/dl/package_esp32_index.json"
RUN arduino-cli core install esp32:esp32 --additional-urls "https://dl.espressif.com/dl/package_esp32_index.json"

WORKDIR /usr/src/AirsoftSmartMine
COPY . ./
RUN sed -i "s|AirsoftSmartMineBLECharacteristicDefaultValues::Version = 0;|AirsoftSmartMineBLECharacteristicDefaultValues::Version = $BUILD_NUMBER;|g" src/Constants/AirsoftSmartMineBLECharacteristicDefaultValues.cpp

RUN arduino-cli compile --fqbn esp32:esp32:d32