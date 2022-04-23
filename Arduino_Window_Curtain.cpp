// Room Window BLE Stepper Operation

#include <Arduino.h>
#include <Stepper.h>
#define stepRev 200  // Number of Steps per revolution of Stepper Motor
#define IN1 4  // Stepper Input 1-4 with digital pin 8-11
#define IN2 7
#define IN3 8
#define IN4 11
Stepper motor=Stepper(stepRev, IN1, IN2, IN3, IN4); //Stepper Library Steps per Revolution with Input 1-4
char BLE;  // Define BLE module name
const int speed=240;  // Set Stepper speed in RPM
int step=6700;  // Set number of steps for Stepper motor rotation
unsigned long prevMil0;  // Millis function for blinking LED
unsigned long interval0=3000;
unsigned long prevMil1;
unsigned long interval1=300;
const byte led=13;  // Board LED set for digital pin 13
const int del=1000;

void setup(){
  Serial.begin(115200);  // Set baud rate to 115200
  pinMode(led, OUTPUT);
}

void loop(){
  while(Serial.available()){
    BLE=Serial.read();  // BLE Serial Read
  }
    if(BLE=='6'){
      motor.setSpeed(speed);
      motor.step(step+35);
      motor.step(0);
      delay(del);
      digitalWrite(IN1, LOW); //Setting State of digital pins to LOW reducing current & heat from Stepper Controller
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }

    if(BLE=='7'){
      motor.setSpeed(speed);
      motor.step(-step);
      motor.step(0);
      delay(del);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }

    if(BLE=='8'){
      motor.setSpeed(speed);
      motor.step((step/4));
      motor.step(0);
      delay(del);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }

    if(BLE=='9'){
      motor.setSpeed(speed);
      motor.step((-step/4));
      motor.step(0);
      delay(del);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    
  unsigned long currentMil=millis();  // Millis blink function Blinking LED on for 300 Mil seconds and off for 5 seconds
  if(currentMil-prevMil0>interval0){
    digitalWrite(led, HIGH);
    prevMil0=currentMil;
  }
  if(currentMil-prevMil1>interval1){
    digitalWrite(led, LOW);
    prevMil1=currentMil;
  }
}