int BUTTON_ONE = 13;
int BUTTON_ONE_State = 0;
const int RED_PIN = 6;
const int GREEN_PIN = 5;
const int BLUE_PIN = 3;
void setup() 
{
  pinMode(BUTTON_ONE, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() 
{
    int button1state = digitalRead(BUTTON_ONE);
    if(button1state == LOW)
    {
      digitalWrite(GREEN_PIN, HIGH);
  }
}