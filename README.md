
# Interactive Rotary Telephone Box
This is an Arduino-based project for a rotary telephone, designed for interactive exhibitions. When someone approaches the telephone, a PIR sensor triggers the phone to ring. If the phone is lifted off the cradle, a random audio recording is played. The current setup plays a static test audio file.

## Components Used:
- Arduino board
- PIR sensor
- Adafruit VS1053 Codec + MicroSD Breakout Board
- SD card to store audio files
- Rotary Telephone
- 5V Power supply

## Library Dependencies:
- SPI.h
- Adafruit_VS1053.h
- SD.h
- Toggle.h

## Hardware Connections:
The following pin connections should be used for the hardware:

- BREAKOUT_RESET: 9
- BREAKOUT_CS: 10
- BREAKOUT_DCS: 8
- SHIELD_RESET: 8
- SHIELD_CS: 6
- SHIELD_DCS: 7
- CARDCS: 9
- DREQ: 2
- PIR_PIN: 3
- CRADLE_PIN: 5
- 
## Software Functionality:
- Initialises Adafruit VS1053 FilePlayer and SD card.
- Listens for a HIGH signal from the PIR sensor (indicating motion is detected) to trigger the phone to ring (plays /ring.mp3).
- When the phone is lifted (button release event), stops the ringing sound, and starts playing a random audio file (/track001.mp3 in this case).
- When the phone is put back on the cradle (button press event), stops the audio file, and resets the system to detect the next motion.

## Required Files on the SD Card:
A ringtone file: /ring.mp3
One or more recorded messages: /track001.mp3, /track002.mp3, etc. Currently, only /track001.mp3 is used.
Please modify the Arduino code to suit the specific needs of your interactive exhibition, such as changing the audio files to play, adjusting the volume levels, or modifying the delay before resetting the system.
