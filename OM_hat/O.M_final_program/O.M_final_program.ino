
const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
int time = 100;          // time interval

//varibales 
boolean initialise=true;
int buttonState = 0;         // valriable for reading the pushbutton status
int mode = 0;
int x;
int y;
int z;

void setup()
{ 
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);  
  // The EL channels are on pins 2 through 9
  // Initialize the pins as outputs
  pinMode(2, OUTPUT);  // channel A
  pinMode(3, OUTPUT);  // channel B 
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D  
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H
  // We also have two status LEDs, pin 10 on the Escudo,
  pinMode(10, OUTPUT);   
  // and ledPin(pin 13) on the Arduino itself
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT); 
}

void loop()
{
  //Start program with a single run of LED illumination
  if (initialise==true)
  {
    delay(10);
    Serial.println("");
    Serial.println("");    
    Serial.println("Initialising...");     
    Serial.println("");
    int status;
    // Step through all eight EL channels (pins 2 through 9)
    for (x=2; x<=9; x++)
    {
      digitalWrite(ledPin, HIGH);    // turn LED on
      digitalWrite(x, HIGH);         // turn the EL channel on
      delay(100);                    // wait for 1/10 second
      digitalWrite(ledPin, LOW);     // turn LED off
      digitalWrite(x, LOW);          // turn the EL channel off
      delay(50);                     // wait for 1/10 second
      digitalWrite(ledPin, HIGH);    // turn LED on
      digitalWrite(x, HIGH);         // turn the EL channel on
      delay(100);                    // wait for 1/10 second
      digitalWrite(ledPin, LOW);     // turn LED off
      digitalWrite(x, LOW);          // turn the EL channel off
      delay(50);
      //stops running of initialisation after one iteration
      initialise=false;
    }
    Serial.println("");    
    Serial.println("Initialisation DONE!");     
    Serial.println("Waiting for Mode trigger");
  }
  detail();

  //=================MODE 1(Step through all eight EL channels)==================
  if (mode==1)
  {
    // Step through all eight EL channels (pins 2 through 9)
    for (x=2; x<=9; x++)
    {
      detail();
      digitalWrite(x, HIGH);   // turn the EL channel on
      delay(time);              // wait for 1/10 second
      digitalWrite(x, LOW);    // turn the EL channel off
    }
  }

  //=================MODE 2(fill up from bottom then empty from bottom)==================
  if (mode==2)
  {
    for (x=2; x<=9; x++)
    {
      detail();
      digitalWrite(x, HIGH);   // turn the EL channel on
      delay(time);        // wait for 1/10 second
    }
    for (x=2; x<=9; x++)
    {
      detail();
      digitalWrite(x, LOW);   // turn the EL channel on
      delay(time);        // wait for 1/10 second
    }
  }

  //=================MODE 3(up down up down)==================
  if (mode==3)
  {
    for (x=2; x<=9; x++)
    {
      detail();
      digitalWrite(x, HIGH);   // turn the EL channel on
      delay(time);        // wait for 1/10 second
      digitalWrite(x, LOW);    // turn the EL channel off
    }
    for (x=2; x<=9; x++)
    {
      detail();
      y=11-x;
      digitalWrite(y, HIGH);   // turn the EL channel on
      delay(time);        // wait for 1/10 second
      digitalWrite(y, LOW);    // turn the EL channel off
    }
  }

  //=================MODE 4(sweep in bottom to top , sweep out top to bottom)==================
  if (mode==4)
  {
    for(x = 2; x <= 9; x++)
    {
      detail();
      digitalWrite(x, HIGH);
      delay(time);
    }
    for(x = 9; x >= 2; x--)
    {
      detail();
      digitalWrite(x, LOW);
      delay(time);
    }
  }
 
  //=================MODE 5(stack and unstack)==================
  if (mode==5)
  {
    for (x = 2; x <= 9; x++)
    {
      for (y = 9; y >= x; y--)
      {
        digitalWrite(y, HIGH);
        delay(time); 
        digitalWrite(y, LOW);
        detail();   
      }
      digitalWrite(x, HIGH);
    }
    for (x = 9; x >= 2; x--)
    {
      for (y = x; y <= 9; y++)
      {
        digitalWrite(y, HIGH); 
        delay(time);              
        digitalWrite(y, LOW);      
        detail();
      }
    }
    digitalWrite(y, LOW);
    delay(time+20);
  }
 
  //=================MODE 6(alternate flashing)==================
  if (mode==6)
  {
    detail();
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    delay(time+75);
    detail();
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    delay(time+75);
    detail();
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
  }

  //=================MODE 7(criss cross)==================
  if (mode==7)
  {
    for (x = 2; x <= 9; x++)
    {
      y=11-x;
      digitalWrite(x, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(y, HIGH);   // turn the LED on (HIGH is the voltage level)
      if (x==5)
      {
        delay(time/2);
      }
      else
      {
        delay(time);
      }
      digitalWrite(x, LOW);
      digitalWrite(y, LOW);
      detail();   
    }   
  }   
 
  //=================MODE 8 ==================
  if (mode==8)
  {
    runAllSequences();
  }
}
// =========================================
// =============== FUNCTIONS ===============
// =========================================

void detail()
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW)
  {
    buttonPressed();
    digitalWrite(ledPin, LOW);
  }   
}

