#include <Arduino.h>
#include <Servo.h>
int servoPin=6;
int servoPos=0;
Servo servoMotor;

void setup() {
    Serial.begin(9600);
    servoMotor.attach(servoPin);
    }

void loop() {
    Serial.println("Servo Angle: ");
    while(Serial.available()==0){
    }
    servoPos=Serial.parseInt();
    servoMotor.write(servoPos);
    Serial.println(servoPos);
}