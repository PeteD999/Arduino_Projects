#include <Arduino.h>
#include <Servo.h>
Servo servoMotor;

int servoPin=6;
int servoPos;
int potVal;
int potPin=A4;
unsigned long prevMil0=0;
unsigned long prevMil01=0;
unsigned long interVal0=500;
unsigned long prevMil1=0;
unsigned long interVal1=1000;
unsigned long interval01=50;
int led0=13;
int led1=10;
boolean ledState0=false;
boolean ledState1=false;
boolean ledState01= false;

void setup(){
   pinMode(led0, OUTPUT);
   pinMode(led1, OUTPUT);
   pinMode(potPin, INPUT);
   servoMotor.attach(servoPin);
}

void loop(){
   unsigned long currentMil=millis();
   potVal=analogRead(potPin);
   potVal=map(potVal, 0, 920, 0, 180);
   if(currentMil-prevMil0>interVal0){
      digitalWrite(led0, ledState0);
      prevMil0=currentMil;
      ledState0=!ledState0;
   }
   if(currentMil-prevMil01>interval01){
      digitalWrite(led1, LOW);      
      prevMil01=currentMil;
      ledState01=!ledState01;
   }
   if(currentMil-prevMil1>interVal1){
      digitalWrite(led1, ledState1);
      prevMil1=currentMil;
      ledState1=!ledState1;
   }
   servoMotor.write(potVal);
}