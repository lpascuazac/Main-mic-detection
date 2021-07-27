# Main-mic-detection
Noise detection with ESP-32 through KY037/KY038 mic module and alert transmission via serial bluetooth 

Noise is detected by ESP-32 by digital input signal from KY037/KY038 mic module and via integrated serial bluetooth a message is sended to connected devices. 

Development card ESP-32 is programmed using Arduino IDE. 

URL below is added into IDE's "URLs manager", and the ESP-32 is searched on "boards manager" and selected as development board on the IDE.
    https://dl.espressif.com/dl/package_esp32_index.json
    
    
"BluetoothSerial.h" used library is available on espressif's repository for ESP-32 support on the link below.
    https://github.com/espressif/arduino-esp32
