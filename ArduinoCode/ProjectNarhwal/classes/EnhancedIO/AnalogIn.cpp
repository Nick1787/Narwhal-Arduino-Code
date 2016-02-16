/*
 *        File: AnalogIn.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: AnalogIn - Analog Input with Filtering
 * ----------------------------------------------------------------
 *    Revision:
 *		02162016 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "AnalogIn.h"

// default constructor
AnalogIn::AnalogIn(int pin, float vref, unsigned long period, filterType filter )
{
	this->pin = pin;
	this->vref = vref;
	this->period = period;
	this->filter = filter;
} //AnalogIn


void AnalogIn::update(){
	if(this->filter == None){
		value = analogRead(pin)*(vref/1023.0);
	}else{
		samples.add(analogRead(pin));
		
		//If Filtering, see if filter period passed and then calculate filtered value;
		if((millis() - lastUpdate) > period){
			if( this->filter == TimeAverage){
				float temp_val = 0;
				for( int i=0; i<samples.size(); i++){
					temp_val += samples.get(i)*(vref/1023.0)*(1/period);
				}
				value=temp_val;
			}else if( this->filter == TimeMedian ){
				value = samples.get((int)(samples.size()/2))*(vref/1023.0);
			}
			
			samples.clear();
		}
	}
}

// default destructor
AnalogIn::~AnalogIn()
{
} //~AnalogIn
