
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
  
  // Now just set 1 segment, a, on digit 1
  digitalWrite(3, HIGH);   
  digitalWrite(9, LOW); 

}

void loop() {
  // Your main code runs here
}