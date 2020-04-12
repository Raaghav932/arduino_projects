Servo myservo;
int pos = 0;

int turnMotor(String message);

void setup()
{
	myservo.attach(D0);
	//Particle.function("motor",turnMotor);
	Serial.begin(9600);

}

void loop()
{
	_turnMotor(0);

}

//int turnMotor(String message)
//{
	//int r;
	//r = _turnMotor(message.toInt());
	//return r;


//}

int _turnMotor(int degrees)
{
	degrees = (0);
	degrees = (0);
	Servo myservo;
	//for (pos = 0; pos< degrees; pos += 1)
	//{
		myservo.write(degrees);
		delay(100);
	//}
	
	Serial.println("first motor turn complete");

	//for (pos = degrees; pos>= 0; pos-=1)
	//{
		myservo.write(0);
		delay(50);

	//} 
	
	Serial.println("second motor turn complete");
	Serial.println(degrees);
	return 0;
}
