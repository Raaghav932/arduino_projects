
const int FRONT_BUTTON = 8;
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int BACK_BUTTON = 13;
void setup() 
{
  pinMode(FRONT_BUTTON,INPUT);
  pinMode(RED_PIN,OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(BLUE_PIN,OUTPUT);
  pinMode(BACK_BUTTON,INPUT);
  
  changeColor(LOW,HIGH,LOW);
}


void loop() {
  int front;
  int back;

  front = digitalRead(FRONT_BUTTON);
  back  = digitalRead(BACK_BUTTON);
if (front == LOW)
  {
    changeColor(LOW,LOW,HIGH);
  }
 if (back == LOW)
  {
    changeColor(HIGH,LOW,LOW);
  }
}
void changeColor(int red, int green, int blue)
{
      digitalWrite(RED_PIN,red);
      digitalWrite(GREEN_PIN,green);
      digitalWrite(BLUE_PIN,blue);
  
}
