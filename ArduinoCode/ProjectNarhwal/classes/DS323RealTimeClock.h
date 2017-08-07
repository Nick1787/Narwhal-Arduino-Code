/*
 * DS323RealTimeClock.h
 *
 * Created: 12/11/2016 3:46:23 PM
 *  Author: Nick1
 */ 


#ifndef DS323REALTIMECLOCK_H_
#define DS323REALTIMECLOCK_H_

#include <Wire.h>
#include <Arduino.h>
#include "../include/ds3231/ds3231.h"

class DS323RealTimeClock{
	private:
		bool initComplete  = false;
		const int i2cAddress = 0;
		
		float _RTC_second = 0;
		float _RTC_minute = 0;
		float _RTC_hour = 0;
		float _RTC_weekday = 0;
		float _RTC_day = 0;
		float _RTC_month = 0;
		float _RTC_year = 0;
	public:
		AdjustableParam *Second;
		AdjustableParam *Minute;
		AdjustableParam *Hour;
		AdjustableParam *Day;
		AdjustableParam *Month;
		AdjustableParam *Year;
			
		enum DateStampFormat{ YYYYMMDD, YYMMDD, MMDDYY, MMDDYYYY, MMDD, DATETIME };
		enum TimeStampFormat{ HHMM, HHMMSS };
			
		//Constructors
		DS323RealTimeClock(int address, AdjustableParam *_Second, AdjustableParam *_Minute,AdjustableParam *_Hour,AdjustableParam *_Day,AdjustableParam *_Month,AdjustableParam *_Year): i2cAddress(address), Second(_Second), Minute(_Minute),Hour(_Hour),Day(_Day),Month(_Month),Year(_Year){};
		~DS323RealTimeClock(){};
		
		//Functions
		void init(){
			
			//Init the RTC
			DS3231_init(i2cAddress);
			exec();
		}
		
		void exec(){
			boolean userChanged = false;
			ts t_str;
			DS3231_get(&t_str);			
			_RTC_weekday = (float)t_str.wday;
			
			//-Seconds
			if(!initComplete){
				_RTC_second = (float)t_str.sec;
				Second->set(_RTC_second);
			}else{
				if(Second->getValue() != _RTC_second){
					//User changed value, use the users value
					_RTC_second = Second->getValue();
					userChanged = true;
					t_str.sec = (uint8_t)_RTC_second;
				}else{
					//Value changed on own, use the RTC value
					_RTC_second = (float)t_str.sec;
					Second->set(_RTC_second);
				}
			}
					
			//-Minutes
			if(!initComplete){
				_RTC_minute = (float)t_str.min;
				Minute->set(_RTC_minute);
			}else{
				if(Minute->getValue() != _RTC_minute){
				//User changed value, use the users value
					_RTC_minute = Minute->getValue();
					userChanged = true;
					t_str.min = (uint8_t)_RTC_minute;
				}else{
					//Value changed on own, use the RTC value
					_RTC_minute = (float)t_str.min;
					Minute->set(_RTC_minute);
				}
			}
			
			//-Hour
			if(!initComplete){
				_RTC_hour = (float)t_str.hour;
				Hour->set(_RTC_hour);
			}else{
				if (Hour->getValue() != _RTC_hour){
					//User changed value, use the users value
					_RTC_hour = Hour->getValue();
					userChanged = true;
					t_str.hour = (uint8_t)_RTC_hour;
				}else{
					//Value changed on own, use the RTC value
					_RTC_hour = (float)t_str.hour;
					Hour->set(_RTC_hour);
				}
			}
			
			//-Day
			if(!initComplete){
				_RTC_day = (float)t_str.mday;
				Day->set(_RTC_day);
			}else{
				if(Day->getValue() != _RTC_day){
					//User changed value, use the users value
					_RTC_day = Day->getValue();
					userChanged = true;
					t_str.mday = (uint8_t)_RTC_day;
				}else{
					//Value changed on own, use the RTC value
					_RTC_day = (float)t_str.mday;
					Day->set(_RTC_day);
				}
			}
			
			//-Month
			if(!initComplete){
				_RTC_month = (float)t_str.mon;
				Month->set(_RTC_month);
			}else{
				if(Month->getValue() != _RTC_month){
					//User changed value, use the users value
					_RTC_month = Month->getValue();
					userChanged = true;
					t_str.mon = (uint8_t)_RTC_month;
				}else{
					//Value changed on own, use the RTC value
					_RTC_month = (float)t_str.mon;
					Month->set(_RTC_month);
				}
			}
			
			//-Year
			if(!initComplete){
				_RTC_year = (float)t_str.year;
				Year->set(_RTC_year);
			}else{
				if(Year->getValue() != _RTC_year){								
					//User changed value, use the users value
					_RTC_year = Year->getValue();
					userChanged = true;
					t_str.year = (uint8_t)_RTC_year;

				}else{
					//Value changed on own, use the RTC value
					_RTC_year = (float)t_str.year;
					Year->set(_RTC_year);
				}
			}
			
			initComplete = true;
			
			if(userChanged){
				#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>3)
					Serial.print(F(" Setting Date Time - "));
					Serial.print(t_str.mon);
					Serial.print(F("/"));
					Serial.print(t_str.mday);
					Serial.print(F("/"));
					Serial.print(t_str.year);
					Serial.print(F(" "));
					Serial.print(t_str.hour);
					Serial.print(F(":"));
					Serial.print(t_str.min);
					Serial.print(F(":"));
					Serial.println(t_str.sec);
				#endif
				DS3231_set(t_str);
			}
		}
		
		
		String getDateStamp(DateStampFormat format){
			ts t_str;
			DS3231_get(&t_str);
			String year = String((int)t_str.year);
			String mon = String((int)t_str.mon);
			String mday = String((int)t_str.mday);
			String hour = String((int)t_str.hour);
			int Hr12 = (int)(t_str.hour % 12);
			if(Hr12 ==0){ Hr12 = 12;}
			String hour12 = String(Hr12);
			String min = String((int)t_str.min);
			String sec = String((int)t_str.sec);
				
			if(mon.length() == 1) mon = "0"+mon;
			if(mday.length() == 1) mday = "0"+mday;
			if(hour.length() == 1) hour = "0"+hour;
			if(hour12.length() == 1) hour12 = "0"+hour12;
			if(min.length() == 1) min = "0"+min;
			if(sec.length() == 1) sec = "0"+sec;
						
			if( format == YYYYMMDD){
				return year + mon + mday;
				
			}else if( format == DATETIME){
				return mon + "/" + mday + "/" +  year + " " + hour12 + ":" + min ;
			}
			
		}
			
};

#endif /* DS323REALTIMECLOCK_H_ */