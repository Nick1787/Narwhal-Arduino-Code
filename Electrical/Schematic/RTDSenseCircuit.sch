EESchema Schematic File Version 2
LIBS:Project_Narwhal_Electrical-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:valves
LIBS:NarwhalLib
LIBS:Project_Narwhal_Electrical-cache
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 3 4
Title "RTD Wheatstone Bridge Sensing Circuit"
Date "2016-10-30"
Rev "3"
Comp "Project Narwhal"
Comment1 "Constant voltage 3-wire 100 Ohm RTD circuit"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_3 22-23-2031
U 1 1 55E5D538
P 1700 2900
AR Path="/55E57BF5/55E5D538" Ref="22-23-2031"  Part="1" 
AR Path="/55E5C9A3/55E5D538" Ref="K?"  Part="1" 
AR Path="/55E62603/55E5D538" Ref="K"  Part="1" 
F 0 "22-23-2031" V 1650 2900 50  0000 C CNN
F 1 "CONN_3" V 1750 2900 40  0000 C CNN
F 2 "" H 1700 2900 60  0000 C CNN
F 3 "" H 1700 2900 60  0000 C CNN
	1    1700 2900
	-1   0    0    -1  
$EndComp
$Comp
L CONN_3 22-23-2031
U 1 1 55E5D545
P 1700 4050
AR Path="/55E57BF5/55E5D545" Ref="22-23-2031"  Part="1" 
AR Path="/55E5C9A3/55E5D545" Ref="K?"  Part="1" 
AR Path="/55E62603/55E5D545" Ref="K"  Part="1" 
F 0 "22-23-2031" V 1650 4050 50  0000 C CNN
F 1 "CONN_3" V 1750 4050 40  0000 C CNN
F 2 "" H 1700 4050 60  0000 C CNN
F 3 "" H 1700 4050 60  0000 C CNN
	1    1700 4050
	-1   0    0    -1  
$EndComp
$Comp
L CONN_3 22-23-2031
U 1 1 55E5D54B
P 1700 5150
AR Path="/55E57BF5/55E5D54B" Ref="22-23-2031"  Part="1" 
AR Path="/55E5C9A3/55E5D54B" Ref="K?"  Part="1" 
AR Path="/55E62603/55E5D54B" Ref="K"  Part="1" 
F 0 "22-23-2031" V 1650 5150 50  0000 C CNN
F 1 "CONN_3" V 1750 5150 40  0000 C CNN
F 2 "" H 1700 5150 60  0000 C CNN
F 3 "" H 1700 5150 60  0000 C CNN
	1    1700 5150
	-1   0    0    -1  
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D562
P 3800 3000
AR Path="/55E57BF5/55E5D562" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D562" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D562" Ref="R"  Part="1" 
AR Path="/55E5D562" Ref="R?"  Part="1" 
F 0 "R" V 3880 3000 40  0000 C CNN
F 1 "100" V 3807 3001 40  0000 C CNN
F 2 "~" V 3730 3000 30  0000 C CNN
F 3 "~" H 3800 3000 30  0000 C CNN
	1    3800 3000
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D56F
P 4400 3000
AR Path="/55E57BF5/55E5D56F" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D56F" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D56F" Ref="R"  Part="1" 
AR Path="/55E5D56F" Ref="R?"  Part="1" 
F 0 "R" V 4480 3000 40  0000 C CNN
F 1 "2000" V 4407 3001 40  0000 C CNN
F 2 "~" V 4330 3000 30  0000 C CNN
F 3 "~" H 4400 3000 30  0000 C CNN
	1    4400 3000
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D575
P 3800 2800
AR Path="/55E57BF5/55E5D575" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D575" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D575" Ref="R"  Part="1" 
AR Path="/55E5D575" Ref="R?"  Part="1" 
F 0 "R" V 3880 2800 40  0000 C CNN
F 1 "2000" V 3807 2801 40  0000 C CNN
F 2 "~" V 3730 2800 30  0000 C CNN
F 3 "~" H 3800 2800 30  0000 C CNN
	1    3800 2800
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D5A4
P 3800 4150
AR Path="/55E57BF5/55E5D5A4" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D5A4" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D5A4" Ref="R"  Part="1" 
AR Path="/55E5D5A4" Ref="R?"  Part="1" 
F 0 "R" V 3880 4150 40  0000 C CNN
F 1 "100" V 3807 4151 40  0000 C CNN
F 2 "~" V 3730 4150 30  0000 C CNN
F 3 "~" H 3800 4150 30  0000 C CNN
	1    3800 4150
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D5AA
P 4400 4150
AR Path="/55E57BF5/55E5D5AA" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D5AA" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D5AA" Ref="R"  Part="1" 
AR Path="/55E5D5AA" Ref="R?"  Part="1" 
F 0 "R" V 4480 4150 40  0000 C CNN
F 1 "2000" V 4407 4151 40  0000 C CNN
F 2 "~" V 4330 4150 30  0000 C CNN
F 3 "~" H 4400 4150 30  0000 C CNN
	1    4400 4150
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D5B0
P 3800 3950
AR Path="/55E57BF5/55E5D5B0" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D5B0" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D5B0" Ref="R"  Part="1" 
AR Path="/55E5D5B0" Ref="R?"  Part="1" 
F 0 "R" V 3880 3950 40  0000 C CNN
F 1 "2000" V 3807 3951 40  0000 C CNN
F 2 "~" V 3730 3950 30  0000 C CNN
F 3 "~" H 3800 3950 30  0000 C CNN
	1    3800 3950
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D5B9
P 3800 5250
AR Path="/55E57BF5/55E5D5B9" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D5B9" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D5B9" Ref="R"  Part="1" 
AR Path="/55E5D5B9" Ref="R?"  Part="1" 
F 0 "R" V 3880 5250 40  0000 C CNN
F 1 "100" V 3807 5251 40  0000 C CNN
F 2 "~" V 3730 5250 30  0000 C CNN
F 3 "~" H 3800 5250 30  0000 C CNN
	1    3800 5250
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D5BF
P 4400 5250
AR Path="/55E57BF5/55E5D5BF" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D5BF" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D5BF" Ref="R"  Part="1" 
AR Path="/55E5D5BF" Ref="R?"  Part="1" 
F 0 "R" V 4480 5250 40  0000 C CNN
F 1 "2000" V 4407 5251 40  0000 C CNN
F 2 "~" V 4330 5250 30  0000 C CNN
F 3 "~" H 4400 5250 30  0000 C CNN
	1    4400 5250
	0    -1   -1   0   
