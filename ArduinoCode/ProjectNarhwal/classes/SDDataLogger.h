/*
 * SDDataLogger.h
 *
 * Created: 12/11/2016 2:54:31 PM
 *  Author: Nick1
 */ 


#ifndef SDDATALOGGER_H_
#define SDDATALOGGER_H_


#include<Arduino.h>
#include <SD.h>
#include <SPI.h>

class GenericParamRef{
	public:
	virtual String strValue(){ return""; };
	virtual String strLabel(){ return""; };
};

template <typename T>
class ParamRef : public GenericParamRef{
	private:
		const bool isFlashLabel = false;
		T* Ref;
		const unsigned int Label = NULL;
	public:
		ParamRef(const __FlashStringHelper * Lbl, T* PRef): Label((const unsigned int)Lbl), Ref(PRef), isFlashLabel(true){};
		ParamRef(const char * Lbl, T* PRef):				Label((const unsigned int)Lbl), Ref(PRef){};
			
		//Over-ridden Functions
		String strLabel(){ 
			if(isFlashLabel){ 
				return String((__FlashStringHelper*)(Label));
			}else{
				return String((const char *)Label);
			} 
		};
		String strValue(){ return String(*Ref); };
};

template <unsigned int Size>
class SDDataLogger{
	private:
		boolean initialized = false;
		PROGMEM GenericParamRef *Items[Size] ;
		File outFile;

	//functions
	public:
		char* filename = "";
		unsigned int itemCount = 0;
		const PROGMEM unsigned int maxItemCount = Size;
	
		//Constructor, Destructor
		SDDataLogger<Size>(uint8_t address){
			if(SD.begin(address)){
				initialized = true;
			}
		};
			
		~SDDataLogger(){};
	
		//Create Output File
		int createOutFile(char* filename){
			if(initialized){
				outFile = SD.open(filename, FILE_WRITE);
			
				if( outFile ){
					//Write each parameter Name as a header
					for( int i=0; i<itemCount; i++){
						outFile.print(Items[i]->strLabel());
						outFile.print(",");
					}
					outFile.println(" ");
					return 1;
				}else{
					return 0;
			
				}
			}
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
				//Write each parameter
				for( int i=0; i<itemCount; i++){
					outFile.print(Items[i]->strValue());
					outFile.print(",");
				}
				outFile.println(" ");
			}
		};
	
		//Adding Parameters
		void addParam(const char* Label, byte * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<byte>(Label, Ref);itemCount++;}};
		void addParam(const char* Label, boolean * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<boolean>(Label, Ref);itemCount++;}};
		void addParam(const char* Label, short * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<short>(Label, Ref);itemCount++;}};
		void addParam(const char* Label, unsigned short * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<unsigned short>(Label, Ref);itemCount++;}};
		void addParam(const char* Label, int * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<int>(Label, Ref);itemCount++;}};
		void addParam(const char* Label, unsigned int * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<unsigned int>(Label, Ref);itemCount++;}};
		void addParam(const char* Label, long * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<long>(Label, Ref);itemCount++;}};
		void addParam(const char* Label, unsigned long * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<unsigned long>(Label, Ref);itemCount++;}};
		void addParam(const char* Label, float * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<float>(Label, Ref);itemCount++;}};
		void addParam(const char* Label, double * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<double>(Label, Ref);itemCount++;}};
	
}; 


#endif /* SDDATALOGGER_H_ */