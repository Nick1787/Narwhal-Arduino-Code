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

class DS323RealTimeClock{
	private:
		const int i2cAddress = 0;
		
		// Convert normal decimal numbers to binary coded decimal
		byte decToBcd(byte val){ return( (val/10*16) + (val%10) );	};
		
		// Convert binary coded decimal to normal decimal numbers
		byte bcdToDec(byte val){ return( (val/16*10) + (val%16) );	};
		
		//Read date and time
		void readDateTime(byte *second, byte *minute,	byte *hour,	byte *dayOfWeek, byte *dayOfMonth,	byte *month,	byte *year)
		{
			Wire.beginTransmission(i2cAddress);
			Wire.write(0); // set DS3231 register pointer to 00h
			Wire.endTransmission();
			Wire.requestFrom(i2cAddress, 7);
			// request seven bytes of data from DS3231 starting from register 00h
			*second = bcdToDec(Wire.read() & 0x7f);
			*minute = bcdToDec(Wire.read());
			*hour = bcdToDec(Wire.read() & 0x3f);
			*dayOfWeek = bcdToDec(Wire.read());
			*dayOfMonth = bcdToDec(Wire.read());
			*month = bcdToDec(Wire.read());
			*year = bcdToDec(Wire.read());
		};
		
	public:
		enum DateStampFormat{ YYYYMMDD, YYMMDD, MMDDYY, MMDDYYYY, MMDD };
		enum TimeStampFormat{ HHMM, HHMMSS };
			
		//Constructors
		DS323RealTimeClock(int address): i2cAddress(address){};
		~DS323RealTimeClock(){};
			
		String getDateStamp(){
			byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
			readDateTime(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
			
			return  String(year) + String(month) + String(dayOfMonth);
		}
			
};

#endif /* DS323REALTIMECLOCK_H_ */