$EndComp
$Comp
L CONN_3 22-23-2031
U 1 1 55E5D6DF
P 1700 6200
AR Path="/55E57BF5/55E5D6DF" Ref="22-23-2031"  Part="1" 
AR Path="/55E5C9A3/55E5D6DF" Ref="K?"  Part="1" 
AR Path="/55E62603/55E5D6DF" Ref="K"  Part="1" 
F 0 "22-23-2031" V 1650 6200 50  0000 C CNN
F 1 "CONN_3" V 1750 6200 40  0000 C CNN
F 2 "" H 1700 6200 60  0000 C CNN
F 3 "" H 1700 6200 60  0000 C CNN
	1    1700 6200
	-1   0    0    -1  
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D6E5
P 3800 6300
AR Path="/55E57BF5/55E5D6E5" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D6E5" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D6E5" Ref="R"  Part="1" 
AR Path="/55E5D6E5" Ref="R?"  Part="1" 
F 0 "R" V 3880 6300 40  0000 C CNN
F 1 "100" V 3807 6301 40  0000 C CNN
F 2 "~" V 3730 6300 30  0000 C CNN
F 3 "~" H 3800 6300 30  0000 C CNN
	1    3800 6300
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D6EB
P 4400 6300
AR Path="/55E57BF5/55E5D6EB" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D6EB" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D6EB" Ref="R"  Part="1" 
AR Path="/55E5D6EB" Ref="R?"  Part="1" 
F 0 "R" V 4480 6300 40  0000 C CNN
F 1 "2000" V 4407 6301 40  0000 C CNN
F 2 "~" V 4330 6300 30  0000 C CNN
F 3 "~" H 4400 6300 30  0000 C CNN
	1    4400 6300
	0    -1   -1   0   
