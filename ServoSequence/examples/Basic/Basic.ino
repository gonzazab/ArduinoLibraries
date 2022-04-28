#include "ServoSequence.h"

ServoSequence base;
ServoSequence pie;

void setup() 
{
  Serial.begin(115200);

  base.add(0,2000);
  base.add(90,500);

  pie.add(120,500);
  pie.add(90,1000);
  pie.add(30,500);
  pie.add(90,500);



  base.Init(2);
  pie.Init(3);
  
}

void loop()
{
  base.Check();
  pie.Check();
}


