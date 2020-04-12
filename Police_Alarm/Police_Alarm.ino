#define SPEED     0
#define FLAG      2
#define RED       7
#define YELLOW    8
#define SPEAKER   13

#define LOW_NOTE  262
#define HIGH_NOTE 523

void setup() 
{
  pinMode(FLAG,INPUT);
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(SPEAKER,OUTPUT);
}

void loop()
{

  int dur;
  int flag;

  // step 1: should I play?
  flag = digitalRead(FLAG);
  if (flag == LOW)
  {
    //step 2: Read speed
    dur = analogRead(SPEED);
    
    // step 2: red light
    digitalWrite(RED,HIGH);
    digitalWrite(YELLOW,LOW); 
    tone(SPEAKER, LOW_NOTE, dur);
   // step 2: wait. 
    delay(dur);
    
    // step 3: yellow light
    digitalWrite(RED,LOW);
    digitalWrite(YELLOW,HIGH); 
    tone(SPEAKER, HIGH_NOTE, dur);
    // step 4: wait for 1 second. 
    delay(dur);
  }  
  else
  {
    digitalWrite(RED,LOW);
    digitalWrite(YELLOW,LOW);

  //  tone(SPEAKER, LOW_NOTE, dur);
  //  delay(dur);
  
  }
  
}

