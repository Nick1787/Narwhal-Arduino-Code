/* 
* DIO.h
*
* Created: 1/4/2016 9:23:18 PM
* Author: Customer
*/


#ifndef __DigIO_H__
#define __DigIO_H__

#include<Arduino.h>

class DigIO
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
	
	DigIO(int Pin, PinModes Mode);
	DigIO(int Pin, PinModes Mode, String TrueLabel, String FalseLabel);
	
	~DigIO();
protected:
private:
	//DigIO( const DigIO &c );
	//DigIO& operator=( const DigIO &c );

}; //DIO

#endif //__DIO_H__
