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
protected:
private:
	float _value = NULL;

//functions
public:
	AdjustableParam(float defaultVal, float minValue, float maxValue, float increment): _value(defaultVal), minValue(minValue), maxValue(maxValue), increment(increment){};
	~AdjustableParam(){};
	
	//Min-Max-Increment
	const float maxValue;
	const float minValue;
	const float increment;
	
	//Values
	float getValue(){return _value;};
	void set(float value){
		if(value > maxValue){
			_value = maxValue; 
		}else if(value < minValue){
			_value = minValue;
		}else{
			_value = value;
		}
	};
		
	//Value Text - Overrides
	String valueText()   {	return String( getValue() ); };
	String minVaueText() {	return String( minValue  ); };
	String maxVaueText() {	return String( maxValue  ); };
	float pctOfMinMax()  {
		return 100*(getValue() - minValue) / (maxValue-minValue);
	};
		
	//Increment / Decrement - Overrides
	void incr() 	{ set( getValue() + increment ); };
	void decr() 	{ set( getValue() - increment ); };
	void incrBig() 	{ set( getValue() + 10*increment ); };
	void decrBig() 	{ set( getValue() - 10*increment ); };
	
protected:
private:
	//AdjustableParam( const AdjustableParam &c );
	//AdjustableParam& operator=( const AdjustableParam &c );

}; //AdjustableParam

#endif //__ADJUSTABLEPARAM_H__
