#include <Arduino.h>
#include <Servo.h>
Servo servoMotor;

int lightVal;
int lightResPin=A5;
int servoPin=9;
int del=50;
int angle;

void setup(){
  Serial.begin(9600);
  pinMode(lightResPin, INPUT);
  pinMode(servoPin, OUTPUT);
  servoMotor.attach(servoPin);
}

void loop(){
  lightVal=analogRead(lightResPin);
  Serial.println(lightVal);
  delay(del);
  angle=(-16.0/63.0)*lightVal+16.0*780.0/63.0;
  servoMotor.write(angle);
}