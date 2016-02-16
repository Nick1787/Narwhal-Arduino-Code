/*
 *        File: AnalogIn.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: AnalogIn - Analog Input with Filtering
 * ----------------------------------------------------------------
 *    Revision:
 *		02162016 - NRD - Initial Version
 * ----------------------------------------------------------------
 */


#ifndef __ANALOGIN_H__
#define __ANALOGIN_H__

#include <Arduino.h>
#include "../../include/LinkedList/LinkedList.h"

class AnalogIn
{
//variables
public:
	unsigned long period = 0;
	enum filterType { None, TimeAverage, TimeMedian };
	filterType filter = None;
	float value;
		
protected:
private:
	unsigned long lastUpdate = 0;
	int pin;
	float vref;

//functions
public:
	void update();
	AnalogIn(int pin, float vref, unsigned long period, filterType filter );
	~AnalogIn();
	
protected:
private:
	LinkedList<int> samples = LinkedList<int>();
	//AnalogIn( const AnalogIn &c );
	//AnalogIn& operator=( const AnalogIn &c );

}; //AnalogIn

#endif //__ANALOGIN_H__
