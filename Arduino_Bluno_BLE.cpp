#include <Arduino.h>
byte BLE;
const byte led=13;

void setup(){
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop(){
  while(Serial.available()){
    BLE=Serial.read();
  }
  if(BLE=='1'){
    digitalWrite(led, HIGH);
  }
  if(BLE=='0'){
    digitalWrite(led, LOW);
  }
}
