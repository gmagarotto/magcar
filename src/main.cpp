#include <Arduino.h>
#include <SoftwareSerial.h>

char s;
int  LED = PC13;
int  motorA_CW = PB0;
int  motorA_CCW = PB1;
int  motorB_CW = PB10;
int  motorB_CCW = PB11;

SoftwareSerial mySerial(PA10, PA9);

void setup()
{
  pinMode(motorA_CW,  OUTPUT);
  pinMode(motorA_CCW, OUTPUT); 
  pinMode(motorB_CW,  OUTPUT);
  pinMode(motorB_CCW, OUTPUT);

  mySerial.begin(9600);
}

void loop()
{
  while (!mySerial.available()) {
  }
  
  s = mySerial.read();
  if (s == '1') {
    analogWrite(motorA_CW, 255);
    analogWrite(motorB_CW, 255);
    delay(1000);
    analogWrite(motorA_CW, 0);
    analogWrite(motorB_CW, 0);
  }
  if (s == '2') {
    analogWrite(motorA_CCW, 255);
    analogWrite(motorB_CCW, 255);
    delay(500);
    analogWrite(motorA_CCW, 0);
    analogWrite(motorB_CCW, 0);
  }
  if (s == '4') {
    analogWrite(motorA_CW, 0);
    analogWrite(motorB_CW, 255);
    delay(200);
    analogWrite(motorA_CW, 0);
    analogWrite(motorB_CW, 0);
  }  
  if (s == '3') {
    analogWrite(motorA_CW, 255);
    analogWrite(motorB_CW, 0);
    delay(200);
    analogWrite(motorA_CW, 0);
    analogWrite(motorB_CW, 0);
  }
}
