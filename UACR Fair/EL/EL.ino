// Channel E is not working
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);  // channel B 
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D  
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H
  pinMode(LED_BUILTIN, OUTPUT);

}
void loop() {
  digitalWrite(3, HIGH);  // channel B ON
  digitalWrite(4, HIGH);  // channel C ON
  digitalWrite(5, HIGH);  // channel D ON
  digitalWrite(6, HIGH);  // channel E ON
  digitalWrite(7, HIGH);  // channel F ON
  digitalWrite(8, HIGH);  // channel G ON
  digitalWrite(9, HIGH);  // channel H ON
  Serial.print("Working");
  
}
