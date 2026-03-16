

// For each digit, describe the segments that have to be lit 
int ledMap[]={
  /* 0 */ 0x7e,
  /* 1 */ 0x48,
  /* 2 */ 0x3d,
  /* 3 */ 0x5d,
  /* 4 */ 0x4b,
  /* 5 */ 0x57,
  /* 6 */ 0x77,
  /* 7 */ 0x4c,
  /* 8 */ 0x7f,
  /* 9 */ 0x4f
};

// showNumber - Paint one digit on the tumble dryer display
//    row    - digit to display 0..3  (left to right)
//    number - value 0..9 to show
void showNumber( int row, int number ){
  int map = ledMap[number];
  for (int i=0; i<8; i++){   // switch segments on or off to paint the number on the 7 segments
    if(map & 0x40){
      // set segment to on
      digitalWrite(5+i, LOW);   // pin numbers are D5..D11 for cathodes
    }else{
      // set segment to off
      digitalWrite(5+i, HIGH);
    }
    map <<= 1;
  }
  digitalWrite(row, HIGH);   // switch on anode
}

// blankDigit - Switch off any lit segments for digit 0..3
void blankDigit( int row ){
  digitalWrite(row, LOW);
  for (int i=0; i<8; i++){
    digitalWrite(5+i, HIGH);
  }
}


void setup() {

  // Anodes are D0, D1, D2, D3, D4  ( left to right digits 0..3 and 4=sun/colon )
  // Cathodes are D5 (c), D6 (e), D7 (d), D8 (b), D9 (a), D10 (f), D11 (g)

  for (int port=0; port<12; port++){
    pinMode(port, OUTPUT);      // set all anodes and cathodes to outputs
    if (port<5)
      digitalWrite(port, LOW);  // Anodes set low
    else
      digitalWrite(port, HIGH); // Cathodes set high

  }

}


const unsigned int MaxDigits=4;

unsigned long digits[MaxDigits];  // Four digit number to display

// millisToDigits - read seconds and express as a 4-digit decimal number
void  millisToDigits(){

  unsigned long secs = millis() / 1000;    // millis is number of ms since power-on

  for (int i=0; i<MaxDigits; i++){     // Work out the value of each digit in the number
    digits[MaxDigits-i-1]= secs % 10;
    secs = secs / 10;
  }

}



int whichDigit=0;


void loop() {

  showNumber( whichDigit, digits[whichDigit] );
  delay(2);
  blankDigit( whichDigit );

  whichDigit = (whichDigit+1)%4;

  millisToDigits();   // update 'digits' array every second
}