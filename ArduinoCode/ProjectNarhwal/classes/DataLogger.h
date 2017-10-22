/* 
* DataLogger().h
*
* Created: 11/30/2016 11:07:22 PM
* Author: Nick1
*/


#ifndef __DATALOGGER_H__
#define __DATALOGGER_H__

#include "DS323RealTimeClock.h"

#include<Arduino.h>
#include <SD.h>
#include <SPI.h>
#include "../Main.h"

#ifndef PROGTEMPLATES
#define PROGTEMPLATES
template <typename T> void PROGMEM_readAnything (const T * sce, T& dest)
{
	memcpy_P (&dest, sce, sizeof (T));
}

template <typename T> T PROGMEM_getAnything (const T * sce)
{
	static T temp;
	memcpy_P (&temp, sce, sizeof (T));
	return temp;
}
#endif

#define str_buffer_size 50

enum LogItemType{
	byte_ptr,
	short_ptr,
	char_ptr,
	uchar_ptr,
	bool_ptr,
	int_ptr,
	uint_ptr,
	float_ptr,
	double_prt,
	listopt_ptr,
	adjparm_ptr,
	string_ptr,
};


struct LogItem{
	LogItemType Type;
	const char * Name;
	void* ItemRef;
};


class DataLogger{
	private:
		uint8_t i2Caddress;
		File outFile;
		DS323RealTimeClock * RTC;
		boolean prevRunState = false;
		unsigned long logStartTimeMillis = 0;
		unsigned long lastRecordMillis = 0;
		double logTime = 0;
		const LogItem *items;
		uint16_t itemCount = 0;
		boolean initialized = false;
		
	public:
		AdjustableParam *logRate;
		String outFileName = "";
		boolean isRunning = false;
		boolean isFaulted = false;
		
		//Constructor/Destructor
		DataLogger(AdjustableParam * LoggerRateMs, DS323RealTimeClock * Clock, const LogItem _items[], unsigned int _size): logRate(LoggerRateMs), RTC(Clock), items(_items), itemCount(_size){};
		~DataLogger(void){};
		
		//Create Output File
		boolean createOutFile(String filename){
			if(initialized){
				char copy[str_buffer_size];
				filename.toCharArray(copy, str_buffer_size);
				outFile = SD.open(filename, FILE_WRITE);
				if( outFile ){
					//First write the time column
					outFile.print("time,");
					
					//Write each parameter Name as a header
					for( int i=0; i<itemCount; i++){
						LogItem Item = PROGMEM_getAnything (&this->items[i]);
						String ItemName = (__FlashStringHelper*)Item.Name;
						outFile.print(ItemName);
						outFile.print(",");
					}
					outFile.println(" ");
					return true;
					}else{
			
					return false;
				}
			}
		}

		//is SD card ready
		boolean init(){
			
			pinMode(53, OUTPUT);
			if( SD.begin(i2Caddress)){
				initialized = true;
				}else{
				initialized = false;
			}
			return initialized;
		}

		//is SD card ready
		boolean isSDReady(){
			return initialized;
		}

		//Close Output File
		void closeOutFile(){
			if(outFile){
				outFile.close();
			}
		}

		//Check if out file exists
		boolean fileExists(String Name){
			char copy[str_buffer_size];
			Name.toCharArray(copy, str_buffer_size);
			return SD.exists(copy);
		}

		//See if outfile is ready to write to
		boolean outFileReady(){
			if(outFile){
				return true;
				}else{
				return false;
			}
		}

		//Write a log line entry
		void writeLog(){
			if(initialized && outFile){
				//Write the time
				outFile.print(String(logTime));
				
				//Write each parameter
				for( int i=0; i<itemCount; i++){
					LogItem Item = PROGMEM_getAnything (&this->items[i]);
					char outBuff[20];
					GetLogItemValueString(&Item,outBuff,20);
					outFile.print(outBuff);
					outFile.print(",");
				}
				outFile.println(" ");
			}
		};
		
		//Main Log Function
		void log(){
			bool record = false;
			
			//Creating the output
			if((isRunning == true) && (prevRunState == false)){
					
				//Build a unique File name
				String BaseName = "Log_" + RTC->getDateStamp(DS323RealTimeClock::DateStampFormat::YYYYMMDD) + "_" + RTC->getDateStamp(DS323RealTimeClock::DateStampFormat::HHMMSS);
				//String BaseName = "Log";
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
					
					//#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
						Serial.println(F("    Data Logging Started."));
						Serial.print(F("      Rate:"));
						Serial.println(logRate->getValue());
						Serial.print(F("      File:"));
						Serial.println(outName);
					//#endif
					
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
				logTime = ((double)(millis()-logStartTimeMillis))/1000;
				
				//Write log if time passed
				if( ((millis() - lastRecordMillis)/1000) > logRate->getValue() ){
					writeLog();
					lastRecordMillis = millis();
				}
			}
			
			prevRunState = isRunning;
		}
		
		
	void GetLogItemValueString(const LogItem *Item, char * outString, uint8_t outStringsize){
		String StrValue;
		if( Item->Type == LogItemType::byte_ptr ){
				StrValue = String( *(byte*)Item->ItemRef );
			}else if( Item->Type == LogItemType::bool_ptr ){
				StrValue = String( *(bool*)Item->ItemRef );
			}else if( Item->Type == LogItemType::adjparm_ptr ){
				StrValue = String( *(float*)Item->ItemRef );
			}else if( Item->Type == LogItemType::char_ptr ){
				StrValue = String( *(char*)Item->ItemRef );
			}else if( Item->Type == LogItemType::uchar_ptr ){
				StrValue = String( *(unsigned char*)Item->ItemRef );
			}else if( Item->Type == LogItemType::int_ptr ){
				StrValue = String( *(int*)Item->ItemRef );
			}else if( Item->Type == LogItemType::uint_ptr ){
				StrValue = String( *(unsigned int*)Item->ItemRef );
			}else if( Item->Type == LogItemType::float_ptr ){
				StrValue = String( *(float*)Item->ItemRef );
			}else if( Item->Type == LogItemType::double_prt ){
				StrValue = String( *(double*)Item->ItemRef );
			}else if( Item->Type == LogItemType::string_ptr ){
				StrValue = *(String*)Item->ItemRef;
			
			/*}else if( Item->Type == LogItemType.listopt_ptr ){
				ListOption * lst = (ListOption*)Item->ItemRef;
				StrValue = lst->valueText();
			}else if( Item->Type == LogItemType.adjparm_ptr ){
				AdjustableParam * adj = (AdjustableParam*)Item->ItemRef;
				StrValue = String(adj->value()); */
			}
	
			//Convert to c string and return
			//char copy[str_buffer_size];
			StrValue.toCharArray(outString, outStringsize);
		}
	};

#endif //__DATALOGGER_H__
