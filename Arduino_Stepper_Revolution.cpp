#include <Arduino.h>
#include <Stepper.h>
const int stepsPerRevolution=200;
int speed=60;
Stepper stepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  Serial.begin(9600); // initialize the serial port:
}

void loop() {
  Serial.println("clockwise"); // Amount of total stps in clockwise direction
  stepper.step(stepsPerRevolution); // Speed for stepper 
  stepper.setSpeed(speed);
  delay(500);

  Serial.println("counterclockwise"); // Amount of steps in counter clockwise direction
  stepper.step(-stepsPerRevolution); //Speed for stepper  
  stepper.setSpeed(speed);
  delay(500);
}