void buttonPressed()
{     
  digitalWrite(ledPin, HIGH);
  delay(300);             // pause to control the program. ensuring single mode change
  mode = mode + 1;        // increment Mode
  if (mode>8)             // if mode is greater than 9, restart from mode 1
  {
    mode=1;
    Serial.println(""); 
    Serial.println("Resetting Mode Sequence");
    Serial.println(""); 
    for (x=0;x<=3;x++)
    { 
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
    }
  } 
  Serial.println("");
  Serial.println("");    
  Serial.println("Button Pressed");     
  Serial.print("Mode: ");     
  Serial.print(mode);     
  Serial.println("");
  for(x=2;x<=9;x++)        //turn all channels off - reset for next loop
  {
    digitalWrite(x, LOW);         
  }
 
}
void runAllSequences()
{
  //=================MODE 1(step through all 8 channels)==================
  for (z = 0; z <=7; z++) //because this is relatively short sequence, do it a few times times
  { 
    // Step through all eight EL channels (pins 2 through 9)
    for (x=2; x<=9; x++)
    {
      detail();
      digitalWrite(x, HIGH);   // turn the EL channel on
      delay(time);              // wait for 1/10 second
      digitalWrite(x, LOW);    // turn the EL channel off
    }
  }
  for(x=2;x<=9;x++)        //turn all channels off - reset for next loop
  {
    digitalWrite(x, LOW);         
  }

  //=================MODE 2(fill up from bottom then empty from bottom)==================
  for (z = 0; z <=3; z++) //because this is relatively short sequence, do it a few times times
  {
    for (x=2; x<=9; x++)
    {
      detail();
      digitalWrite(x, HIGH);   // turn the EL channel on
      delay(time);        // wait for 1/10 second
    }
    for (x=2; x<=9; x++)
    {
      detail();
      digitalWrite(x, LOW);   // turn the EL channel on
      delay(time);        // wait for 1/10 second
    }
  }
  for(x=2;x<=9;x++)        //turn all channels off - reset for next loop
  {
    digitalWrite(x, LOW);         
  }

  //=================MODE 3(up down up down)==================
  for (z = 0; z <=3; z++) //because this is relatively short sequence, do it a few times times
  { 
    for (x=2; x<=9; x++)
    {
      detail();
      digitalWrite(x, HIGH);   // turn the EL channel on
      delay(time);        // wait for 1/10 second
      digitalWrite(x, LOW);    // turn the EL channel off
    }
    for (x=2; x<=9; x++)
    {
      detail();
      y=11-x;
      digitalWrite(y, HIGH);   // turn the EL channel on
      delay(time);        // wait for 1/10 second
      digitalWrite(y, LOW);    // turn the EL channel off
    }
  }
  for(x=2;x<=9;x++)        //turn all channels off - reset for next loop
  {
    digitalWrite(x, LOW);         
  }

  //=================MODE 4(sweep in bottom to top , sweep out top to bottom)==================
  for (z = 0; z <=3; z++) //because this is relatively short sequence, do it a few times times
  {
    for(x = 2; x <= 9; x++)
    {
      detail();
      digitalWrite(x, HIGH);
      delay(time);
    }
    for(x = 9; x >= 2; x--)
    {
      detail();
      digitalWrite(x, LOW);
      delay(time);
    }
  }
  for(x=2;x<=9;x++)        //turn all channels off - reset for next loop
  {
    digitalWrite(x, LOW);         
  }

  //=================MODE 5(stack and unstack)==================
  for (z = 0; z <=3; z++) //because this is relatively short sequence, do it a few times times
  {
    for (x = 2; x <= 9; x++)
    {
      for (y = 9; y >= x; y--)
      {
        digitalWrite(y, HIGH);
        delay(time); 
        digitalWrite(y, LOW);
        detail();   
      }
      digitalWrite(x, HIGH);
    }
    for (x = 9; x >= 2; x--)
    {
      for (y = x; y <= 9; y++)
      {
        digitalWrite(y, HIGH); 
        delay(time);              
        digitalWrite(y, LOW);      
        detail();
      }
    }
    digitalWrite(y, LOW);
    delay(time+20);
  }
  for(x=2;x<=9;x++)        //turn all channels off - reset for next loop
  {
    digitalWrite(x, LOW);         
  }

  //=================MODE 6(alternate flashing)==================
  for (z = 0; z <=10; z++) //because this is a short sequence, do it may times
  {
    detail();
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    delay(time+75);
    detail();
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    delay(time+75);
    detail();
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
  }
  for(x=2;x<=9;x++)        //turn all channels off - reset for next loop
  {
    digitalWrite(x, LOW);         
  }

  //=================MODE 7(criss cross)==================
  for (z = 0; z <=10; z++) //because this is a short sequence, do it may times
  {
    for (x = 2; x <= 9; x++)
    {
      y=11-x;
      digitalWrite(x, HIGH);   // turn the LED on (HIGH is the voltage level)

      digitalWrite(y, HIGH);   // turn the LED on (HIGH is the voltage level)
      if (x==5)
      {
        delay(time/2);
      }
      else
      {
        delay(time);
      }
      digitalWrite(x, LOW);
      digitalWrite(y, LOW);
      detail();   
    }   
  }
  for(x=2;x<=9;x++)        //turn all channels off - reset for next loop
  {
    digitalWrite(x, LOW);         
  }
}