$EndComp
$Comp
L AD623 U?
U 1 1 55E5D9AD
P 6450 2650
AR Path="/55E57BF5/55E5D9AD" Ref="U?"  Part="1" 
AR Path="/55E5C9A3/55E5D9AD" Ref="U?"  Part="1" 
AR Path="/55E62603/55E5D9AD" Ref="U?"  Part="1" 
F 0 "U?" H 6450 2650 60  0001 C CNN
F 1 "AD623" H 6450 2650 60  0000 C CNN
F 2 "" H 6450 2650 60  0000 C CNN
F 3 "" H 6450 2650 60  0000 C CNN
	1    6450 2650
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5DAAC
P 6450 2350
AR Path="/55E57BF5/55E5DAAC" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5DAAC" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5DAAC" Ref="R"  Part="1" 
AR Path="/55E5DAAC" Ref="R?"  Part="1" 
F 0 "R" V 6530 2350 40  0000 C CNN
F 1 "2000" V 6457 2351 40  0000 C CNN
F 2 "~" V 6380 2350 30  0000 C CNN
F 3 "~" H 6450 2350 30  0000 C CNN
	1    6450 2350
	0    -1   -1   0   
$EndComp
$Comp
L AD623 U?
U 1 1 55E5DBED
P 6450 3800
AR Path="/55E57BF5/55E5DBED" Ref="U?"  Part="1" 
AR Path="/55E5C9A3/55E5DBED" Ref="U?"  Part="1" 
AR Path="/55E62603/55E5DBED" Ref="U?"  Part="1" 
F 0 "U?" H 6450 3800 60  0001 C CNN
F 1 "AD623" H 6450 3800 60  0000 C CNN
F 2 "" H 6450 3800 60  0000 C CNN
F 3 "" H 6450 3800 60  0000 C CNN
	1    6450 3800
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5DBF5
P 6450 3500
AR Path="/55E57BF5/55E5DBF5" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5DBF5" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5DBF5" Ref="R"  Part="1" 
AR Path="/55E5DBF5" Ref="R?"  Part="1" 
F 0 "R" V 6530 3500 40  0000 C CNN
F 1 "2000" V 6457 3501 40  0000 C CNN
F 2 "~" V 6380 3500 30  0000 C CNN
F 3 "~" H 6450 3500 30  0000 C CNN
	1    6450 3500
	0    -1   -1   0   
$EndComp
$Comp
L AD623 U?
U 1 1 55E5DC01
P 6450 4900
AR Path="/55E57BF5/55E5DC01" Ref="U?"  Part="1" 
AR Path="/55E5C9A3/55E5DC01" Ref="U?"  Part="1" 
AR Path="/55E62603/55E5DC01" Ref="U?"  Part="1" 
F 0 "U?" H 6450 4900 60  0001 C CNN
F 1 "AD623" H 6450 4900 60  0000 C CNN
F 2 "" H 6450 4900 60  0000 C CNN
F 3 "" H 6450 4900 60  0000 C CNN
	1    6450 4900
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5DC09
P 6450 4600
AR Path="/55E57BF5/55E5DC09" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5DC09" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5DC09" Ref="R"  Part="1" 
AR Path="/55E5DC09" Ref="R?"  Part="1" 
F 0 "R" V 6530 4600 40  0000 C CNN
F 1 "2000" V 6457 4601 40  0000 C CNN
F 2 "~" V 6380 4600 30  0000 C CNN
F 3 "~" H 6450 4600 30  0000 C CNN
	1    6450 4600
	0    -1   -1   0   
$EndComp
$Comp
L AD623 U?
U 1 1 55E5DC15
P 6450 5950
AR Path="/55E57BF5/55E5DC15" Ref="U?"  Part="1" 
AR Path="/55E5C9A3/55E5DC15" Ref="U?"  Part="1" 
AR Path="/55E62603/55E5DC15" Ref="U?"  Part="1" 
F 0 "U?" H 6450 5950 60  0001 C CNN
F 1 "AD623" H 6450 5950 60  0000 C CNN
F 2 "" H 6450 5950 60  0000 C CNN
F 3 "" H 6450 5950 60  0000 C CNN
	1    6450 5950
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5DC1D
P 6450 5650
AR Path="/55E57BF5/55E5DC1D" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5DC1D" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5DC1D" Ref="R"  Part="1" 
AR Path="/55E5DC1D" Ref="R?"  Part="1" 
F 0 "R" V 6530 5650 40  0000 C CNN
F 1 "2000" V 6457 5651 40  0000 C CNN
F 2 "~" V 6380 5650 30  0000 C CNN
F 3 "~" H 6450 5650 30  0000 C CNN
	1    6450 5650
	0    -1   -1   0   
