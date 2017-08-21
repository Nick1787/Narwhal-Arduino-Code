/*
 * SDDataLogger().h
 *
 * Created: 12/11/2016 2:54:31 PM
 *  Author: Nick1
 */ 


#ifndef SDDATALOGGER_H_
#define SDDATALOGGER_H_


class SDDataLogger{
	private:
		LogItem *items;
		uint16_t itemCount = 0;

	//functions
	public:
		char* filename = "";
	
		//Constructor, Destructor
		SDDataLogger(uint8_t address, const LogItem _items[], unsigned int _size): i2Caddress(address), items(_items), itemCount(size){};
		~SDDataLogger(){};
	
}; 


#endif /* SDDATALOGGER_H_ */