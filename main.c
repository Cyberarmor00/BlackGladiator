#include <AFMotor.h>
#include <Arduino.h>
#include <Wire.h>

AF_DCMotor motorright(3);//rechter Motor
AF_DCMotor motorleft(4);//Linker Motor
int echo=7;
int trigger=6;
int x=0;
int y=0;
int i=0;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  motorright.setSpeed(255);
  motorleft.setSpeed(255);
}

int Messung(){
  digitalWrite(trigger,HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  int time=pulseIn(echo,HIGH); //Zeitmessung von absenden mit Empfang des Signals
  int Entfernung=(time/2)*0.03432;
  return Entfernung;
}

//Vorwärtsfahren gem Dauer
int vorwaerts(int x){
  motorright.run(FORWARD);
  motorleft.run(FORWARD);
  delay(x);
}

//Rückwärtsfahren gem Dauer
int rueckwaerts(int x){
  motorright.run(BACKWARD);
  motorleft.run(BACKWARD);
  delay(x);
}

//Rechtskurve
int kurverechts(int y){
  motorleft.run(FORWARD);
  motorright.run(BACKWARD);
  delay(y);
  motorleft.run(RELEASE);
  motorright.run(RELEASE);
  delay(100);
}

//Linkskurve
int kurvelinks(int y){
  motorright.run(FORWARD);
  motorleft.run(BACKWARD);
  delay(y);
  motorright.run(RELEASE);
  motorleft.run(RELEASE);
  delay(100);
}

void loop() {
  vorwaerts(100);
  if (Messung<20){
    motorleft.run(RELEASE);
    motorright.run(RELEASE);
    kurverechts(1500);
  for (int i=0; i=3; i++){
      vorwaerts(100);
      kurverechts(1000);
    }
  }
}
