#define RED       7
#define YELLOW    8
#define SPEAKER   13
#define LOW_NOTE  262
#define HIGH_NOTE 523
#define DUR       500
void setup() 
{
  
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(SPEAKER,OUTPUT);
}

void loop()
{
  // step 1: turn on
  digitalWrite(RED,HIGH);
  digitalWrite(YELLOW,LOW); 
  tone(SPEAKER, LOW_NOTE, DUR);
 // step 2: wait for 1 second. 
  delay(DUR);
  
  // step 3: turn off
  digitalWrite(RED,LOW);
  digitalWrite(YELLOW,HIGH); 
  tone(SPEAKER, HIGH_NOTE, DUR);
  // step 4: wait for 1 second. 
  delay(DUR);
}

