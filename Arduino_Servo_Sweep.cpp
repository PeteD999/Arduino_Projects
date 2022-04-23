#include <Arduino.h>
#include <Servo.h>
Servo servoMotor;
int servoPin=6;
int servoPos=0;
int del0=55;
int del1=55;

void setup(){
  Serial.begin(9600);
  servoMotor.attach(servoPin);
}

void loop(){
  for(servoPos=0; servoPos<=180; servoPos+=1){
    servoMotor.write(servoPos);
    delay(del0);
  }
  for(servoPos=180; servoPos>=0; servoPos-=1){
    servoMotor.write(servoPos);
    delay(del1);
  }
}