
#include "AmazonSNSClient.h"
#include "SparkAWSImplementations.h"
#include "AWSFoundationalTypes.h"
#include "mykeys.h"

/* Constants for connecting to Amazon SNS. */
static const char* TARGET_ARN = "arn%3Aaws%3Asns%3Aus-west-2%3A706205996625%3ABetter_mouse_trap";  // replace each ':' with '%3A'
static const char* AWS_REGION = "us-west-2";  // us-west-2 etc
static const char* AWS_ENDPOINT = "amazonaws.com";

//functions//
int snsMessage(String message);
int resetStatus(String ignore);
int turnMotor(String degrees);
//variabels//
int sense=A1;
int detect=D4;
int val;
int status;
Servo myservo;

SparkHttpClient httpClient;
SparkDateTimeProvider dateTimeProvider;

/* AWS objects. */
AmazonSNSClient snsClient;
PublishInput publishInput;
ActionError actionError;


void setup()
{
	Serial.begin(9600);
	Serial.println("It is working");
	pinMode(sense,INPUT);
	pinMode(detect,OUTPUT);
	digitalWrite(detect,HIGH);
	//Serial.println("setup complete");
	//Particle.variable("sensor",val);
	status = 0;
	snsClient.setAWSRegion(AWS_REGION);
	snsClient.setAWSEndpoint(AWS_ENDPOINT);
	snsClient.setAWSSecretKey(awsSecKey);
	snsClient.setAWSKeyID(awsKeyID);
	snsClient.setHttpClient(&httpClient);
	snsClient.setDateTimeProvider(&dateTimeProvider);
	MinimalString dateTime(dateTimeProvider.getDateTime());
	dateTimeProvider.sync(dateTime.getCStr());
	Particle.function("message",snsMessage);
	myservo.attach(D0);
	Particle.function("changeStatus", resetStatus);
	Particle.function("motor", turnMotor);
	Particle.variable("status", status);
}

void loop()
{
	
		readIR();

}

//functions//


// readIR function //
int readIR ()
{
	//digitalWrite(detect,HIGH);
	Serial.println("Reading ÎR:");
	delay(500);
	val=analogRead(sense);
	Serial.println(val);
	delay(1000);
		if (val> 3000 && status == 0)
		{
			turnMotor("180");
			snsMessage("Mouse has been caught please take care of it");
			status = 1;
			digitalWrite(detect,LOW);
			Serial.println("turned off light");

		}
	////////////////////Serial.println("starting turnddddMotor");
	return(0);
}

// motor function//
int turnMotor (String degrees)
{
	int r;
	r = _turnMotor(degrees.toInt());
	return r;
}

int _turnMotor (int degrees)
{
	int a;
	for (a = 32; a<35; a=a+1)
	{
	Serial.print("staaaaaaaaarrrrrrrrrrtttttttttiiiiiiiiiiinnnnnnng turn motor");
	Serial.print(degrees);
	myservo.write(degrees);
	delay(1000);	
	myservo.write(0);
	Serial.print("fiiiiiiinnnnnnnnnnsssssssssiiiiiiiiissssssshhhhhhhheeeeeeeeeddddddd turn motor");
	delay(1000);
  Serial.print(val);
	}
	return(0);

}
//sns function//
int snsMessage(String message)
{
	Serial.println("starting snsMessage");
	publishInput.setMessage((MinimalString)message);
	publishInput.setTargetArn(TARGET_ARN);
	PublishOutput publishOutput = snsClient.publish(publishInput, actionError);
	Spark.publish("Log",publishOutput.getMessageId().getCStr());
	Serial.println("We have finsished everything Yay!");

	return (0);
}

int resetStatus(String ignore)
{
	Serial.println("starting reset");
	status = 0;
	digitalWrite(detect,HIGH);
	return 0;
} 
