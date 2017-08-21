/*
 * ListOption.h
 *
 * Created: 8/12/2016 8:12:06 PM
 *  Author: Customer
 */ 

#ifndef __LISTOPT
#define __LISTOPT
#include<Arduino.h>
class GenericListOption{
	public:
		virtual uint8_t currentItem(){return 0;};
		virtual uint8_t itemCount(){return -1;};
		virtual void setItem(unsigned int indx){};
		virtual const __FlashStringHelper* itemText(unsigned int indx){ return F("--");};
};

template <typename T>
struct ListOptionItem{
	T Value;
	const __FlashStringHelper* Text;
};

template <typename T>
class ListOption : public GenericListOption{
	private:
		ListOptionItem<T> *items;
		uint8_t length;
		uint8_t cindex;
		
	public:
		//constructor
		ListOption<T>(ListOptionItem<T> * _items, unsigned int _size): length(_size), items(_items){};
		
		//Override Methods
		uint8_t currentItem() override{return cindex;};
		uint8_t itemCount() override{ return length;};
		void setItem (unsigned int indx) override{ cindex = indx; };
		const __FlashStringHelper* itemText (unsigned int indx) override{ 
			return items[indx].Text;
		};
		
		//Other Values
		const ListOptionItem<T>* Items(){return this->items; };
		T currentValue(){return items[cindex].Value;};
		
		void setValue(T val){ 
			for(int i=0; i<length; i++){
				if( items[i].Value == val){
					cindex = i;
					break;
				}
			}
		};
		
		
		T * Values(){
			T vals[length];
			for(int i=0; i<length; i++){
				vals[i] = items[i].Value;
			}
			return vals;
		};
		const char * valueText (T val){
			for(int i=0; i<length; i++){
				if( items[i].Value == val){
					return itemText(i);
				}
			}
			return "--";
		}
};

#endif