$EndComp
$Comp
L 4.9V_REGULATOR U?
U 1 1 55E5E83D
P 6600 1400
AR Path="/55E57BF5/55E5E83D" Ref="U?"  Part="1" 
AR Path="/55E5C9A3/55E5E83D" Ref="U?"  Part="1" 
AR Path="/55E62603/55E5E83D" Ref="U?"  Part="1" 
F 0 "U?" H 6600 1400 39  0001 C CNN
F 1 "4.9V_REGULATOR" H 6600 1400 39  0000 C CNN
F 2 "" H 6600 1400 60  0000 C CNN
F 3 "" H 6600 1400 60  0000 C CNN
	1    6600 1400
	-1   0    0    -1  
$EndComp
Text Label 2000 2800 0    39   ~ 0
RTD0_B
Text Label 2000 2900 0    39   ~ 0
RTD0_B
Text Label 2000 3000 0    39   ~ 0
RTD0_A
Text Label 2000 3950 0    39   ~ 0
RTD1_B
Text Label 2000 4050 0    39   ~ 0
RTD1_B
Text Label 2000 4150 0    39   ~ 0
RTD1_A
Text Label 2000 5050 0    39   ~ 0
RTD2_B
Text Label 2000 5150 0    39   ~ 0
RTD2_B
Text Label 2000 5250 0    39   ~ 0
RTD2_A
Text Label 2000 6100 0    39   ~ 0
RTD3_B
Text Label 2000 6200 0    39   ~ 0
RTD3_B
Text Label 2000 6300 0    39   ~ 0
RTD3_A
Text Label 8900 3400 0    39   ~ 0
Vref
Text Label 8900 3500 0    39   ~ 0
RTD_0_Vout
Text Label 8900 3600 0    39   ~ 0
RTD_1_Vout
Text Label 8900 3700 0    39   ~ 0
RTD_2_Vout
Text Label 8900 3800 0    39   ~ 0
RTD_3_Vout
$Comp
L CONN_7 22-23-2071
U 1 1 561AA936
P 9750 3500
AR Path="/55E57BF5/561AA936" Ref="22-23-2071"  Part="1" 
AR Path="/55E62603/561AA936" Ref="P"  Part="1" 
F 0 "22-23-2071" V 9720 3500 60  0000 C CNN
F 1 "CONN_7" V 9820 3500 60  0000 C CNN
F 2 "" H 9750 3500 60  0000 C CNN
F 3 "" H 9750 3500 60  0000 C CNN
	1    9750 3500
	1    0    0    -1  
$EndComp
Text Label 8900 3300 0    39   ~ 0
GND_12V
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 561AB7E5
P 2950 3000
AR Path="/55E57BF5/561AB7E5" Ref="R"  Part="1" 
AR Path="/55E62603/561AB7E5" Ref="R"  Part="1" 
AR Path="/561AB7E5" Ref="R?"  Part="1" 
F 0 "R" V 3030 3000 40  0000 C CNN
F 1 "5" V 2957 3001 40  0000 C CNN
F 2 "~" V 2880 3000 30  0000 C CNN
F 3 "~" H 2950 3000 30  0000 C CNN
	1    2950 3000
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 561AB7EB
P 2950 4150
AR Path="/55E57BF5/561AB7EB" Ref="R"  Part="1" 
AR Path="/55E62603/561AB7EB" Ref="R"  Part="1" 
AR Path="/561AB7EB" Ref="R?"  Part="1" 
F 0 "R" V 3030 4150 40  0000 C CNN
F 1 "5" V 2957 4151 40  0000 C CNN
F 2 "~" V 2880 4150 30  0000 C CNN
F 3 "~" H 2950 4150 30  0000 C CNN
	1    2950 4150
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 561AB7F1
P 2950 5250
AR Path="/55E57BF5/561AB7F1" Ref="R"  Part="1" 
AR Path="/55E62603/561AB7F1" Ref="R"  Part="1" 
AR Path="/561AB7F1" Ref="R?"  Part="1" 
F 0 "R" V 3030 5250 40  0000 C CNN
F 1 "5" V 2957 5251 40  0000 C CNN
F 2 "~" V 2880 5250 30  0000 C CNN
F 3 "~" H 2950 5250 30  0000 C CNN
	1    2950 5250
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 561AB7F7
P 2950 6300
AR Path="/55E62603/561AB7F7" Ref="R"  Part="1" 
AR Path="/55E57BF5/561AB7F7" Ref="R"  Part="1" 
AR Path="/561AB7F7" Ref="R?"  Part="1" 
F 0 "R" V 3030 6300 40  0000 C CNN
F 1 "5" V 2957 6301 40  0000 C CNN
F 2 "~" V 2880 6300 30  0000 C CNN
F 3 "~" H 2950 6300 30  0000 C CNN
	1    2950 6300
	0    -1   -1   0   
