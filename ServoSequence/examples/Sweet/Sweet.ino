#include <ServoSequence.h>
ServoSequence servo;

void setup() {
  servo.add(0,2000);
  servo.add(180,2000);
  servo.Init(2);
}

void loop(){
  servo.Check();
}