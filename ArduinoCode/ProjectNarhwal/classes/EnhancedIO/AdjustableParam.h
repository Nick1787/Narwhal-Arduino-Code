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

template<typename t>
class AdjustableParam
{
//variables
public:
	//Handling Values
	void increment(){
		Value = Value + incr;
	}
	void decrement(){
		Value = Value - incr;
	}
	t getAdjValue(){
		return Value;
	}
	t getValue(){
		return *refParam;
	};
	void set(){
		*refParam = Value;
	}
	
	
protected:
private:
	t *refParam = NULL;
	t maxValue;
	t minValue;
	t incr;
	t Value;

//functions
public:
	AdjustableParam(t *refParam, t minValue, t maxValue, t incr);
	~AdjustableParam();
	
protected:
private:
	AdjustableParam( const AdjustableParam &c );
	AdjustableParam& operator=( const AdjustableParam &c );

}; //AdjustableParam

#endif //__ADJUSTABLEPARAM_H__
