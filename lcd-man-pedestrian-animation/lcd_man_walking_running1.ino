#include<Wire.h>

int sec = 15;
int x = 250;
int n;

//setting pixels for standing man:
//step 1 of 1:
  byte stepA1[8] = {B00011,B00111,B00111,B00111,B00111,B00001,B00011,B00111};
  byte stepA2[8] = {B00001,B00001,B00011,B00011,B00011,B00001,B00000,B00001};
  byte stepA3[8] = {B11111,B11111,B11111,B11111,B11111,B11011,B10001,B10001};
  byte stepA4[8] = {B11111,B11111,B11101,B11101,B11111,B11111,B11111,B11111};
  byte stepA5[8] = {B11000,B11100,B11100,B11100,B11100,B10000,B11000,B11100};
  byte stepA6[8] = {B00000,B10000,B11000,B00000,B11000,B11100,B11000,B10000};
  
//setting pixels for running man right:
//step 1 of 3:
  byte stepB1[8] = {B00011,B00011,B00011,B00011,B00001,B00000,B00000,B00000};
  byte stepB2[8] = {B00000,B00001,B00001,B00011,B00011,B00011,B00000,B00001};
  byte stepB3[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11110};
  byte stepB4[8] = {B11111,B11111,B11101,B11101,B11111,B11111,B11111,B11111};
  byte stepB5[8] = {B00000,B00000,B10000,B10000,B10000,B00000,B10000,B00000};
  byte stepB6[8] = {B00000,B11000,B00000,B11000,B11100,B11000,B10000,B00000};

//step 2 of 3
  byte stepC1[8] = {B11111,B11111,B11101,B00011,B00111,B01111,B01111,B00111};
  byte stepC2[8] = {B00000,B00001,B00001,B00011,B00011,B00011,B00000,B00111};
  byte stepC3[8] = {B11111,B11111,B11111,B11111,B11111,B10011,B00000,B00000};
  byte stepC4[8] = {B11111,B11111,B11101,B11101,B11111,B11111,B11111,B11111};
  byte stepC5[8] = {B11110,B11110,B01100,B11100,B11100,B11100,B00000,B00000};
  byte stepC6[8] = {B00000,B11000,B00000,B11000,B11100,B11000,B10000,B00000};
  
//step 3 of 3
  byte stepD1[8] = {B00001,B00011,B00111,B00111,B00111,B01111,B01100,B00000};
  byte stepD2[8] = {B00000,B00000,B00001,B00001,B00011,B00011,B00011,B00000};
  byte stepD3[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11110,B11111};
  byte stepD4[8] = {B00000,B11111,B11111,B11101,B11101,B11111,B11111,B11111};
  byte stepD5[8] = {B10000,B11000,B10000,B00000,B00000,B00000,B00000,B00000};
  byte stepD6[8] = {B00000,B00000,B11000,B00000,B11000,B11100,B11000,B10000};

//setting pixels for man slipping right
//step 1 of 3
  byte slipA1[8] = {B00111,B00111,B00011,B00011,B00001,B01111,B01111,B00111};
  byte slipA2[8] = {B00000,B00011,B00111,B01111,B01111,B00111,B00011,B00111};
  byte slipA3[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11000,B10000};
  byte slipA4[8] = {B11111,B11111,B11101,B11101,B11111,B11111,B11111,B11111};
  byte slipA5[8] = {B11000,B11000,B10000,B00000,B00000,B00000,B00000,B00000};
  byte slipA6[8] = {B00000,B11000,B00000,B11100,B11100,B11000,B10000,B11000};

//step 2 of 3
  byte slipB1[8] = {B00011,B00011,B00001,B00001,B00000,B00111,B00111,B00011};
  byte slipB2[8] = {B00000,B00001,B00011,B00111,B00111,B00011,B00001,B00011};
  byte slipB3[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11100,B11000};
  byte slipB4[8] = {B11111,B11111,B11110,B11110,B11111,B11111,B11111,B11111};
  byte slipB5[8] = {B11100,B11100,B11000,B10000,B10000,B00000,B00000,B00000};
  byte slipB6[8] = {B00000,B11000,B10000,B11100,B11110,B11100,B11000,B11100};

