#include <Arduino.h>

void setup(){
    Serial.begin(115200);
    randomSeed(analogRead(0));
}

void loop(){
    analogWrite(3, random(255));
    delay(100);
}