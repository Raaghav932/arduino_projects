// This #include statement was automatically added by the Particle IDE.
//#include "AmazonSNSClient/AmazonSNSClient.h"

/*
	This sample publishes a message to an Amazon SNS target (topic or endpoint).
*/

//#include "application.h"
#include "AmazonSNSClient.h"
#include "SparkAWSImplementations.h"
#include "AWSFoundationalTypes.h"
#include "mykeys.h"

/* Constants for connecting to Amazon SNS. */
static const char* TARGET_ARN = "arn%3Aaws%3Asns%3Aus-west-2%3A706205996625%3ABetter_mouse_trap";  // replace each ':' with '%3A'
static const char* AWS_REGION = "us-west-2";  // us-west-2 etc
static const char* AWS_ENDPOINT = "amazonaws.com";


/* Light the LED while a message is transmitted. */
int led = 13;

/* Device independent implementations required for AmazonSNSClient to function. */
SparkHttpClient httpClient;
SparkDateTimeProvider dateTimeProvider;

/* AWS objects. */
AmazonSNSClient snsClient;
PublishInput publishInput;
ActionError actionError;



/*functions*/
int mouseMessage(String message);



void setup() {
    /* Begin serial communication. */
//    Serial.begin(9600);
	delay(5000);

	pinMode(led, OUTPUT);

	/* Initialize Amazon SNS client. */
	snsClient.setAWSRegion(AWS_REGION);
	snsClient.setAWSEndpoint(AWS_ENDPOINT);
	snsClient.setAWSSecretKey(awsSecKey);
	snsClient.setAWSKeyID(awsKeyID);
	snsClient.setHttpClient(&httpClient);
	snsClient.setDateTimeProvider(&dateTimeProvider);

	/*setup particle functions*/
	Particle.function("mouse",mouseMessage);
}

void loop() {
	/* Repeat SNS attempt every 60s. */
	Spark.publish("Log","Start Loop");


	
	
	delay(30000);

}

int mouseMessage(String message){
	mouseMessage("Mouse has been caught please take care of it");
	publishInput.setMessage((MinimalString)message);
	publishInput.setTargetArn(TARGET_ARN);
	PublishOutput publishOutput = snsClient.publish(publishInput, actionError);
	Spark.publish("Log",publishOutput.getMessageId().getCStr());

	return 0;
}





