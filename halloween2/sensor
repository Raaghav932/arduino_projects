int sense=A1;
int detect=D1;
int val;

void setup() {
	Serial.begin(9600);
	pinMode(sense,INPUT);
	pinMode(detect,OUTPUT);
	digitalWrite(detect,HIGH);
	Serial.println("setup complete");
	Particle.variable("sensor",val);
}

void loop() {
	Serial.println("Loop starting");
	val=analogRead(sense);
	Serial.println("loop end:");
	Serial.println(val);
	delay(1000);
}
// when inturruption val = 40/50
