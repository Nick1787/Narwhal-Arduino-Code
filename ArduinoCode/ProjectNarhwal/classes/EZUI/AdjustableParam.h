/*
 *        File: AdjustableParam.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: A class for adjustable parameters
 * ----------------------------------------------------------------
 *    Revision:
 *		06092016 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __ADJUSTABLEPARAM_H__
#define __ADJUSTABLEPARAM_H__

#include<Arduino.h>

class AdjustableParam
{
//variables
public:

	//Min-Max-Increment
	const PROGMEM float maxValue = -1;
	const PROGMEM float minValue = -1;
	const PROGMEM float increment = -1;
	float value = NULL;

protected:
private:

//functions
public:
	AdjustableParam(float defaultVal, float mnValue, float mxValue, float incr): value(defaultVal), minValue(mnValue), maxValue(mxValue), increment(incr){};
	~AdjustableParam(){};
	
	
	//Values
	float getValue(){ return value;};
	void set(float _value){
		if(value > maxValue){
			value = maxValue; 
		}else if(value < minValue){
			value = minValue;
		}else{
			value = _value;
		}
	};
		
	//Value Text - Overrides
	String valueText()   {	return String(value); };
	String minVaueText() {	return String( minValue  ); };
	String maxVaueText() {	return String( maxValue  ); };
	float pctOfMinMax()  {
		return 100*(getValue() - minValue) / (maxValue-minValue);
	};
		
	//Increment / Decrement - Overrides
	void incr() 	{ set( value + increment ); };
	void decr() 	{ set( value - increment ); };
	void incrBig() 	{ set( value + 10*increment ); };
	void decrBig() 	{ set( value - 10*increment ); };
	
protected:
private:
	//AdjustableParam( const AdjustableParam &c );
	//AdjustableParam& operator=( const AdjustableParam &c );

}; //AdjustableParam

#endif //__ADJUSTABLEPARAM_H__
