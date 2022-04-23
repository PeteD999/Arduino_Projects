#include <Arduino.h>
#include <SPI.h>
#include <TMC26XStepper.h>

//we have a stepper motor with 200 steps per rotation,CS pin 6, dir pin 4, step pin 5 and a current of 800mA
TMC26XStepper tmc26XStepper = TMC26XStepper(200,6,4,5,800);
void setup() {
    Serial.begin(9600);
    Serial.println("==============================");
    Serial.println("TMC26X Stepper Driver Demo App");
    Serial.println("==============================");
    //set this according to you stepper
    Serial.println("Configuring stepper driver");
    //char constant_off_time, char blank_time, char hysteresis_start, char hysteresis_end, char hysteresis_decrement
    tmc26XStepper.setSpreadCycleChopper(2,24,8,6,0);
    tmc26XStepper.setRandomOffTime(0);
    tmc26XStepper.SPI_setCoilCurrent(100);
    tmc26XStepper.setMicrosteps(128);
    tmc26XStepper.setStallGuardThreshold(4,0);
    Serial.println("config finished, starting");
    Serial.println("started");

      tmc26XStepper.SPI_setSpeed(80);    //Set speed at 80 RPM
      tmc26XStepper.SPI_step(-200);       //set step at -200 steps,  that is to say stepper will turn a circle reverse
      tmc26XStepper.spi_start() ;         //start stepper
      delay(2000);                         //delay 2s


      tmc26XStepper.SPI_step(200);       // set step at 200 steps,  stepper will turn a circle forward
      tmc26XStepper.spi_start() ;
      delay(2000);

      tmc26XStepper.SPI_setSpeed(100);   // Set speed at 100 RPM
   tmc26XStepper.SPI_step(-300);       // stepper will turn 1.5 circles reverse
      tmc26XStepper.spi_start() ;
      delay(2000);

     tmc26XStepper.SPI_setSpeed(120);   // Set speed at 120 RPM
     tmc26XStepper.SPI_step(400);       // stepper will turn 2 circles forward
     tmc26XStepper.spi_start() ;
     delay(3000);



}
void loop() {


          //you can put stepper control code in loop{} to make stepper works circularly
}