//step 3 of 3
  byte slipC1[8] = {B00001,B00001,B00000,B00000,B00000,B00011,B00011,B00001};
  byte slipC2[8] = {B00000,B00000,B00001,B00011,B00011,B00001,B00000,B00001};
  byte slipC3[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11110,B11100};
  byte slipC4[8] = {B01111,B11111,B11111,B11111,B11111,B11111,B11111,B11111};
  byte slipC5[8] = {B11110,B11110,B11100,B11000,B11000,B10000,B00000,B00000};
  byte slipC6[8] = {B10000,B11100,B11000,B11110,B11111,B11110,B11100,B11110};

//setting pixels for man running left
//step 1 of 3
  byte stepE1[8] = {B00000,B00001,B00001,B00001,B00000,B00000,B00001,B00000};
  byte stepE2[8] = {B00000,B00011,B00000,B00011,B00111,B00011,B00001,B00000};
  byte stepE3[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B01111};
  byte stepE4[8] = {B11111,B11111,B10111,B10111,B11111,B11111,B11111,B11111};
  byte stepE5[8] = {B11000,B11000,B11000,B11000,B10000,B00000,B00000,B00000};
  byte stepE6[8] = {B00000,B10000,B10000,B11000,B11000,B11000,B10000,B10000};
  
//step 2 of 3
  byte stepF1[8] = {B01111,B01111,B01100,B00111,B00111,B00111,B00000,B00000};
  byte stepF2[8] = {B00000,B00011,B00000,B00011,B00111,B00011,B00001,B00000};
  byte stepF3[8] = {B11111,B11111,B11111,B11111,B11111,B11001,B00000,B00000};
  byte stepF4[8] = {B11111,B11111,B10111,B10111,B11111,B11111,B11111,B11111};
  byte stepF5[8] = {B11111,B11111,B10111,B11000,B11100,B11110,B11110,B11100};
  byte stepF6[8] = {B00000,B10000,B10000,B11000,B11000,B11000,B00000,B11100};
  
//step 3 of 3
  byte stepG1[8] = {B00001,B00011,B00001,B00000,B00000,B00000,B00000,B00000};
  byte stepG2[8] = {B00000,B00000,B00011,B00000,B00011,B00111,B00011,B00001};
  byte stepG3[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B01111,B11111};
  byte stepG4[8] = {B00000,B11111,B11111,B10111,B10111,B11111,B11111,B11111};
  byte stepG5[8] = {B10000,B11000,B11100,B11100,B11100,B11110,B00110,B00000};
  byte stepG6[8] = {B00000,B00000,B10000,B10000,B11000,B11000,B11000,B00000};
  
//setting pixels for man slipping left
//step 1 of 3
  byte slipD1[8] = {B00011,B00011,B00001,B00000,B00000,B00000,B00000,B00000};
  byte slipD2[8] = {B00000,B00001,B00000,B00011,B00111,B00011,B00001,B00011};
  byte slipD3[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B00011,B00001};
  byte slipD4[8] = {B11111,B11111,B10111,B10111,B11111,B11111,B11111,B11111};
  byte slipD5[8] = {B11100,B11100,B11000,B11000,B10000,B11110,B11110,B11100};
  byte slipD6[8] = {B00000,B11000,B11100,B11110,B11110,B11100,B11000,B11100};

//step 2 of 3
  byte slipE1[8] = {B00111,B00111,B00111,B00011,B00001,B00000,B00000,B00000};
  byte slipE2[8] = {B00000,B00011,B00001,B00111,B01111,B00111,B00011,B00111};
  byte slipE3[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B00111,B00011};
  byte slipE4[8] = {B11111,B11111,B01111,B01111,B11111,B11111,B11111,B11111};
  byte slipE5[8] = {B11000,B11000,B10000,B00000,B10000,B11100,B11100,B11000};
  byte slipE6[8] = {B00000,B00000,B11000,B11100,B11100,B11000,B10000,B11000};
  
//step 3 of 3
  byte slipF1[8] = {B01111,B01111,B00111,B00111,B00011,B00001,B00000,B00000};
  byte slipF2[8] = {B00001,B00111,B00011,B01111,B11111,B01111,B00111,B01111};
  byte slipF3[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B01111,B00111};
  byte slipF4[8] = {B11110,B11111,B11111,B11111,B11111,B11111,B11111,B11111};
  byte slipF5[8] = {B00000,B00000,B00000,B00000,B00000,B11000,B11000,B10000};
  byte slipF6[8] = {B00000,B00000,B10000,B11000,B11000,B10000,B00000,B10000};

// include the library code:
#include <LiquidCrystal.h>

