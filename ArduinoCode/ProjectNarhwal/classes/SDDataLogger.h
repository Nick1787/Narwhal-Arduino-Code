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
		uint8_t i2Caddress;
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
			i2Caddress = address;
		};
			
		~SDDataLogger(){};
	
		//Create Output File
		boolean createOutFile(String filename){
			if(initialized){
				char fn[filename.length()+1];
				filename.toCharArray(fn, sizeof(fn));
				outFile = SD.open(fn, FILE_WRITE);
				if( outFile ){
					
					Serial.println("HERE3!");
					//Write each parameter Name as a header
					for( int i=0; i<itemCount; i++){
						outFile.print(Items[i]->strLabel());
						outFile.print(",");
					}
					outFile.println(" ");
					return true;
				}else{
					
					Serial.println("HERE4!");
					return false;
				}
			}
		}
				
		//is SD card ready
		boolean init(){
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
			char fn[Name.length()+1];
			Name.toCharArray(fn, sizeof(fn));
			return SD.exists(fn);
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
			
		void addParam(const __FlashStringHelper * Label, byte * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<byte>(Label, Ref);itemCount++;}};
		void addParam(const __FlashStringHelper * Label, boolean * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<boolean>(Label, Ref);itemCount++;}};
		void addParam(const __FlashStringHelper * Label, short * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<short>(Label, Ref);itemCount++;}};
		void addParam(const __FlashStringHelper * Label, unsigned short * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<unsigned short>(Label, Ref);itemCount++;}};
		void addParam(const __FlashStringHelper * Label, int * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<int>(Label, Ref);itemCount++;}};
		void addParam(const __FlashStringHelper * Label, unsigned int * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<unsigned int>(Label, Ref);itemCount++;}};
		void addParam(const __FlashStringHelper * Label, long * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<long>(Label, Ref);itemCount++;}};
		void addParam(const __FlashStringHelper * Label, unsigned long * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<unsigned long>(Label, Ref);itemCount++;}};
		void addParam(const __FlashStringHelper * Label, float * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<float>(Label, Ref);itemCount++;}};
		void addParam(const __FlashStringHelper * Label, double * Ref){	if(itemCount < maxItemCount){ Items[itemCount] = new ParamRef<double>(Label, Ref);itemCount++;}};
	
}; 


#endif /* SDDATALOGGER_H_ */