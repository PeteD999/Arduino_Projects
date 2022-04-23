// Millis Example Code, LED State ON & OFF

#include <Arduino.h>
int ledPin=13;
boolean ledState=false;             
unsigned long prevMil=0;
unsigned long ledDelay=200;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
    unsigned long currentMil=millis();
  if (currentMil-prevMil>=ledDelay){
      prevMil=currentMil;
    if (ledState==0) {
      ledState=1;
    } 
    else {
      ledState=0;
    }
    digitalWrite(ledPin, ledState);
  }
}