#define YELLOW    13
#define RED       12
#define BUTTON_G  7
#define SPEAKER   10
#define BUTTON_F  6     

#define DUR       200
void setup() {

  pinMode(YELLOW,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(BUTTON_G,INPUT);
  pinMode(BUTTON_F,INPUT);
  pinMode(SPEAKER, OUTPUT);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED,LOW);
}

void loop() {
  int flag_g;
  int flag_f;

  //step:1  should I play?
  flag_g = digitalRead(BUTTON_G);
  flag_f = digitalRead(BUTTON_F);
      
if (flag_g == LOW)
      {
      tone(SPEAKER,349,DUR);
      digitalWrite(RED,HIGH);
      delay(DUR);
      }
else
{
  digitalWrite(RED,LOW);
}
if (flag_f == LOW)
     {
      tone(SPEAKER,392,DUR);
      digitalWrite(YELLOW,HIGH);
      delay(DUR);
     }
else
{
  digitalWrite(YELLOW,LOW);
}
}
  
  
