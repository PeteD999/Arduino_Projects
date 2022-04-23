#include <Arduino.h>
const int tempPin=A7; // Set pin to analog A7
float temp; //Value of Temperature in Celsius
float sensorVal; // Sesnsor value reading from ananlog Pin 7
float cel; // Value of converted analog Pin into Cel

void setup(){
    Serial.begin(9600); //Baud rate set for (9600)
    pinMode(tempPin, INPUT); // 
}

void loop(){
    sensorVal=analogRead(tempPin);  // Calculation of analog Read converted into Readable tempertature
    temp=(sensorVal/1023.0)*4650;
    cel=temp/10;
    Serial.print("temperature: ");
    Serial.print(cel);
    Serial.println("*C"); // Serial print the temperature in Celsius every 1 Second
    delay(1000);
}