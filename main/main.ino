#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>
#include <Toggle.h>


#define BREAKOUT_RESET 9  
#define BREAKOUT_CS 10     
#define BREAKOUT_DCS 8 
#define SHIELD_RESET 8
#define SHIELD_CS 6     
#define SHIELD_DCS 7
#define CARDCS 9 
#define DREQ 2
#define PIR_PIN 3
#define CRADLE_PIN 5


Adafruit_VS1053_FilePlayer musicPlayer = Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

int pirState = 0;  
int pirVal = 0;  
int cradleState = 0;

bool ringing = 0;
bool audio = 0;

Toggle button(4, 5); 
 
void setup() {
  Serial.begin(9600);
  Serial.println("Red Box Initialised");

  musicPlayer.begin();
  SD.begin(CARDCS);
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  

  pinMode(PIR_PIN, INPUT);
  button.begin(CRADLE_PIN);
}
 
void loop(){
  pirVal = digitalRead(PIR_PIN);

  
  if (pirVal == HIGH) {            
    if (pirState == LOW) {
      Serial.println("motion detected!");
      ringing = 1;
      musicPlayer.setVolume(30,255);
      musicPlayer.startPlayingFile("/ring.mp3");
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }

  while (musicPlayer.playingMusic) {
    button.poll();
    if (button.isReleased() && ringing == 1 && audio == 0) {
      musicPlayer.stopPlaying();
      musicPlayer.setVolume(255,30);
      musicPlayer.startPlayingFile("/track001.mp3");
      ringing = 0;
      audio = 1;
    } else if (button.isPressed() && ringing == 0 && audio == 1) {
      musicPlayer.stopPlaying();
      delay(10000);
      audio = 0;
    }
  }
}