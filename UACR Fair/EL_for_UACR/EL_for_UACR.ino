void setup() {
  pinMode(3, OUTPUT);  // channel B 
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D  
  pinMode(6, OUTPUT);  // channel E
}
void loop() {
  digitalWrite(3, HIGH);  // channel B ON
  delay(500);
  digitalWrite(4, HIGH);  // channel C ON
  delay(500);
  digitalWrite(5, HIGH);  // channel D ON
  delay(500);
  digitalWrite(6, HIGH);  // channel E ON
  delay(500);
  //Flashing
  digitalWrite(3, HIGH);  // B ON
  digitalWrite(4, HIGH);  // C ON
  digitalWrite(5, HIGH);  // D ON
  digitalWrite(6, HIGH);  // E ON
  digitalWrite(3, LOW);   // B OFF
  digitalWrite(4, LOW);   // C OFF
  digitalWrite(5, LOW);   // D OFF
  digitalWrite(6, LOW);   // E OFF
  digitalWrite(3, HIGH);  // B ON
  digitalWrite(4, HIGH);  // C ON
  digitalWrite(5, HIGH);  // D ON
  digitalWrite(6, HIGH);  // E ON
  digitalWrite(3, LOW);   // B OFF
  digitalWrite(4, LOW);   // C OFF
  digitalWrite(5, LOW);   // D OFF
  digitalWrite(6, LOW);   // E OFF
  digitalWrite(3, HIGH);  // B ON
  digitalWrite(4, HIGH);  // C ON
  digitalWrite(5, HIGH);  // D ON
  digitalWrite(6, HIGH);  // E ON
  digitalWrite(3, LOW);   // B OFF
  digitalWrite(4, LOW);   // C OFF
  digitalWrite(5, LOW);   // D OFF
  digitalWrite(6, LOW);   // E OFF
}
