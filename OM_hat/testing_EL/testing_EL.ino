//3 is blue
//4 is orange
//5 is purple
//7 is red
//8 is green
void setup()
{
  pinMode(12,INPUT);
  for(int i = 2;i<=9; i++)
  {
    pinMode(i,OUTPUT);
  }
}
void loop()
{
  int flag;
  flag=digitalRead(12);
  if (flag == LOW)
  {
    for(int i = 2;i<=9; i++)
    {
      digitalWrite(i,HIGH);
      delay(150);
      digitalWrite(i,LOW);
      delay(150);
  }
  }
//6
}
