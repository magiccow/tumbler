
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
  
  // set D9 low to select segment a  
  digitalWrite(9, LOW); 

}

int digit=0;     // 0,1,2,3 for 
int segment=0;  

void loop() {
  // Your main code runs here

  digitalWrite(digit, HIGH);
  delay(500);
  digitalWrite(digit, LOW);
  digit = (digit+1)%4;

}