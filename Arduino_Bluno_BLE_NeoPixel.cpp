#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define ledNum 194
#define ledPin 3
Adafruit_NeoPixel ledStrip(ledNum, ledPin, NEO_GRB + NEO_KHZ800);
//blue, green and red; brightness level for each led in the strip starting at the following values
int blue=10;
int green=158;
int red=10;
int red1=160;
//level of fade amount
int bfade=1;
int gfade=1;
int rfade=1;
int colorFade=1;
boolean colorSwitch=0;
//starting position of the led strip, starting a 0
int ledPos=0;
int ledFade=1;
//assigning ble as BT and the state of each button
char BT;
byte BTState=0;
//interval of 20 millisec in our millis statement
unsigned long interval=20;
unsigned long interval1=9999;
unsigned long prevMil=0;
unsigned long prevMil1=0;

void setup(){
  Serial.begin(115200);
  ledStrip.begin();
}

void loop(){
  //Checking for serial and reading given value of each state
  //millis loop in each statement
  while(Serial.available()){
    BT=Serial.read();
  }
  //BTState 1 is the state of blue and green cycle
  if(BT==10){
    BTState=1;
  }
  //BTState 2 is the state of blue and red cycle
  if(BT==11){
    BTState=2;
  }
  //BTState 3 is the state of rainbow cycle
  if(BT==12){
    BTState=3; 
  }
  //BTState 4 is the state of white light
  if(BT==13){
    BTState=4;
  }
  //BTState 5 is the off state
  if(BT=='7'){
    BTState=5;
  }
  if(BTState==1){
    unsigned long currentMil=millis();
    if(currentMil-prevMil>=interval){
      prevMil=currentMil;
      blue=blue+bfade;
      green=green+gfade;
      ledPos=ledPos+ledFade;
      if(blue<=10 || blue>=160){
        bfade=-bfade;
      }
      if(green<=10 || green>=190){
        gfade=-gfade;
      }
      if(ledPos<=0 || ledPos>=194){
        ledFade=-ledFade;
      }
      ledStrip.setPixelColor(ledPos, ledStrip.Color(0, green, blue));
      ledStrip.show();
    }
  }
  if(BTState==2){
    unsigned long currentMil=millis();
    if(currentMil-prevMil>=interval){
      prevMil=currentMil;
      blue=blue+bfade;
      red=red+rfade;
      ledPos=ledPos+ledFade;
      if(blue<=10 || blue>=160){
        bfade=-bfade;
      }
      if(red<=10 || red>=190){
        rfade=-rfade;
      }
      if(ledPos<=0 || ledPos>=194){
        ledFade=-ledFade;
      }
      ledStrip.setPixelColor(ledPos, ledStrip.Color(red, 0, blue));
      ledStrip.show();
    }
  }
  if(BTState==3){
    unsigned long currentMil1=millis();
    if(currentMil1-prevMil1>=interval1){
      prevMil1=currentMil1;
      colorSwitch=colorSwitch+colorFade;
      if(colorSwitch<=0 || colorSwitch>=1){
        colorFade=-colorFade;
      }
      Serial.println(colorSwitch);
    }
      if(colorSwitch==0){
        unsigned long currentMil=millis();
        if(currentMil-prevMil>=interval){
          prevMil=currentMil;
          blue=blue+bfade;
          green=green+gfade;
          ledPos=ledPos+ledFade;
          if(blue<=10 || blue>=160){
            bfade=-bfade;
          }
          if(green<=10 || green>=190){
            gfade=-gfade;
          }
          if(ledPos<=0 || ledPos>=194){
            ledFade=-ledFade;
          }
          ledStrip.setPixelColor(ledPos, ledStrip.Color(0, green, blue));
          ledStrip.show();
        }
      }
      if(colorSwitch==1){
        unsigned long currentMil=millis();
        if(currentMil-prevMil>=interval){
          prevMil=currentMil;
          blue=blue+bfade;
          red=red+rfade;
          ledPos=ledPos+ledFade;
          if(blue<=10 || blue>=160){
            bfade=-bfade;
          }
          if(red<=10 || red>=190){
            rfade=-rfade;
          }
          if(ledPos<=0 || ledPos>=194){
            ledFade=-ledFade;
          }
          ledStrip.setPixelColor(ledPos, ledStrip.Color(red, 0, blue));
          ledStrip.show();
        }
      }
  }
  if(BTState==4){
    unsigned long currentMil=millis();
    if(currentMil-prevMil>=interval){
      prevMil=currentMil;
      red1=red1+rfade;
      ledPos=ledPos+ledFade;
      if(red1<=130 || red1>=210){
        rfade=-rfade;
      }
      if(ledPos<=0 || ledPos>=194){
        ledFade=-ledFade;
      }
      ledStrip.setPixelColor(ledPos, ledStrip.Color(red1, 30, 0));
      ledStrip.show();
    }
  }
  if(BTState==5){
    unsigned long currentMil=millis();
    if(currentMil-prevMil>=interval){
      prevMil=currentMil;
      ledPos=ledPos+ledFade;
      if(ledPos<=0 || ledPos>=194){
        ledFade=-ledFade;
      }
      ledStrip.setPixelColor(ledPos, ledStrip.Color(0, 0, 0));
      ledStrip.show();
    }
  }
}