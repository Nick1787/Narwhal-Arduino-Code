/*
 * ListOption.h
 *
 * Created: 8/12/2016 8:12:06 PM
 *  Author: Customer
 */ 

#ifndef __LISTOPT
#define __LISTOPT

template <typename T>
struct ListOptionItem{
	T Value;
	const char * Text;
};

template <typename T>
class ListOption{
	private:
		ListOptionItem<T> *items;
		unsigned int itemCount;
		unsigned int cindex;
		
	public:
		//constructor
		ListOption<T>(ListOptionItem<T> * _items, unsigned int _size): itemCount(_size), items(_items){};
		
		//MEthods
		const ListOptionItem<T>* Items(){return this->items; };
		unsigned int Size(){ return itemCount;};
		unsigned int currentIndex(){return cindex;};
		T currentValue(){return items[cindex].Value;};
		
		void setIndex(unsigned int indx){ cindex = indx; };
		void setValue(T val){ 
			for(int i=0; i<itemCount; i++){
				if( items[i].Value == val){
					cindex = i;
					break;
				}
			}
		};
		
		
		T * Values(){
			T vals[itemCount];
			for(int i=0; i<itemCount; i++){
				vals[i] = items[i].Value;
			}
			return vals;
		}
		const char * ItemText(T val){
			for(int i=0; i<itemCount; i++){
				if( items[i].Value == val){
					return items[i].Text;
				}
			}
			return "--";
		}
};

#endif