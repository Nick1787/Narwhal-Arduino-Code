/* 
* DataLogger.h
*
* Created: 11/30/2016 11:07:22 PM
* Author: Nick1
*/


#ifndef __DATALOGGER_H__
#define __DATALOGGER_H__

#include "SDDataLogger.h"

template <unsigned int Size>
class DataLogger: public SDDataLogger<Size>{
	private:
		boolean prevRunState = false;
		unsigned int logStartTimeMillis = 0;
		unsigned int lastRecordMillis = 0;
		unsigned int logRateMs = 1000;
		float logTime = 0;
		
	public:
		boolean isRunning = false;
		boolean isFaulted = false;
		
		//Constructor/Destructor
		DataLogger<Size>(unsigned int LoggerRateMs): SDDataLogger<Size>(SDCARD_ADDR), logRateMs(LoggerRateMs){
			addParam("time",&logTime);	
		};
		~DataLogger(void){};
		
		//Parent Class Functions
		using SDDataLogger<Size>::createOutFile;
		using SDDataLogger<Size>::closeOutFile;
		using SDDataLogger<Size>::outFileReady;
		using SDDataLogger<Size>::writeLog;
		using SDDataLogger<Size>::addParam;
		
		void log(){
			bool record = false;
			
			//Creating the output
			if((isRunning == true) && (prevRunState == false)){
				//Create a new File
				createOutFile("test.txt");
				if(outFileReady()){
					logStartTimeMillis = millis();
					isRunning = true;
				}else{
					isFaulted = true;
					isRunning = false;
				}
			}
			
			//See if Stopping Running
			if((isRunning == false) && (prevRunState == true)){
				closeOutFile();
			}
			
			//Writing the Log
			if(isRunning){
				logTime = ((float)(millis()-logStartTimeMillis))/1000;
				
				//Write log if time passed
				if( (millis() - lastRecordMillis) > logRateMs ){
					writeLog();
				}
			}
			
			prevRunState = isRunning;
		}
};

#endif //__DATALOGGER_H__
