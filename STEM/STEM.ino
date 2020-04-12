
#include <Servo.h>
int r = -90;
int g = 180;

Servo myservo;


void setup()
{
  myservo.attach(10);

}

void loop()
{
  myservo.write(g);
}
