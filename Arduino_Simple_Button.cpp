#include <Arduino.h>

int buttonPin=3;
int buttonVal;
int del=500;

void setup(){
    Serial.begin(9600);
    pinMode(buttonPin, INPUT);
    digitalWrite(buttonPin, HIGH);
}

void loop(){
    buttonVal=digitalRead(buttonPin);
    Serial.println("Button: ");
    Serial.println(buttonVal);
    delay(del);
}