//defining arrow icon
byte arrowChar1[] = {B00000,B00010,B00110,B01111,B11111,B01111,B00110,B00010};
byte arrowChar2[] = {B00000,B00000,B00000,B11111,B11111,B11111,B00000,B00000};

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  Wire.begin(1);
  Wire.onReceive(dataRcv);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  delay(100);
}

void dataRcv(int numBytes){
  n = Wire.read();
  Serial.println(n);
  if (n>10){
    standingMan();
  }
  if (n>5 && n<=10){
    runningManR();
  }
  
  if (n>0 && n<=0){
    runningManL();
  }
}

void loop() {
 ;
}

//display standing man
void standingMan(){
  int a = 2;
  int b = a + 1;
  int c = a + 2;
  lcd.createChar(1, stepA1);
  lcd.createChar(2, stepA2);
  lcd.createChar(3, stepA3);
  lcd.createChar(4, stepA4);
  lcd.createChar(5, stepA5);
  lcd.createChar(6, stepA6);
  lcd.setCursor(a,1);
  lcd.write(1);
  lcd.setCursor(a,0);
  lcd.write(2);
  lcd.setCursor(b,1);
  lcd.write(3);
  lcd.setCursor(b,0);
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(5);
  lcd.setCursor(c,0);
  lcd.write(6);
  delay(1000);
}

// running man to the right animation part
void runningManR() {
  for (int a=2;a<11;a+=4){
  int b = a + 1;
  int c = a + 2;
  int d = a + 3;
  int e = a + 4;
  int f = a + 5;
  int g = a + 6;
  lcd.clear();
  lcd.createChar(1, stepB1);
  lcd.createChar(2, stepB2);
  lcd.createChar(3, stepB3);
  lcd.createChar(4, stepB4);
  lcd.createChar(5, stepB5);
  lcd.createChar(6, stepB6);
  lcd.setCursor(b,1);
  lcd.write(1);
  lcd.setCursor(b,0);
  lcd.write(2);
  lcd.setCursor(c,1);
  lcd.write(3);
  lcd.setCursor(c,0);
  lcd.write(4);
  lcd.setCursor(d,1);
  lcd.write(5);
  lcd.setCursor(d,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, stepC1);
  lcd.createChar(2, stepC2);
  lcd.createChar(3, stepC3);
  lcd.createChar(4, stepC4);
  lcd.createChar(5, stepC5);
  lcd.createChar(6, stepC6);
  lcd.setCursor(c,1);
  lcd.write(1);
  lcd.setCursor(c,0);
  lcd.write(2);
  lcd.setCursor(d,1);
  lcd.write(3);
  lcd.setCursor(d,0);
  lcd.write(4);
  lcd.setCursor(e,1);
  lcd.write(5);
  lcd.setCursor(e,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, stepB1);
  lcd.createChar(2, stepB2);
  lcd.createChar(3, stepB3);
  lcd.createChar(4, stepB4);
  lcd.createChar(5, stepB5);
  lcd.createChar(6, stepB6);
  lcd.setCursor(d,1);
  lcd.write(1);
  lcd.setCursor(d,0);
  lcd.write(2);
  lcd.setCursor(e,1);
  lcd.write(3);
  lcd.setCursor(e,0);
  lcd.write(4);
  lcd.setCursor(f,1);
  lcd.write(5);
  lcd.setCursor(f,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, stepD1);
  lcd.createChar(2, stepD2);
  lcd.createChar(3, stepD3);
  lcd.createChar(4, stepD4);
  lcd.createChar(5, stepD5);
  lcd.createChar(6, stepD6);
  lcd.setCursor(e,1);
  lcd.write(1);
  lcd.setCursor(e,0);
  lcd.write(2);
  lcd.setCursor(f,1);
  lcd.write(3);
  lcd.setCursor(f,0);
  lcd.write(4);
  lcd.setCursor(g,1);
  lcd.write(5);
  lcd.setCursor(g,0);
  lcd.write(6);
  delay(x);
  }
}

