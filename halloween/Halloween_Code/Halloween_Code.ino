
//libraries
#include <BlockDriver.h>
#include <FreeStack.h>
#include <MinimumSerial.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <SysCall.h>
#include <SFEMP3Shield.h>
#include <SFEMP3ShieldConfig.h>
#include <SFEMP3Shieldmainpage.h>


#define PIR_AOUT A0
#define PIR_DOUT 10
#define LED_PIN 13
#define TRIGGER_COUNT 9
SdFat sd;
SFEMP3Shield MP3player;
int triggerPins[TRIGGER_COUNT] = {0,1};
int stopPin = A5;
int lastTrigger = 0;
char filename[ ] = "track003.mp3";
char filename2[ ] = "track002.mp3";
const uint8_t volume = 0;
const uint16_t monoMode = 1;
void setup() {
  //Configure Motion Sensor
  pinMode(PIR_AOUT, INPUT);
  pinMode(PIR_DOUT, INPUT);
  pinMode(LED_PIN, OUTPUT); // data light
  digitalWrite(LED_PIN, LOW);

  // configure mp3 player
  for (int i=0; i<TRIGGER_COUNT; i++)
  {
    pinMode(triggerPins[i], INPUT_PULLUP);
  }
  pinMode(stopPin, INPUT_PULLUP);
  initSD();
  initMP3Player();
}

void loop() {
 // readDigitalValue(); //read the motion sensor
  MP3player.playMP3(filename);

}

void readDigitalValue()
{
  int motionStatus = digitalRead(PIR_DOUT); // see if there is motion
  if (motionStatus == HIGH)
  {
    digitalWrite(LED_PIN, HIGH);
    MP3player.playMP3(filename2);
    if (MP3player.isPlaying())
    {
      MP3player.stopTrack();
    }
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
   
}

void initMP3Player()
{
  uint8_t result = MP3player.begin(); // init the mp3 player shield
  if(result != 0) // check result, see readme for error codes.
  {
    // Error checking can go here!
  }
  MP3player.setVolume(volume, volume);
  MP3player.setMonoMode(monoMode);
}

void initSD()
{
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) 
    sd.initErrorHalt();
  if(!sd.chdir("/")) 
    sd.errorHalt("sd.chdir");
}