$EndComp
Text Label 8900 3200 0    39   ~ 0
+12V
$Comp
L C-RESCUE-Project_Narwhal_Electrical C
U 1 1 56403D01
P 7950 2600
AR Path="/55E57BF5/56403D01" Ref="C"  Part="1" 
AR Path="/55E62603/56403D01" Ref="C"  Part="1" 
AR Path="/56403D01" Ref="C"  Part="1" 
F 0 "C" H 7950 2700 40  0000 L CNN
F 1 "0.1uF" H 7956 2515 40  0000 L CNN
F 2 "~" H 7988 2450 30  0000 C CNN
F 3 "~" H 7950 2600 60  0000 C CNN
	1    7950 2600
	0    -1   -1   0   
$EndComp
$Comp
L C-RESCUE-Project_Narwhal_Electrical C
U 1 1 56403F9B
P 7950 3750
AR Path="/55E57BF5/56403F9B" Ref="C"  Part="1" 
AR Path="/55E62603/56403F9B" Ref="C"  Part="1" 
AR Path="/56403F9B" Ref="C?"  Part="1" 
F 0 "C" H 7950 3850 40  0000 L CNN
F 1 "0.1uF" H 7956 3665 40  0000 L CNN
F 2 "~" H 7988 3600 30  0000 C CNN
F 3 "~" H 7950 3750 60  0000 C CNN
	1    7950 3750
	0    -1   -1   0   
$EndComp
$Comp
L C-RESCUE-Project_Narwhal_Electrical C
U 1 1 56403FA1
P 7900 4850
AR Path="/55E57BF5/56403FA1" Ref="C"  Part="1" 
AR Path="/55E62603/56403FA1" Ref="C"  Part="1" 
AR Path="/56403FA1" Ref="C?"  Part="1" 
F 0 "C" H 7900 4950 40  0000 L CNN
F 1 "0.1uF" H 7906 4765 40  0000 L CNN
F 2 "~" H 7938 4700 30  0000 C CNN
F 3 "~" H 7900 4850 60  0000 C CNN
	1    7900 4850
	0    -1   -1   0   
$EndComp
$Comp
L C-RESCUE-Project_Narwhal_Electrical C
U 1 1 56403FA7
P 7900 5900
AR Path="/55E57BF5/56403FA7" Ref="C"  Part="1" 
AR Path="/55E62603/56403FA7" Ref="C"  Part="1" 
F 0 "C" H 7900 6000 40  0000 L CNN
F 1 "0.1uF" H 7906 5815 40  0000 L CNN
F 2 "~" H 7938 5750 30  0000 C CNN
F 3 "~" H 7900 5900 60  0000 C CNN
	1    7900 5900
	0    -1   -1   0   
$EndComp
$Comp
L C-RESCUE-Project_Narwhal_Electrical C
U 1 1 57DEC465
P 7350 1550
AR Path="/55E57BF5/57DEC465" Ref="C"  Part="1" 
AR Path="/55E62603/57DEC465" Ref="C"  Part="1" 
F 0 "C" H 7350 1650 40  0000 L CNN
F 1 "10uF" H 7356 1465 40  0000 L CNN
F 2 "~" H 7388 1400 30  0000 C CNN
F 3 "~" H 7350 1550 60  0000 C CNN
	1    7350 1550
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 57DF551F
P 5450 5900
AR Path="/55E57BF5/57DF551F" Ref="R"  Part="1" 
AR Path="/55E62603/57DF551F" Ref="R"  Part="1" 
F 0 "R" V 5530 5900 40  0000 C CNN
F 1 "2000" V 5457 5901 40  0000 C CNN
F 2 "~" V 5380 5900 30  0000 C CNN
F 3 "~" H 5450 5900 30  0000 C CNN
	1    5450 5900
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 57DF560A
P 5200 6000
AR Path="/55E57BF5/57DF560A" Ref="R"  Part="1" 
AR Path="/55E62603/57DF560A" Ref="R"  Part="1" 
F 0 "R" V 5280 6000 40  0000 C CNN
F 1 "2000" V 5207 6001 40  0000 C CNN
F 2 "~" V 5130 6000 30  0000 C CNN
F 3 "~" H 5200 6000 30  0000 C CNN
	1    5200 6000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5700 2500 5650 2500
