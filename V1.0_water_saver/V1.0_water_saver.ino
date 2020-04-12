const int RED_PIN = 6;
const int GREEN_PIN = 5;
const int BLUE_PIN = 3;
int BUTTON_ONE = 13;
int BUTTON_TWO = 12;
int SPEAKER = 9;
int TEMP = A0;
int TURNTABLE = A4;
int delay2 = 30;
int brightness = 0;
int fadeAmount = 5;
float turnValue = 0;
float turnValue2 = 0;
int BUTTON_TWO_STATE = 1;
float voltage, degreesC, degreesF;
int c = 6;
void setup() 
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON_ONE, INPUT);
  pinMode(BUTTON_TWO, INPUT);
  pinMode(SPEAKER, OUTPUT);
  pinMode(TEMP, INPUT);
  pinMode(TURNTABLE, INPUT);
  Serial.begin(9600);
  State_1(9);

}

void loop() 
{
}

int State_1 (int ignore)
{
  //turnValue = analogRead(TURNTABLE);
  int button1State = digitalRead(BUTTON_ONE);
  if(button1State == HIGH)
  {
    digitalWrite(RED_PIN, HIGH);
    State_2(9);                     
  }
  while(button1State == HIGH)
  {

    /*digitalWrite(RED_PIN, HIGH);
    analogWrite(GREEN_PIN, brightness);
    brightness = brightness + fadeAmount;
    if(brightness < 0 || brightness >= 255)
    {
    fadeAmount = -fadeAmount;
    }*/ 

  }
}


int State_2(int ignnore)
{
  //Serial.write("in s 2");
  turnValue = analogRead(TURNTABLE);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  digitalWrite(RED_PIN, LOW);
  if (c==6)
   {
      voltage = getVoltage(TEMP);
      degreesC = (voltage - 0.5) * 100.0;
      degreesF = degreesC * (9.0/5.0) + 32.0;
      //Serial.println(degreesF); 69
      turnValue = analogRead(TURNTABLE * 0.0);
      turnValue = turnValue * 0.093;
      turnValue2 = turnValue + 5;
      //Serial.println(turnValue);
      digitalWrite(RED_PIN,LOW);
      digitalWrite(BLUE_PIN,LOW);
      digitalWrite(GREEN_PIN,HIGH);
      delay(1000);
      //Serial.print("done");
      if(degreesF >= turnValue && degreesF <= turnValue2)
      {
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(BLUE_PIN,LOW);
        State_3(9);
        //Serial.print("done");  
      }
    } 
}

int State_3(int ignnnore)
{
  if(ignnnore == 9)
  {
    digitalWrite(GREEN_PIN,LOW);
    digitalWrite(RED_PIN,HIGH);
    digitalWrite(BLUE_PIN,LOW);
    //Serial.println("State_3");
    ignnnore = 10;
  }
  while (ignnnore==10)
    {
      tone(9,2000,2500);
      tone(9,4000,2500);
      delay(10000);
      digitalWrite(GREEN_PIN,HIGH);
      while(true)
        {
          digitalWrite(GREEN_PIN,LOW);
        }
    }
  if(BUTTON_TWO_STATE == LOW)
    {
      State_4(9);
      digitalWrite(GREEN_PIN,LOW);
      digitalWrite(BLUE_PIN,LOW);
      digitalWrite(RED_PIN,LOW);
    }
  }
  
int State_4(int ignnnnore)
{
if(true)
  {
    digitalWrite(GREEN_PIN,LOW);
    digitalWrite(BLUE_PIN,LOW);
    Serial.println("done");
    digitalWrite(RED_PIN,LOW);
  }

}

  

float getVoltage(int pin)
{
    return (analogRead(A4) * 0.004882814);
}




