/* 
* DataLogger.h
*
* Created: 11/30/2016 11:07:22 PM
* Author: Nick1
*/


#ifndef __DATALOGGER_H__
#define __DATALOGGER_H__

#include "SDDataLogger.h"
#include "DS323RealTimeClock.h"

template <unsigned int Size>
class DataLogger: public SDDataLogger<Size>{
	private:
		DS323RealTimeClock * RTC;
		boolean prevRunState = false;
		unsigned int logStartTimeMillis = 0;
		unsigned int lastRecordMillis = 0;
		float logTime = 0;
		
	public:
		AdjustableParam *logRate;
		String outFileName = "";
		boolean isRunning = false;
		boolean isFaulted = false;
		
		//Constructor/Destructor
		DataLogger<Size>(AdjustableParam * LoggerRateMs, DS323RealTimeClock * Clock): SDDataLogger<Size>(SD_CHIP_SELECT_PIN), logRate(LoggerRateMs), RTC(Clock){
			addParam("time",&logTime);	
		};
		~DataLogger(void){};
		
		//Parent Class Functions
		using SDDataLogger<Size>::createOutFile;
		using SDDataLogger<Size>::closeOutFile;
		using SDDataLogger<Size>::outFileReady;
		using SDDataLogger<Size>::writeLog;
		using SDDataLogger<Size>::addParam;
		using SDDataLogger<Size>::fileExists;
		
		void log(){
			bool record = false;
			
			//Creating the output
			if((isRunning == true) && (prevRunState == false)){
					
				//Build a unique File name
				//String BaseName = "L" + RTC->getDateStamp(DS323RealTimeClock::DateStampFormat::YYYYMMDD);
				String BaseName = "Log";
				String outName = BaseName + ".csv";
				if( fileExists(outName)){
					int cnt = 0;
					while( fileExists(outName)){
						cnt = cnt+1;
						outName = BaseName + "(" + String(cnt) + ").csv";
					}
					
				}
				
				//Create a new File
				if(createOutFile(outName)){
					
					#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
						Serial.println(F("    Data Logging Started."));
						Serial.print(F("      Rate:"));
						Serial.println(logRate->getValue());
						Serial.print(F("      File:"));
						Serial.println(outName);
					#endif
					
					logStartTimeMillis = millis();
					isRunning = true;
					outFileName = outName;
				}else{
					
					#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
					Serial.println(F("    ERROR! Data Logging failed to Start."));
					Serial.print(F("      Rate:"));
					Serial.println(logRate->getValue());
					Serial.print(F("      File:"));
					Serial.println(outName);
					#endif
					
					isFaulted = true;
					isRunning = false;
					outFileName = "ERROR";
				}
			}
			
			//See if Stopping Running
			if((isRunning == false) && (prevRunState == true)){
				
				#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
				Serial.println(F("    Data Logging Stopped."));
				#endif
				closeOutFile();
			}
			
			//Writing the Log
			if(isRunning){
				logTime = ((float)(millis()-logStartTimeMillis))/1000;
				
				//Write log if time passed
				if( ((millis() - lastRecordMillis)/1000) > logRate->getValue() ){
					writeLog();
					lastRecordMillis = millis();
				}
			}
			
			prevRunState = isRunning;
		}
};

#endif //__DATALOGGER_H__
