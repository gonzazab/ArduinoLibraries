#include <ServoEasy.h>

ServoEasy myservo;

cont int timeTransition= 2000;    // variable to store the servo position

void setup() {
  myservo.Init(2,0,timeTransition);		// myservo.Init(pin,angleInit,timeTransition)
}

void loop() {
  myservo.SetSetpoint(0);
  Delay(timeTransition);
  myservo.SetSetpoint(180);
  Delay(timeTransition);
}

void _loop(){
  myservo.Check();
}

void Delay(unsigned long time){
  unsigned long _tant=millis();
  while(millis()-_tant<time){
    _loop();
    delay(1);
  }
}