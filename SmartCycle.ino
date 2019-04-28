#include <Adafruit_NeoPixel.h>
 
Adafruit_NeoPixel strip[] = {
  Adafruit_NeoPixel(9, 3, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(9, 6, NEO_GRB + NEO_KHZ800),
};
 
#define index_r 253
#define index_g 80
#define index_b 0
#define index_time 50
 
const int kapcs1 = 2;  
const int kapcs2 = 5;  
const int kapcs3 = 4;
 
int kapcs1State = 0;        
int kapcs2State = 0;      
int kapcs3State = 0;  
 
void setup() {
  strip[0].begin();
  strip[1].begin();
 
  pinMode(kapcs1, INPUT);
  pinMode(kapcs2, INPUT);
  pinMode(kapcs3, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  kapcs1State = digitalRead(kapcs1);
  kapcs2State = digitalRead(kapcs2);
  kapcs3State = digitalRead(kapcs3);
 
  //AnalogRead
  //értek 0-1023 között
 
  //Auto/Bekapcs
  //bekapcsolva?
 
  //int kapcsbe = digitalRead(kapcs3);
  byte bekapcsolva = 0;
  if(kapcs3State == 1){
    if(analogRead(A6)<300){
      bekapcsolva = 1;
    }else{
      bekapcsolva = 0;
    }
  }else{
    bekapcsolva = 1;  
  }
 /*
  Serial.print("fény:");
  Serial.println(analogRead(A6));
  delay(20);
  Serial.print("kapcs1: ");
  Serial.println(kapcs1State);
  delay(20);
  Serial.print("kapcs2: ");
  Serial.println(kapcs2State);
  delay(20);
  Serial.print("kapcs3: ");
  Serial.println(kapcs3State);
  delay(20);
 */
 
  if (kapcs1State == 1) {
    for (int i = 0; i < 9; i++) {
      strip[0].setPixelColor(i, strip[0].Color(index_r, index_g, index_b));
      strip[1].setPixelColor(i, strip[1].Color(index_r, index_g, index_b));
      strip[0].show();
      strip[1].show();
      delay(index_time);
    }
    black(0);
    black(1);
  }else if (kapcs2State == 1) {  //----------------------------------------------------------
    for (int i = 9; i >= 0; i--) {
      strip[0].setPixelColor(i, strip[0].Color(index_r, index_g, index_b));
      strip[1].setPixelColor(i, strip[1].Color(index_r, index_g, index_b));
      strip[0].show();
      strip[1].show();
      delay(index_time);
    }
    black1(0);
    black1(1);
  }else{  //------------------------------------------------------------------------------
    if(bekapcsolva){
      for (int i = 0; i < 9; i++) {
      strip[0].setPixelColor(i, strip[0].Color(100, 100, 100));
      strip[1].setPixelColor(i, strip[1].Color(100, 0, 0));
      }    
      strip[0].show();
      strip[1].show();
    }else{
      black(0);
      black(1);
    }
  }
}
//**********************************************************************
void black(int x) {
  for (int i = 0; i < 9; i++) {
    strip[x].setPixelColor(i, strip[x].Color(0, 0, 0));
  }
  strip[x].show();
}
void black1(int x) {
  for (int i = 9; i >= 0; i--) {
    strip[x].setPixelColor(i, strip[x].Color(0, 0, 0));
  }
  strip[x].show();
}