Wire Wire Line
	5650 2500 5650 2350
Wire Wire Line
	5650 2350 6200 2350
Wire Wire Line
	4100 3850 4950 3850
Wire Wire Line
	5700 3650 5650 3650
Wire Wire Line
	5650 3650 5650 3500
Wire Wire Line
	5650 3500 6200 3500
Wire Wire Line
	4100 4950 4950 4950
Wire Wire Line
	5700 4750 5650 4750
Wire Wire Line
	5650 4750 5650 4600
Wire Wire Line
	5650 4600 6200 4600
Wire Wire Line
	5700 5800 5650 5800
Wire Wire Line
	5650 5800 5650 5650
Wire Wire Line
	5650 5650 6200 5650
Wire Wire Line
	7250 2700 8300 2700
Wire Wire Line
	7250 4950 8400 4950
Wire Wire Line
	7250 4850 7700 4850
Connection ~ 7650 4850
Wire Wire Line
	4050 6100 5700 6100
Wire Wire Line
	7250 5050 7250 5150
Wire Wire Line
	5700 5150 8150 5150
Wire Wire Line
	5700 5050 5700 5150
Wire Wire Line
	7250 6100 7250 6200
Wire Wire Line
	5700 6200 8200 6200
Wire Wire Line
	5700 6100 5700 6200
Wire Wire Line
	7250 3950 7250 4050
Wire Wire Line
	5700 4050 8200 4050
Wire Wire Line
	5700 3950 5700 4050
Wire Wire Line
	7250 2800 7250 2900
Wire Wire Line
	5700 2900 8200 2900
Wire Wire Line
	5700 2800 5700 2900
Wire Wire Line
	4050 2800 5700 2800
Connection ~ 4800 2800
Wire Wire Line
	4050 5050 5700 5050
Connection ~ 4800 5050
Wire Wire Line
	8500 3300 9400 3300
Wire Wire Line
	4800 2100 8500 2100
Wire Wire Line
	8500 2100 8500 3300
Wire Wire Line
	8600 3200 9400 3200
Wire Wire Line
	8600 1300 8600 3200
Wire Wire Line
	7250 1300 8600 1300
Wire Wire Line
	6600 1950 6600 2100
Connection ~ 6600 2100
Wire Wire Line
	3450 1300 5950 1300
Connection ~ 7250 2900
Wire Wire Line
	4800 2100 4800 6300
Connection ~ 7250 4050
Connection ~ 7250 5150
Connection ~ 7250 6200
Wire Wire Line
	9400 3400 8400 3400
Wire Wire Line
	8400 3400 8400 1850
Wire Wire Line
	8400 1850 4800 1850
Wire Wire Line
	4800 1850 4800 1300
Connection ~ 4800 1300
Wire Wire Line
	8300 2700 8300 3500
Wire Wire Line
	8300 3500 9400 3500
Wire Wire Line
	7250 3850 8300 3850
Wire Wire Line
	8300 3850 8300 3600
Wire Wire Line
	8300 3600 9400 3600
Wire Wire Line
	8400 4950 8400 3700
Wire Wire Line
	8400 3700 9400 3700
Wire Wire Line
	7250 6000 8500 6000
Wire Wire Line
	8500 6000 8500 3800
Wire Wire Line
	8500 3800 9400 3800
Wire Wire Line
	8150 5150 8150 4850
Wire Wire Line
	8150 4850 8100 4850
Wire Wire Line
	8200 4050 8200 3750
Wire Wire Line
	8200 3750 8150 3750
Wire Wire Line
	7250 3750 7750 3750
Wire Wire Line
	8200 2900 8200 2600
Wire Wire Line
	8200 2600 8150 2600
Wire Wire Line
	7250 2600 7750 2600
Wire Wire Line
	6700 2350 7250 2350
Wire Wire Line
	7250 2350 7250 2500
Wire Wire Line
	6700 3500 7250 3500
Wire Wire Line
	7250 3500 7250 3650
Wire Wire Line
	6700 4600 7250 4600
Wire Wire Line
	7250 4600 7250 4750
