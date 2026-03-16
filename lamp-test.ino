
void setup() {

  // Anodes are D0, D1, D2, D3, D4  (5)
  // Cathodes are D5, D6, D7, D8, D9, D10, D11  (7)

  for (int port=0; port<12; port++){
    pinMode(port, OUTPUT);      // set all anodes and cathodes to outputs
    if (port<5)
      digitalWrite(port, LOW);  // Anodes set low
    else
      digitalWrite(port, HIGH); // Cathodes set high

  }

  for(int i=0; i<4; i++)
    flashAllSegments(i);

  flashSpecials();
}


void flashSpecials(){

  digitalWrite(6, LOW);  // colon
  digitalWrite(8, LOW);  // half heat
  digitalWrite(11, LOW); // full heat

  digitalWrite(4, HIGH);

  delay(500);

  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);

}


void flashAllSegments(int digit){

  for (int i=5; i<12; i++)
    digitalWrite(i, LOW); 

  digitalWrite(digit, HIGH);
  delay(250);
  digitalWrite(digit, LOW);

  for (int i=5; i<12; i++)
    digitalWrite(i, HIGH); 

}





void loop() {
 


}