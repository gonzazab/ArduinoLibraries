#ifndef SERVOEASY_h
#define SERVOEASY_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Servo.h>

class ServoEasy
{

public:
	
	ServoEasy();

	void Init(int pin);
  void Init(int pin,int init);
  void Init(int pin,int init, unsigned long interval);

	float operator = (float value);
	operator float();
	float GetSetpoint(float value);
	float SetSetpoint(float value);
	float GetValue();
  void Check();
	void SetMillisInterval(unsigned long interval);
	void SetMicrosInterval(unsigned long interval);

private:
  float InOutCubic(float t);
	float _startPoint;
	float _setPoint;
	float _currentValue;
	unsigned long _startTime;
	unsigned long _easyDuration = 1000000;
	bool _active;
  Servo _servo;


};

#endif