Wire Wire Line
	7250 5900 7700 5900
Wire Wire Line
	8100 5900 8200 5900
Wire Wire Line
	8200 5900 8200 6200
Wire Wire Line
	7650 1300 7650 5900
Connection ~ 7650 5900
Connection ~ 7650 3750
Connection ~ 7650 2600
Connection ~ 7650 1300
Wire Wire Line
	3450 1300 3450 6300
Wire Wire Line
	6700 5650 7250 5650
Wire Wire Line
	7250 5650 7250 5800
Wire Wire Line
	7350 1350 7350 1300
Connection ~ 7350 1300
Wire Wire Line
	7350 1750 7350 2100
Connection ~ 7350 2100
Wire Wire Line
	5450 6000 5700 6000
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 57DF85ED
P 5450 4850
AR Path="/55E57BF5/57DF85ED" Ref="R"  Part="1" 
AR Path="/55E62603/57DF85ED" Ref="R"  Part="1" 
F 0 "R" V 5530 4850 40  0000 C CNN
F 1 "2000" V 5457 4851 40  0000 C CNN
F 2 "~" V 5380 4850 30  0000 C CNN
F 3 "~" H 5450 4850 30  0000 C CNN
	1    5450 4850
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 57DF86B6
P 5200 4950
AR Path="/55E57BF5/57DF86B6" Ref="R"  Part="1" 
AR Path="/55E62603/57DF86B6" Ref="R"  Part="1" 
F 0 "R" V 5280 4950 40  0000 C CNN
F 1 "2000" V 5207 4951 40  0000 C CNN
F 2 "~" V 5130 4950 30  0000 C CNN
F 3 "~" H 5200 4950 30  0000 C CNN
	1    5200 4950
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 57DF910E
P 5200 3850
AR Path="/55E57BF5/57DF910E" Ref="R"  Part="1" 
AR Path="/55E62603/57DF910E" Ref="R"  Part="1" 
F 0 "R" V 5280 3850 40  0000 C CNN
F 1 "2000" V 5207 3851 40  0000 C CNN
F 2 "~" V 5130 3850 30  0000 C CNN
F 3 "~" H 5200 3850 30  0000 C CNN
	1    5200 3850
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 57DF919F
P 5450 3750
AR Path="/55E57BF5/57DF919F" Ref="R"  Part="1" 
AR Path="/55E62603/57DF919F" Ref="R"  Part="1" 
F 0 "R" V 5530 3750 40  0000 C CNN
F 1 "2000" V 5457 3751 40  0000 C CNN
F 2 "~" V 5380 3750 30  0000 C CNN
F 3 "~" H 5450 3750 30  0000 C CNN
	1    5450 3750
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 57DF97AD
P 5200 2700
AR Path="/55E57BF5/57DF97AD" Ref="R"  Part="1" 
AR Path="/55E62603/57DF97AD" Ref="R"  Part="1" 
F 0 "R" V 5280 2700 40  0000 C CNN
F 1 "2000" V 5207 2701 40  0000 C CNN
F 2 "~" V 5130 2700 30  0000 C CNN
F 3 "~" H 5200 2700 30  0000 C CNN
	1    5200 2700
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 57DF9858
P 5450 2600
AR Path="/55E57BF5/57DF9858" Ref="R"  Part="1" 
AR Path="/55E62603/57DF9858" Ref="R"  Part="1" 
F 0 "R" V 5530 2600 40  0000 C CNN
F 1 "2000" V 5457 2601 40  0000 C CNN
F 2 "~" V 5380 2600 30  0000 C CNN
F 3 "~" H 5450 2600 30  0000 C CNN
	1    5450 2600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5450 4950 5700 4950
Wire Wire Line
	5450 3850 5700 3850
Wire Wire Line
	5450 2700 5700 2700
Text Notes 600  7450 0    60   ~ 0
Note 3: Molex #1 connector is #2 on RTD cable (white wire).
Text Notes 600  7750 0    60   ~ 0
Note 4: 5 Ohm resistor added such that zero deg C equals a positive voltage allowing for calibration in the software\n        (Arduino cannot read negative voltage)
Text Notes 600  7000 0    60   ~ 0
Note 1: Molex connector pin numbering convention: With female connector ears to the right, pin 1 is located at the top.\n        Pin 1 is generally set as power.
Text Notes 600  7200 0    60   ~ 0
Note 2: GND_12V is the ground from the 12V power supply.
Text Label 1300 3750 0    60   ~ 0
Red
Text Label 1300 3900 0    60   ~ 0
Red
Text Label 1300 4050 0    60   ~ 0
White
Wire Wire Line
	2000 3000 2700 3000
