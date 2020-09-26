FROM illja96/arduino-cli:latest
RUN arduino-cli core update-index --additional-urls "https://dl.espressif.com/dl/package_esp32_index.json"
RUN arduino-cli core install esp32:esp32 --additional-urls "https://dl.espressif.com/dl/package_esp32_index.json"
RUN arduino-cli compile --fqbn esp32:esp32:lolin32 AirsoftSmartMine.ino