#include "ServoEasy.h"

ServoEasy::ServoEasy()
{
	_startPoint = 0;
	_setPoint = 0;
	_active = false;
	_easyDuration = 1000000;
}

void ServoEasy::Init(int pin)
{
  Init(pin,0,1000000);
}

void ServoEasy::Init(int pin,int init)
{
  Init(pin,init,1000000);
}

void ServoEasy::Init(int pin,int init, unsigned long interval)
{
	_setPoint = init;
	_startPoint =init;
	_currentValue = init;
  _easyDuration = interval*1000 ;
  _servo.attach(pin);
  _servo.writeMicroseconds(1000.0+init*1000.0/180.0);
}

float ServoEasy::operator=(float value)
{
	return SetSetpoint(value);
}

ServoEasy::operator float()
{
	return GetValue();
}

float ServoEasy::GetSetpoint(float value)
{
	return _setPoint;
}

float ServoEasy::SetSetpoint(float value)
{
	if (value == _setPoint) return GetValue();

	_setPoint = value;
	_startPoint = _currentValue;
	_startTime = micros();
	_active = true;
	return _currentValue;
}

float ServoEasy::GetValue()
{
	if (!_active) return _currentValue;

	unsigned long elapsedTime = micros() - _startTime;
	if (elapsedTime >= _easyDuration)
	{
		_active = false;
		_startPoint = _setPoint;
		_currentValue = _setPoint;
		return _currentValue;
	}

	float t = static_cast<float>(elapsedTime) / _easyDuration;
	_currentValue = (_setPoint - _startPoint) * InOutCubic(t) + _startPoint;
  return _currentValue;
}

void ServoEasy::Check()
{

_servo.writeMicroseconds(1000.0+GetValue()*1000.0/180.0);
}

float ServoEasy::InOutCubic(float t) {
  return t < .5 ? 4 * t * t * t : (t - 1) * (2 * t - 2) * (2 * t - 2) + 1; 
};