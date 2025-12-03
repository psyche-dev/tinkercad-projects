//ST_CP to pin 12
const char lth = 12;
//SH_CP to pin 13
const char clk = 13;
//DS to pin 10
const char dat = 11;
//Red RGB Pin
const char red = 5;
//Green RGB Pin
const char green = 6;

// Inverse 7-segment binary since connected to the cathode pins
int invbit[9] = {
 //ABCDEFG
  B10011111,//num 1
  B00100011,//num 2
  B00001011,//num 3
  B10011001,//num 4
  B01001001,//num 5
  B01000001,//num 6
  B00011111,//num 7
  B00000001,//num 8
  B00001001	//num 9
};

void setup()
{
  pinMode(lth, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(dat, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  STOP();
  GO();
  READY();
}

// Go (Green) signal with 7 sec duration
void GO() {
  int g = 7; // duration
  analogWrite(green, 255);
  analogWrite(red, 0);
  for(int i=g-1; i>=0; i--) {
    digitalWrite(lth, 0);
    shiftOut(dat, clk, LSBFIRST, invbit[i]);
    digitalWrite(lth, 1);
    delay(1000);
  }
}

// Ready (Yellow) signal with 3 sec duration
void READY() {
  int r = 3; // duration
  analogWrite(red, 255);
  analogWrite(green, 255);
  for(int i=r-1; i>=0; i--) {
    digitalWrite(lth, 0);
    shiftOut(dat, clk, LSBFIRST, invbit[i]);
    digitalWrite(lth, 1);
    delay(1000);
  }
}

// Stop (Red) signal with 9 sec duration
void STOP() {
  int s = 9; // duration
  analogWrite(red, 255);
  analogWrite(green, 0);
  for(int i=s-1; i>=0; i--) {
    digitalWrite(lth, 0);
    shiftOut(dat, clk, LSBFIRST, invbit[i]);
    digitalWrite(lth, 1);
    delay(1000);
  }
}

//Reference: 
	//https://www.tinkercad.com/things/cgq6AzOQUAR-control-7-segment-led-with-74hc595-ic-using-shift-register