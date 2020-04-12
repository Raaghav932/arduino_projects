#include <Servo.h>
Servo myservo;
int pos = 0;

int turnMotor(String message);

void setup()
{
  myservo.attach(2);
  //Particle.function("motor",turnMotor);
  Serial.begin(9600);

}

void loop()
{
  //digitalWrite(2, HIGH);
  _turnMotor(45);
  delay(9000);
  Serial.println("it worked");

}

int turnMotor(String message)
{
  int r;
  r = _turnMotor(message.toInt());
  return r;


}

int _turnMotor(int degrees)
{
  for (pos = 0; pos< degrees; pos += 1)
  {
    myservo.write(pos);
    delay(15);
  }
  
  Serial.println("first motor turn complete");

  for (pos = degrees; pos>= 0; pos-=1)
  {
    myservo.write(pos);
    delay(15);

  } 
  
  Serial.println("second motor turn complete");
  return 0;
}
