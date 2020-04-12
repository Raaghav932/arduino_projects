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
  if (flag == HIGH)
  {
   // int randPort;
   // randPort = random(2,9);
    digitalWrite(2,HIGH);
    
  }
  else
  {
    digitalWrite(2,LOW);
  }
 }
//6

