#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int BACK_BUTTON = 13;
const int FWD_BUTTON = 8;
const int SPEED = 2;
const int RED_PIN = 10;
const int GREEN_PIN = 9;
const int BLUE_PIN = 6;
const int carLength = 14;
long startTime;
long endTime;
int distance;
 
void setup() 
{
  changeColors(LOW,LOW,LOW);
  lcd.begin(16, 2);
  sayLine1("Going Back !!");
  
  pinMode(BACK_BUTTON, INPUT);
  pinMode(FWD_BUTTON , INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  Serial.begin(9600);
}


void loop() 
{

    
  if (checkButton(BACK_BUTTON) == LOW)
  { 
    startTime = millis()/1000;
    sayLine1("Going Forwad !!");
    changeColors(LOW,LOW,HIGH);

  }

  if (checkButton(FWD_BUTTON) == LOW)
  {
    endTime = millis()/1000;
    distance = calculateDistance (startTime, endTime);
    sayLine1("distance");
    sayLine2(distance);
    changeColors(HIGH,LOW,LOW);


  }
}

int checkButton (int button)
{
  int state = digitalRead(button);
  return state;
}

void sayLine1(char message[])
{
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print(message);
}
void sayLine2(float distance)
{
  lcd.setCursor(0,1);
  lcd.print(distance);
}

int calculateDistance (long startTime,long endTime)
{
  long timeTaken = endTime - startTime;
  int distance = SPEED* timeTaken + carLength;

  return distance;
}
void changeColors(int red, int green, int blue)
{
      digitalWrite(RED_PIN,red);
      digitalWrite(GREEN_PIN,green);
      digitalWrite(BLUE_PIN,blue);
  
}

