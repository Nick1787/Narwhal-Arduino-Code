/*
 *        File: iodef.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Defines the hardware io pins for Project Narwhal on
 *				the arduino Mega
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#ifndef iodef_h
#define iodef_h

///////////////////////////////
// General
///////////////////////////////
#define AN_REF 5.0 
#define AN_OUT A0

///////////////////////////////
// Loop 1
///////////////////////////////

//Out 1
#define CTR_1_OUT 23 //Ctrl Digital out

//LCD 1
#define LCD_1_I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is
#define LCD_1_BACKLIGHT_PIN     3
#define LCD_1_En_pin  2
#define LCD_1_Rw_pin  1
#define LCD_1_Rs_pin  0
#define LCD_1_D4_pin  4
#define LCD_1_D5_pin  5
#define LCD_1_D6_pin  6
#define LCD_1_D7_pin  7

//Encoder
#define ENC_1_A 50
#define ENC_1_B 51
#define ENC_1_C 52

//Analog In
#define AN_IN_1 A1


///////////////////////////////
// Loop 2
///////////////////////////////

//Out 2
#define CTR_2_OUT 0 //Ctrl Digital out

//LCD 2
#define LCD_2_RW 12
#define LCD_2_EN 11
#define LCD_2_D4 46
#define LCD_2_D5 48
#define LCD_2_D6 50
#define LCD_2_D7 52

//Encoder 2
#define ENC_2_A 30
#define ENC_2_B 32
#define ENC_2_C 31

///////////////////////////////
// Loop 3
///////////////////////////////

//Out 3
#define CTR_3_OUT 0 //Ctrl Digital out

//LCD 3
#define LCD_3_RW 12
#define LCD_3_EN 11
#define LCD_3_D4 46
#define LCD_3_D5 48
#define LCD_3_D6 50
#define LCD_3_D7 52

//Encoder 3
#define ENC_3_A 34
#define ENC_3_B 36
#define ENC_3_C 35


#endif
