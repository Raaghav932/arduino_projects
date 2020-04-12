int speedPin = 3;
int motor1APin = 6;
int motor2APin = 7;
int ledPin = 13;
int speed_value_motor1;
int speedPin2 = 9;
int motor1Bpin = 12;
int motor2Bpin = 13;
int speed_value_motor2;

void setup() {
  pinMode(speedPin, OUTPUT); 
  pinMode(motor1APin, OUTPUT); 
  pinMode(motor2APin, OUTPUT); 
  pinMode(ledPin, OUTPUT);
  pinMode(speedPin2, OUTPUT);
  pinMode(motor1Bpin, OUTPUT);
  pinMode(motor2Bpin, OUTPUT);
}

void loop() {
  digitalWrite(motor1APin, HIGH);
  digitalWrite(motor2APin, LOW);
  digitalWrite(motor1Bpin, LOW);
  digitalWrite(motor2Bpin, HIGH);
  speed_value_motor1 = 0;
  speed_value_motor2 = 0;
  analogWrite(speedPin, speed_value_motor1);
  analogWrite(speedPin2, speed_value_motor2);
}
