/*
 *         File: EZUI_UI.cpp
 *       Author: Nick Dodds <Nick1787@gmail.com>
 *  Description: EZ User Display Class 
 * Dependencies: None
 */

#ifndef __EZUI_MENU_H__
#define __EZUI_MENU_H__

//Standard
#include <Arduino.h>

//Hardware Includes
#include <avr/pgmspace.h>
#include <LiquidCrystal_I2C.h>
#include "EZUI_Hardware_ClickEncoder.h"

//Types
#include "EZUI_UI.h"
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

//string Buffer side
#ifndef str_buffer_size
#define str_buffer_size 40
#endif
extern char strbuffer[];

//Make Types Alittle Easier
#ifndef EZUI_MenuItems
	#define EZUI_MenuItems static const PROGMEM MenuItem
#endif

#ifndef EZUI_PageItems
	#define EZUI_PageItems static const PROGMEM PageItem
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
	EZUI_UI
------------------------------------------------*/
class EZUI_UI{
	private:
		
	public:
		int currentItem = -1;
		unsigned int itemCount = 0;
		void * items;
		bool refresh = true;
		
		//Set Items
		enum EZUI_UIType{ None, Menu, Page, ListOpt, AdjOpt};
		const PROGMEM EZUI_UIType Type;
		
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
		EZUI_UI() : Type(EZUI_UIType::None) {};
		EZUI_UI(EZUI_UIType _Type) : Type(_Type) {};
		virtual ~EZUI_UI() {};
};


/*-----------------------------------------------
	EZUI_Menu
------------------------------------------------*/
class EZUI_Menu : public EZUI_UI{
	private:
		bool itemChanged = false;
		const MenuItem * items;
		unsigned int size;
		unsigned int cursorLine = 0;
		
	protected:
	public:
		EZUI_Menu(): EZUI_UI(EZUI_UIType::Menu){};
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
		void printPage(EZUI *UI);
		
};


/*-----------------------------------------------
	EZUI_PAGE
------------------------------------------------*/
class EZUI_Page : public EZUI_UI{
	private:
		//String *itemsText;
		
		const PageItem *items;
		int itemCount = 0;
		int currentItem = -1;
		boolean itemChanged = true;
		boolean refresh = false;
		unsigned long lastPrint = 0;
		unsigned long refreshRate = 1000;
		
	protected:
	public:
		EZUI_Page(): EZUI_UI(EZUI_UIType::Page){};
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
class EZUI_ListOptionEditor : public EZUI_UI{
	private:
		GenericListOption *ListOptRef;
		EZUI_UI *ParentDispRef;
		
		bool APPLY = false;
		unsigned int temp_index;
		
		enum ListEditMode{ ERR, ONITEM, SEL, OKCANCEL};
		ListEditMode Mode;
		
		void drawListItems( EZUI *UI);
	protected:
	public:
		EZUI_ListOptionEditor(GenericListOption * Ref, EZUI_UI * ParentDisp): ListOptRef(Ref), ParentDispRef(ParentDisp), EZUI_UI(EZUI_UIType::ListOpt){};
	
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
class EZUI_AdjustParamEditor : public EZUI_UI{
	private:
		AdjustableParam *AdjParamRef;
		EZUI_UI *ParentDispRef;
		
		bool APPLY = false;
		float _tempValue;
		
		enum AdjEditMode{ ERR, ADJUST, OKCANCEL};
		AdjEditMode Mode = ADJUST;
		
		unsigned long lastUpdate = 0;
		
	protected:
	public:
		EZUI_AdjustParamEditor(AdjustableParam * Ref, EZUI_UI * ParentDisp): AdjParamRef(Ref), ParentDispRef(ParentDisp), EZUI_UI(EZUI_UIType::AdjOpt){};
	
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
