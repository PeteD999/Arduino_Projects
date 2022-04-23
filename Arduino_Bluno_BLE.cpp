#include <Arduino.h>
byte BT;
const byte led=13;

void setup(){
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop(){
  while(Serial.available()){
    BT=Serial.read();
  }
  if(BT=='6'){
    digitalWrite(led, HIGH);
  }
  if(BT=='7'){
    digitalWrite(led, LOW);
  }
}