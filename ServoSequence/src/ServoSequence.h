#ifndef SERVOSEQUENCE_h
#define SERVOSEQUENCE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <ServoEasy.h>

#define MAX_SEQUENCE 50

class ServoSequence
{

public:
	
	ServoSequence();
  ServoSequence(bool continuous);

	void Init(int pin);
  void Check();
	void add(float position,unsigned long interval);
  void clear();
  void setContinuous(bool state);

private:
  int _maxPosition;
  int _nowPosition;
  float _positions[MAX_SEQUENCE];
  unsigned long _intervals[MAX_SEQUENCE];
  unsigned long _nextTime;
  bool _continuous;
  ServoEasy _servo;


};

#endif

