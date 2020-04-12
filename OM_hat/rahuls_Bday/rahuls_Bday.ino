  int x;
  int y;
  int z;
  const int flag = 10;
void setup() {
  for(int i = 7;i<=7; i++)
  {
    pinMode(i,OUTPUT);
    pinMode(flag, INPUT);
  }

}

void loop() {
  if (flag == LOW)
  {
    for (x = 7; x <= 7; x++)
    {
      for (y = 7; y >=x; y--)
      {
        digitalWrite(y, HIGH);
        delay(500);
        digitalWrite(y, LOW);
      }
      digitalWrite(x, HIGH);
    }

   delay(5000);
  
    for (x = 7; x >= 7; x--)
    {
      for (y = x; y <= 7; y++)
      {
        digitalWrite(y, HIGH);
        delay(500);             
        digitalWrite(y, LOW);     
      }
    }
  }
   digitalWrite(y, LOW);
   delay(1000);
  

}
