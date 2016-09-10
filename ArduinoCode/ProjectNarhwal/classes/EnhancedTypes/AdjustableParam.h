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
protected:
private:
	t *_refParam = NULL;
	t _maxValue;
	t _minValue;
	t _incr;

//functions
public:
	AdjustableParam(t *refParam, t minValue, t maxValue, t incr): _refParam(refParam), _minValue(minValue), _maxValue(maxValue), _incr(incr){};
	~AdjustableParam(){};
	
	//Handling Values
	void incr(){ 
		if(*_refParam > _maxValue){
			*_refParam = _maxValue;
		}else{
			*_refParam += incr;
		}
	};
	void decr(){
		if(*_refParam < _minValue){
			*_refParam = _minValue;
		}else{
			*_refParam -= incr;
		}
	};
	void incrLarge(){
		if(*_refParam > _maxValue){
			*_refParam = _maxValue;
		}else{
			*_refParam += 10*incr;
		}
	};
	void decrLarge(){
		if(*_refParam < _minValue){
			*_refParam = _minValue;
		}else{
			*_refParam -= 10*incr;
		}
	};
	t getValue(){return *_refParam;};
	void set(t Value){*_refParam = Value; incr(); decr();};
	
protected:
private:
	AdjustableParam( const AdjustableParam &c );
	AdjustableParam& operator=( const AdjustableParam &c );

}; //AdjustableParam

#endif //__ADJUSTABLEPARAM_H__
