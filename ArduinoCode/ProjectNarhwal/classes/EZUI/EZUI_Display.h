/*
 *        File: EZUI_Display.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Display Class - Menus and Pages
 */

#ifndef __EZUI_MENU_H__
#define __EZUI_MENU_H__

//Standard
#include <Arduino.h>

//Hardware Includes
#include <LiquidCrystal_I2C.h>
#include "EZUI_Hardware_ClickEncoder.h"

//Types
#include "EZUI_Display.h"
#include "ListOption.h"
#include "AdjustableParam.h"
#include "DigitalIO.h"

//Controls
#include "EZUI.h"
#include "EZUI_Control.h"
#include "EZUI_Control_AdjustParam.h"
#include "EZUI_Control_Button.h"
#include "EZUI_Control_Label.h"
#include "EZUI_Control_Link.h"
#include "EZUI_Control_ListOption.h"
#include "EZUI_Control_ToggleOption.h"

//Make Types Alittle Easier
#ifndef MenuItems
	#define EZUI_MenuItems const PROGMEM MenuItem
#endif

#ifndef PageItems
	#define EZUI_PageItems const PROGMEM PageItem
#endif

/*-----------------------------------------------
	EZUI_MenuItem
------------------------------------------------*/
struct MenuItem
{
	EZUI_Control *Control;
};


/*-----------------------------------------------
	EZUI_PageItem
------------------------------------------------*/
struct PageItem
{
	uint8_t col;
	uint8_t row;
	uint8_t fieldWidth;
	EZUI_Control *Control;
};
 

/*-----------------------------------------------
	EZUI_Display
------------------------------------------------*/
class EZUI_Display{
	private:
		
	public:
		int currentItem = -1;
		unsigned int itemCount = 0;
		void * items;
		bool refresh = true;
		
		//Set Items
		enum EZUI_DisplayType{ None, Menu, Page, ListOpt, AdjOpt};
		const PROGMEM EZUI_DisplayType Type;
		
		//Actions
		virtual void display(EZUI *UI);			//Default display function
		virtual void init(EZUI *UI);			//Initialization routines
		virtual void cleanup(EZUI *UI);			//Cleanup when leaving this menu
		virtual void prevItem(EZUI *UI);				//Moves cursor to next item (also calls display to refresh the LCD)
		virtual void nextItem(EZUI *UI);				//Moves cursor to next item (also calls display to refresh the LCD)
		virtual void selectItem(EZUI *UI);		//Select the Item, Passes the User interface parent by reference
		
		//Functions
		static void EditListOption(EZUI_Control_ListOption * ListOptRef);
		
		//Constructors
		EZUI_Display() : Type(EZUI_DisplayType::None) {};
		EZUI_Display(EZUI_DisplayType _Type) : Type(_Type) {};
		virtual ~EZUI_Display() {};
};


/*-----------------------------------------------
	EZUI_Menu
------------------------------------------------*/
class EZUI_Menu : public EZUI_Display{
	private:
		bool itemChanged = false;
		const MenuItem * items;
		unsigned int size;
		unsigned int cursorLine = 0;
		
	protected:
	public:
		EZUI_Menu(): EZUI_Display(EZUI_DisplayType::Menu){};
		void setItems(const MenuItem _items[], unsigned int _size);
		
		//Actions
		void display(EZUI *UI);
		
		void init(EZUI *UI);
		void cleanup(EZUI *UI){ /* Do Nothing */};
		void prevItem(EZUI *UI);
		void nextItem(EZUI *UI);
		void selectItem(EZUI *UI);
		
	private:
		void printItem(EZUI *UI, unsigned int line, unsigned int itemIndex);
		void selectItem(EZUI *UI, EZUI_Control_ToggleOption const * ToggleOptRef);
		void selectItem(EZUI *UI, EZUI_Control_Link const * LinkOptRef);
		//void printItem(int col, int row, LiquidCrystal_I2C * LCD, EZUI_Control_Link const *LinkRef);
		//void printItem(int col, int row, LiquidCrystal_I2C * LCD, EZUI_Control_ToggleOption const *LinkRef);
		void printPage(EZUI *UI);
		
};


/*-----------------------------------------------
	EZUI_PAGE
------------------------------------------------*/
class EZUI_Page : public EZUI_Display{
	private:
		String *itemsText;
		
		const PageItem *items;
		int itemCount = 0;
		int currentItem = -1;
		boolean itemChanged = true;
		boolean refresh = false;
		unsigned long lastPrint = 0;
		unsigned long refreshRate = 500;
		
	protected:
	public:
		EZUI_Page(): EZUI_Display(EZUI_DisplayType::Page){};
		void setItems(const PageItem _items[], unsigned int _size);
	
		//Actions
		void display(EZUI *UI) override;
		void init(EZUI *UI) override;
		void cleanup(EZUI *UI) override;
		void prevItem(EZUI *UI) override;
		void nextItem(EZUI *UI)  override;
		void selectItem(EZUI *UI) override;
	
	private:
};

/*-----------------------------------------------
	EZUI_ListOptionEditor
------------------------------------------------*/
class EZUI_ListOptionEditor : public EZUI_Display{
	private:
		GenericListOption *ListOptRef;
		EZUI_Display *ParentDispRef;
		
		bool APPLY = false;
		unsigned int temp_index;
		
		enum ListEditMode{ ERR, ONITEM, SEL, OKCANCEL};
		ListEditMode Mode;
		
		void drawListItems( EZUI *UI);
	protected:
	public:
		EZUI_ListOptionEditor(GenericListOption * Ref, EZUI_Display * ParentDisp): ListOptRef(Ref), ParentDispRef(ParentDisp), EZUI_Display(EZUI_DisplayType::ListOpt){};
	
		//Actions
		void display(EZUI *UI) override;
		void init(EZUI *UI) override;
		void cleanup(EZUI *UI) override;
		void prevItem(EZUI *UI) override;
		void nextItem(EZUI *UI)  override;
		void selectItem(EZUI *UI) override;
	
	private:
};


/*-----------------------------------------------
	EZUI_AdjustParamEditor
------------------------------------------------*/
class EZUI_AdjustParamEditor : public EZUI_Display{
	private:
		AdjustableParam *AdjParamRef;
		EZUI_Display *ParentDispRef;
		
		bool APPLY = false;
		float _tempValue;
		
		enum AdjEditMode{ ERR, ADJUST, OKCANCEL};
		AdjEditMode Mode = ADJUST;
		
		unsigned long lastUpdate = 0;
		
	protected:
	public:
		EZUI_AdjustParamEditor(AdjustableParam * Ref, EZUI_Display * ParentDisp): AdjParamRef(Ref), ParentDispRef(ParentDisp), EZUI_Display(EZUI_DisplayType::AdjOpt){};
	
		//Actions
		void display(EZUI *UI) override;
		void init(EZUI *UI) override;
		void cleanup(EZUI *UI) override;
		void prevItem(EZUI *UI) override;
		void nextItem(EZUI *UI)  override;
		void selectItem(EZUI *UI) override;
	
	private:
};
#endif //__LCDMENU_H__
