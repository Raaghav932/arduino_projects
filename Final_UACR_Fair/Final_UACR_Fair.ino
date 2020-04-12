//libraries for SD player
#include <BlockDriver.h>
#include <FreeStack.h>
#include <MinimumSerial.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <SysCall.h>
#include <SFEMP3Shield.h>
#include <SFEMP3ShieldConfig.h>
#include <SFEMP3Shieldmainpage.h>


#define PIR_AOUT A1
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
//-----------------------------------------------------------------
// For motion sensor
#define PIR_AOUT A0  
#define PIR_DOUT 5   
#define LED_PIN  13
#define PRINT_TIME 100
unsigned long lastPrint = 0;


void setup() {
  // configure EL wire
  Serial.begin(9600);
  pinMode(3, OUTPUT);  // channel B 
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D  
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H
  pinMode(LED_BUILTIN, OUTPUT);
//-----------------------------------------------
// For motion sensor
  pinMode(PIR_AOUT, INPUT);
  pinMode(PIR_DOUT, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
//------------------------------------------------
// For music player
  for (int i=0; i<TRIGGER_COUNT; i++)
  {
    pinMode(triggerPins[i], INPUT_PULLUP);
  }
  pinMode(stopPin, INPUT_PULLUP);
  initSD();
  initMP3Player();

}

void loop() {
  digitalWrite(3, HIGH);  // channel B ON
  digitalWrite(4, HIGH);  // channel C ON
  digitalWrite(5, HIGH);  // channel D ON
  digitalWrite(6, HIGH);  // channel E ON
 int motionStatus = digitalRead(PIR_DOUT);
  Serial.print("EL wire working");
  if (motionStatus == HIGH){
    Serial.print("motion detected");
    MP3player.playMP3(filename);
    //flashy loop
    digitalWrite(3, HIGH);  // channel B ON
    delay(500);
    digitalWrite(4, HIGH);  // channel C ON
    delay(500);
    digitalWrite(5, HIGH);  // channel D ON
    delay(500);
    digitalWrite(6, HIGH);  // channel E ON
    delay(500);
    //Flashing
    digitalWrite(3, HIGH);  // B ON
    digitalWrite(4, HIGH);  // C ON
    digitalWrite(5, HIGH);  // D ON
    digitalWrite(6, HIGH);  // E ON
    digitalWrite(3, LOW);   // B OFF
    digitalWrite(4, LOW);   // C OFF
    digitalWrite(5, LOW);   // D OFF
    digitalWrite(6, LOW);   // E OFF
    digitalWrite(3, HIGH);  // B ON
    digitalWrite(4, HIGH);  // C ON
    digitalWrite(5, HIGH);  // D ON
    digitalWrite(6, HIGH);  // E ON
    digitalWrite(3, LOW);   // B OFF
    digitalWrite(4, LOW);   // C OFF
    digitalWrite(5, LOW);   // D OFF
    digitalWrite(6, LOW);   // E OFF
    digitalWrite(3, HIGH);  // B ON
    digitalWrite(4, HIGH);  // C ON
    digitalWrite(5, HIGH);  // D ON
    digitalWrite(6, HIGH);  // E ON
    digitalWrite(3, LOW);   // B OFF
    digitalWrite(4, LOW);   // C OFF
    digitalWrite(5, LOW);   // D OFF
    digitalWrite(6, LOW);   // E OFF
    delay(2000);
    //digitalWrite(A5, HIGH); 
  }
  
}



// MP3 player method
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

// MP3 player method
void initSD()
{
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) 
    sd.initErrorHalt();
  if(!sd.chdir("/")) 
    sd.errorHalt("sd.chdir");
}

//Motion Test method
void readDigitalValue()
{
  // The OpenPIR's digital output is active high
  int motionStatus = digitalRead(PIR_DOUT);

  // If motion is detected, turn the onboard LED on:
  if (motionStatus == HIGH)
    digitalWrite(LED_PIN, HIGH);
  else // Otherwise turn the LED off:
    digitalWrite(LED_PIN, LOW);
}
