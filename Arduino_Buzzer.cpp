#include <Arduino.h>
const int buzzer=12;
int del=75;

void setup(){
    pinMode(buzzer, OUTPUT);
}

void loop(){
    tone(buzzer, 2600);
    delay(del);
    noTone(buzzer);
    delay(del);
    tone(buzzer, 2600);
    delay(del);
    noTone(buzzer);
    delay(del);
    tone(buzzer, 3100);
    delay(del);
    noTone(buzzer);
    delay(10000);
}