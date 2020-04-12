Servo dropServo;
Servo windServo;

int dropMotor(String ignore);
int pickMotor(String ignore);
int windMotor(String message);

int action (String ignore);
int working;

void setup()
{
	dropServo.attach(D3);
	windServo.attach(D1);
	Serial.begin(9600);

	Particle.function("drop",dropMotor);
	Particle.function("pick",pickMotor);
	Particle.function("wind",windMotor);

	Particle.function("scare",action);


	pinMode(A0,INPUT);

	working = 0;
}

void loop()
{
    delay (60000);
    if (working == 0)
    {
 //   	action("");
    }
    	

}
	

int action(String ignore)
{
	working = 1;
	_dropMotor();
	delay (5000);
	_pickMotor();
    _windMotor(0);
    working = 0;

}

int dropMotor(String ignore)
{
	return  _dropMotor();
}

int _dropMotor()
{

	dropServo.write(90);
	delay(200);
	Serial.println("motor dropped");

	return 0;
}

int pickMotor(String ignore)
{
	return  _pickMotor();
}

int _pickMotor()
{

	dropServo.write(0);
	delay(200);
	Serial.println("motor close");

	return 0;
}

int windMotor(String message)
{
	return  _windMotor(message.toInt());
}

int _windMotor(int ignore)
{


	windServo.write(0);
	delay(15000);
	Serial.println("motor winding");

	windServo.write(94);
	delay(2000);
	Serial.println("motor stop");


	return 0;
}

