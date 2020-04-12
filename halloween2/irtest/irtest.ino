int sense=A0;
int val;

void setup() {
	Serial.begin(9600);
	pinMode(sense,INPUT);
	Serial.println("setup complete");
	Particle.variable("sensor",val);
}

void loop() {
	val=analogRead(sense);
	Serial.println(val);
	delay(1000);
}
// when inturruption val = 40/50
