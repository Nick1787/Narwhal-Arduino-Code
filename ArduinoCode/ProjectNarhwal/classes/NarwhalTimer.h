/*
 * Timer.h
 *
 * Created: 7/23/2017 8:40:27 PM
 *  Author: Nick1
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "../Main.h"


class NarwhalTimer{
	private:
	unsigned long ellapsedMillis = 0;
	unsigned long lastCallMillis = 0;
	
	public:
	AdjustableParam * TotalTime;
	bool isPaused = true;
	bool expired = false;
	bool reset = false;
	int elapsedSecs;
	int remainingSecs;
	String totalTimeMMSS = "";
	String remainingMMSS = "";
	
	//Constructor
	NarwhalTimer(AdjustableParam *_TotalTime): TotalTime(_TotalTime){};
	
	void init(){
		elapsedSecs = 0;
		remainingSecs = 0;
		lastCallMillis = millis();
	}
	void exec(){
		unsigned long cTime = millis();
		unsigned long deltaMillis = cTime - lastCallMillis;
		lastCallMillis = cTime;
		
		if( reset){
			ellapsedMillis = 0;
			elapsedSecs = 0;
			reset = false;
		}
		
		//If its paused. then add on the delta
		if(!isPaused){
			ellapsedMillis = ellapsedMillis + deltaMillis;
			elapsedSecs = ellapsedMillis/1000;
		}
		
		unsigned int totalSecs = (unsigned int)(TotalTime->getValue() * 60);
		remainingSecs = (totalSecs - elapsedSecs);
		
		if(remainingSecs <=0){
			expired = true;
		}
		totalTimeMMSS = _totalTimeMMSS();
		remainingMMSS = _remainingTimeMMSS();
	}
	
	String _totalTimeMMSS(){
		int totalTimeSecs = 60*(int)(TotalTime->getValue());
		String valueMMStr = String((int)(totalTimeSecs/60));
		String valueSSStr = String(totalTimeSecs);
				
		if(valueMMStr.length() == 1) valueMMStr = "0"+valueMMStr;
		if(valueSSStr.length() == 1) valueSSStr = "0"+valueSSStr;
				
		return  valueMMStr + ":" +  valueSSStr;
	}
	
	String _remainingTimeMMSS(){
		int reamainingMins = (int)(abs(remainingSecs)/60);
		int secs = abs(remainingSecs) % 60;
		bool isNeg = (remainingSecs < 0);
		
		String valueMMStr = String(reamainingMins);
		String valueSSStr = String(secs);	
		
		if(valueMMStr.length() == 1){ valueMMStr = "0"+valueMMStr;}
		if(valueSSStr.length() == 1){ valueSSStr = "0"+valueSSStr;}
		
		if(isNeg){
			return "-" + valueMMStr + ":" +  valueSSStr;
		}else{
			return valueMMStr + ":" +  valueSSStr;
		}
	}
};
		
	
#endif /* TIMER_H_ */