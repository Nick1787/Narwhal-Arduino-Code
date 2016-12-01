/* 
* DataLogger.h
*
* Created: 11/30/2016 11:07:22 PM
* Author: Nick1
*/


#ifndef __DATALOGGER_H__
#define __DATALOGGER_H__

//#include "../include/SD/SD.h"
//#include "../include/SPI/spi.h"

class DataLogger
{
//variables
public:
	unsigned int itemCount = 0;
	char* filename = "";
	
protected:
private:	
	//SD * _SDCard;
	//File _logFile;


//functions
public:
	DataLogger();
	~DataLogger();
	
protected:
private:

}; //DataLogger

#endif //__DATALOGGER_H__
