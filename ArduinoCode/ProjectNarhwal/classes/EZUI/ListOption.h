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
		virtual unsigned int currentItem(){return 0;};
		virtual unsigned int itemCount(){return -1;};
		virtual void setItem(unsigned int indx){};
		virtual const char* itemText(unsigned int indx){ return "--";};
};

template <typename T>
struct ListOptionItem{
	T Value;
	const PROGMEM char* Text;
};

template <typename T>
class ListOption : public GenericListOption{
	private:
		ListOptionItem<T> *items;
		unsigned int length;
		unsigned int cindex;
		
	public:
		//constructor
		ListOption<T>(ListOptionItem<T> * _items, unsigned int _size): length(_size), items(_items){};
		
		//Override Methods
		unsigned int currentItem() override{return cindex;};
		unsigned int itemCount() override{ return length;};
		void setItem (unsigned int indx) override{ cindex = indx; };
		const char* itemText (unsigned int indx) override{ return items[indx].Text;	};
		
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
					return items[i].Text;
				}
			}
			return "--";
		}
};

#endif