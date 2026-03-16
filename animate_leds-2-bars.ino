
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

int digit=0;     // 0,1,2,3 for digits 1..4
int segment=0;   // 0,1 for which segment a/d to light

void loop() {
  // Your main code runs here

  if (segment==1){
    digitalWrite(9, HIGH);    // a
    digitalWrite(7, LOW);    // d
  }else{
    digitalWrite(9, LOW); 
    digitalWrite(7, HIGH); 
  }

  digitalWrite(digit, HIGH);
  delay(5);
  digitalWrite(digit, LOW);

  if (digit==3){
    segment = (segment+1)%2;
  }
  digit = (digit+1)%4;

}