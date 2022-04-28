#include "ServoSequence.h"

ServoSequence::ServoSequence()
{
  _maxPosition=0;
  _nowPosition=0;
  _nextTime = 0;
	_continuous = true;
}

ServoSequence::ServoSequence(bool continuous)
{
  _maxPosition=0;
  _nowPosition=0;
  _nextTime = 0;
	_continuous = continuous;
}

void ServoSequence::Init(int pin)
{

  _nowPosition=0;
  _servo.Init(pin,_positions[0]);
  _servo.SetMillisInterval(_intervals[0]);
  _nextTime=millis() + _intervals[0];
}

void ServoSequence::clear()
{
  _nowPosition=0;
  _maxPosition=0;
  _continuous=false;
}

void ServoSequence::setContinuous(bool state)
{
  _continuous=state;
}



void ServoSequence::add(float position,unsigned long interval)
{
  if(_maxPosition>=MAX_SEQUENCE)_maxPosition=0;

	_positions[_maxPosition] = position;
  _intervals[_maxPosition] = interval;
  _maxPosition++;
}

void ServoSequence::Check()
{
  _servo.Check();
  
  if(_nowPosition==_maxPosition && !_continuous) {
    return;
  }
  if(millis() > _nextTime){
    _nowPosition++;
    if(_nowPosition>=_maxPosition) {
      if(_continuous)_nowPosition=0;
      else return;
    }
    _nextTime = millis() + _intervals[_nowPosition];
    _servo.SetMillisInterval(_intervals[_nowPosition]);
    _servo.SetSetpoint(_positions[_nowPosition]);
  }
  
}
