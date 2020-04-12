//////////////////////////
// Hardware Definitions //
//////////////////////////
#define PIR_AOUT A0  // PIR analog output on A0
#define PIR_DOUT 2   // PIR digital output on D2
#define LED_PIN  13  // LED to illuminate on motion

#define PRINT_TIME 100 // Rate of serial printouts
unsigned long lastPrint = 0; // Keep track of last serial out

void setup() 
{
  Serial.begin(9600);  // Serial is used to view Analog out
  // Analog and digital pins should both be set as inputs:
  pinMode(PIR_AOUT, INPUT);
  pinMode(PIR_DOUT, INPUT);

  // Configure the motion indicator LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Turn the LED off
}

void loop() 
{
  // Read OUT pin, and set onboard LED to mirror output
  readDigitalValue(); 
}

void readDigitalValue()
{
  // The OpenPIR's digital output is active high
  int motionStatus = digitalRead(PIR_DOUT);

  // If motion is detected, turn the onboard LED on:
  if (motionStatus == HIGH){
    digitalWrite(LED_PIN, HIGH);
    Serial.println("It is working");
  }
  else 
    digitalWrite(LED_PIN, LOW);
    // Otherwise turn the LED off:
}


