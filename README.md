
# Interactive Rotary Telephone Box
This Arduino-based project breathes new life into a classic rotary telephone, transforming it into an immersive cultural storytelling device. Situated in a boutique hotel, within a meticulously re-created red Telephone box, this installation offers guests an interactive experience that melds nostalgia with innovation.

![Red Telephone Box](/img/red-telephone-banner.jpg)

## How It Works
- **Sensor Activation:** As guests approach the Telephone box, they activate a proximity sensor, which in turn causes the rotary phone to ring. This not only draws attention but also invites interaction.
- **Storytelling Playback:** Lifting the phone from the cradle initiates an audio playback of storytelling recordings. These stories, rich in cultural heritage, are designed to immerse listeners and enhance the boutique hotel's ambiance through narrative.

## Objective

The installation aims to create an unforgettable experience for hotel guests, connecting them with cultural tales through an innovative medium. By merging historical elements with contemporary technology, the project enriches the hotel's environment, offering guests a unique opportunity to engage with the past in a uniquely dynamic way.
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

## Software Functionality:
- Initialises Adafruit VS1053 FilePlayer and SD card.
- Listens for a HIGH signal from the PIR sensor (indicating motion is detected) to trigger the phone to ring (plays /ring.mp3).
- When the phone is lifted (button release event), stops the ringing sound, and starts playing a random audio file (/track001.mp3 in this case).
- When the phone is put back on the cradle (button press event), stops the audio file, and resets the system to detect the next motion.

## Required Files on the SD Card:
A ringtone file: /ring.mp3
One or more recorded messages: /track001.mp3, /track002.mp3, etc. Currently, only /track001.mp3 is used.
Please modify the Arduino code to suit the specific needs of your interactive exhibition, such as changing the audio files to play, adjusting the volume levels, or modifying the delay before resetting the system.
