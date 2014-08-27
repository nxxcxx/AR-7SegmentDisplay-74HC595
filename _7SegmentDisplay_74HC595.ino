/* 74HC595 SHIFT REGISTER PIN CONFIG
Q0-Q7       = A-G
Q9-Q12      = common anode
Q8, Q13-Q16 = BLANK
*/

const int dataPin = 3;
const int clockPin = 4;
const int latchPin = 5;

const byte disp[4] = {
  B00000001,
  B00000010,
  B00000100,
  B00001000
};

const byte digits[10] = {
  B11000000,
  B11111001,
  B10100100,
  B10110000,
  B10011001,
  B10010010,
  B10000010,
  B11111000,
  B10000000,
  B10010000
};

int counter = 0;
long previousMillis = 0;
long interval = 100;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  
  showDigit(3, 8);
  showDigit(2, 7);
  showDigit(1, 6);
  showDigit(0, 5);
  
}

void showDigit(int dsp, int dgt) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, disp[dsp]);
  shiftOut(dataPin, clockPin, MSBFIRST, digits[dgt]);
  digitalWrite(latchPin, HIGH);
}