Wire Wire Line
	4050 3000 4150 3000
Wire Wire Line
	3200 3000 3550 3000
Connection ~ 3450 3000
Wire Wire Line
	4100 3000 4100 2700
Wire Wire Line
	4100 2700 4950 2700
Connection ~ 4100 3000
Wire Wire Line
	3550 2800 2000 2800
Wire Wire Line
	4650 3000 4800 3000
Connection ~ 4800 3000
Wire Wire Line
	2000 2900 2550 2900
Wire Wire Line
	2550 2900 2550 2600
Wire Wire Line
	2550 2600 5200 2600
Text Label 1300 4850 0    60   ~ 0
Red
Text Label 1300 5000 0    60   ~ 0
Red
Text Label 1300 5150 0    60   ~ 0
White
Text Label 1300 2800 0    60   ~ 0
Red
Text Label 1300 2950 0    60   ~ 0
Red
Text Label 1300 3100 0    60   ~ 0
White
Text Label 1300 5900 0    60   ~ 0
Red
Text Label 1300 6050 0    60   ~ 0
Red
Text Label 1300 6200 0    60   ~ 0
White
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 55E5D5C5
P 3800 5050
AR Path="/55E57BF5/55E5D5C5" Ref="R"  Part="1" 
AR Path="/55E5C9A3/55E5D5C5" Ref="R?"  Part="1" 
AR Path="/55E62603/55E5D5C5" Ref="R"  Part="1" 
AR Path="/55E5D5C5" Ref="R?"  Part="1" 
F 0 "R" V 3880 5050 40  0000 C CNN
F 1 "2000" V 3807 5051 40  0000 C CNN
F 2 "~" V 3730 5050 30  0000 C CNN
F 3 "~" H 3800 5050 30  0000 C CNN
	1    3800 5050
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-Project_Narwhal_Electrical R
U 1 1 5816CB63
P 3800 6100
F 0 "R" V 3880 6100 40  0000 C CNN
F 1 "2000" V 3807 6101 40  0000 C CNN
F 2 "~" V 3730 6100 30  0000 C CNN
F 3 "~" H 3800 6100 30  0000 C CNN
	1    3800 6100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2050 4150 2700 4150
Wire Wire Line
	3200 4150 3550 4150
Connection ~ 3450 4150
Wire Wire Line
	4050 4150 4150 4150
Wire Wire Line
	4650 4150 4800 4150
Connection ~ 4800 4150
Wire Wire Line
	4050 3950 5700 3950
Connection ~ 4800 3950
Wire Wire Line
	3550 3950 2050 3950
Wire Wire Line
	2050 4050 2500 4050
Wire Wire Line
	2500 4050 2500 3750
Wire Wire Line
	2500 3750 5200 3750
Wire Wire Line
	4100 4150 4100 3850
Connection ~ 4100 4150
Wire Wire Line
	2050 5250 2700 5250
Wire Wire Line
	3200 5250 3550 5250
Connection ~ 3450 5250
Wire Wire Line
	4050 5250 4150 5250
Wire Wire Line
	4650 5250 4800 5250
Connection ~ 4800 5250
Wire Wire Line
	4100 5250 4100 4950
Connection ~ 4100 5250
Wire Wire Line
	2050 5050 3550 5050
Wire Wire Line
	2050 5150 2500 5150
Wire Wire Line
	2500 5150 2500 4850
Wire Wire Line
	2500 4850 5200 4850
Wire Wire Line
	2050 6300 2700 6300
Wire Wire Line
	3200 6300 3550 6300
Wire Wire Line
	4050 6300 4150 6300
Wire Wire Line
	4800 6300 4650 6300
Connection ~ 4800 6100
Connection ~ 3450 6300
Wire Wire Line
	2050 6200 2500 6200
Wire Wire Line
	2500 6200 2500 5900
Wire Wire Line
	2500 5900 5200 5900
Wire Wire Line
	4100 6300 4100 6000
Wire Wire Line
	4100 6000 4950 6000
Connection ~ 4100 6300
Wire Wire Line
	2050 6100 3550 6100
$EndSCHEMATC
