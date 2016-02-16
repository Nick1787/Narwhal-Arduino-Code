/*
 *        File: DigitalIO.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Digital IO - State class for Digital IO interface
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __DigitalIO_H__
#define __DigitalIO_H__

#include<Arduino.h>

class DigitalIO
{
//variables
public:
	int Pin = -1;
	enum PinModes {IN, OUT, IN_PULLUP};
	PinModes Mode = IN;	
	String TrueLabel = "true";
	String FalseLabel = "false";
	
protected:
	
private:
	int _value;
	
//functions
public:
	int Value(void);
	PinModes GetMode(void);
	void SetMode(PinModes Mode);
	void Write(int value);
	
	DigitalIO(int Pin, PinModes Mode);
	DigitalIO(int Pin, PinModes Mode, String TrueLabel, String FalseLabel);
	
	~DigitalIO();
	
protected:
private:

}; //DIO

#endif //__DIO_H__