// running man to the left animation part
void runningManL(){
  for (int a=16;a>4;a-=4){
  int b = a - 1;
  int c = a - 2;
  int d = a - 3;
  int e = a - 4;
  int f = a - 5;
  int g = a - 6;
  lcd.clear();
  lcd.createChar(1, stepE1);
  lcd.createChar(2, stepE2);
  lcd.createChar(3, stepE3);
  lcd.createChar(4, stepE4);
  lcd.createChar(5, stepE5);
  lcd.createChar(6, stepE6);
  lcd.setCursor(d,1);
  lcd.write(1);
  lcd.setCursor(d,0);
  lcd.write(2);
  lcd.setCursor(c,1);
  lcd.write(3);
  lcd.setCursor(c,0);
  lcd.write(4);
  lcd.setCursor(b,1);
  lcd.write(5);
  lcd.setCursor(b,0);
  lcd.write(6);
  delay(x);
  pixClear();
  lcd.createChar(1, stepF1);
  lcd.createChar(2, stepF2);
  lcd.createChar(3, stepF3);
  lcd.createChar(4, stepF4);
  lcd.createChar(5, stepF5);
  lcd.createChar(6, stepF6);
  lcd.setCursor(e,1);
  lcd.write(1);
  lcd.setCursor(e,0);
  lcd.write(2);
  lcd.setCursor(d,1);
  lcd.write(3);
  lcd.setCursor(d,0);
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(5);
  lcd.setCursor(c,0);
  lcd.write(6);
  delay(x);
  pixClear();
  lcd.createChar(1, stepE1);
  lcd.createChar(2, stepE2);
  lcd.createChar(3, stepE3);
  lcd.createChar(4, stepE4);
  lcd.createChar(5, stepE5);
  lcd.createChar(6, stepE6);
  lcd.setCursor(f,1);
  lcd.write(1);
  lcd.setCursor(f,0);
  lcd.write(2);
  lcd.setCursor(e,1);
  lcd.write(3);
  lcd.setCursor(e,0);
  lcd.write(4);
  lcd.setCursor(d,1);
  lcd.write(5);
  lcd.setCursor(d,0);
  lcd.write(6);
  delay(x);
  pixClear();
  lcd.createChar(1, stepG1);
  lcd.createChar(2, stepG2);
  lcd.createChar(3, stepG3);
  lcd.createChar(4, stepG4);
  lcd.createChar(5, stepG5);
  lcd.createChar(6, stepG6);
  lcd.setCursor(g,1);
  lcd.write(1);
  lcd.setCursor(g,0);
  lcd.write(2);
  lcd.setCursor(f,1);
  lcd.write(3);
  lcd.setCursor(f,0);
  lcd.write(4);
  lcd.setCursor(e,1);
  lcd.write(5);
  lcd.setCursor(e,0);
  lcd.write(6);
  delay(x);
  }
}

void arrowIcon() {
  lcd.createChar(7 , arrowChar1);
  lcd.createChar(8 , arrowChar2);
  lcd.setCursor(0,0);
  lcd.write(7);
  lcd.setCursor(1,0);
  lcd.write(8);
}

void pixClear() {
  lcd.setCursor(2,0);
  lcd.print(" ");
  lcd.setCursor(2,1);
  lcd.print(" ");
  lcd.setCursor(3,0);
  lcd.print(" ");
  lcd.setCursor(3,1);
  lcd.print(" ");
  lcd.setCursor(4,0);
  lcd.print(" ");
  lcd.setCursor(4,1);
  lcd.print(" ");
  lcd.setCursor(5,0);
  lcd.print(" ");
  lcd.setCursor(5,1);
  lcd.print(" ");
  lcd.setCursor(6,0);
  lcd.print(" ");
  lcd.setCursor(6,1);
  lcd.print(" ");
  lcd.setCursor(7,0);
  lcd.print(" ");
  lcd.setCursor(7,1);
  lcd.print(" ");
  lcd.setCursor(8,0);
  lcd.print(" ");
  lcd.setCursor(8,1);
  lcd.print(" ");
  lcd.setCursor(9,0);
  lcd.print(" ");
  lcd.setCursor(9,1);
  lcd.print(" ");
  lcd.setCursor(10,0);
  lcd.print(" ");
  lcd.setCursor(10,1);
  lcd.print(" ");
  lcd.setCursor(11,0);
  lcd.print(" ");
  lcd.setCursor(11,1);
  lcd.print(" ");
  lcd.setCursor(12,0);
  lcd.print(" ");
  lcd.setCursor(12,1);
  lcd.print(" ");
  lcd.setCursor(13,0);
  lcd.print(" ");
  lcd.setCursor(13,1);
  lcd.print(" ");
  lcd.setCursor(14,0);
  lcd.print(" ");
  lcd.setCursor(14,1);
  lcd.print(" ");
  lcd.setCursor(15,0);
  lcd.print(" ");
  lcd.setCursor(15,1);
  lcd.print(" ");
}