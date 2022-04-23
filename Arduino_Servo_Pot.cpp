#include <Arduino.h>
#include <Servo.h>

int servoPin=9;
Servo servoMotor;
int potVal;
int potPin=A5;

void setup(){
    Serial.begin(9600);
    servoMotor.attach(servoPin);
    pinMode(potPin, INPUT);
}

void loop(){
    potVal=analogRead(potPin);
    potVal=map(potVal, 0, 1023, 0, 180);
    servoMotor.write(potVal);
}