
#define DUR 1000
const int TEMP_PIN = 0;
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

void setup()
{
  pinMode(TEMP_PIN,INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Serial.begin(9600);
  
  //turn off all LEDS
  changeColor(LOW,LOW,LOW);
  Serial.begin(9600);
}

void loop() 
{
  float temp;
  
  temp = getTempretureF(); 

  if (temp > 73)
    {
      changeColor(HIGH,LOW,LOW);
    }
  if (temp == 73)
  {
    changeColor(LOW,HIGH,LOW);
  }
  if (temp < 73)
  {
    changeColor(LOW,LOW,HIGH);
  }
  Serial.print("  temp:  ");
  Serial.println(temp);
  delay(1000);
}

float getTempretureF()  
{
  int tempread;
  float volt;
  float degreesC, degreesF;
  
  tempread=analogRead(TEMP_PIN);
  volt=(tempread*5000.0)/1024.0;
  degreesC = (volt - 500)/10;
  degreesF = (degreesC *9.0/5.0) + 32.0;

   Serial.print(volt)
  
  return degreesF;
}
void changeColor(int red, int green, int blue)
{
      digitalWrite(RED_PIN,red);
      digitalWrite(GREEN_PIN,green);
      digitalWrite(BLUE_PIN,blue);
  
}

