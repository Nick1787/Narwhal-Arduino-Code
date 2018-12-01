EESchema Schematic File Version 2
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
LIBS:contrib
LIBS:valves
LIBS:NarwhalLib
LIBS:ACBoxWiring-cache
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "AC Box Wiring"
Date "2018-12-01"
Rev "6"
Comp "Project Narwhal"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L EA50-5V U?
U 1 1 57E07319
P 8750 2250
F 0 "U?" H 8750 2250 60  0001 C CNN
F 1 "EA50-5V" H 8750 2250 60  0000 C CNN
F 2 "" H 8750 2250 60  0000 C CNN
F 3 "" H 8750 2250 60  0000 C CNN
	1    8750 2250
	1    0    0    -1  
$EndComp
$Comp
L Switch_DPST Pump
U 1 1 57E073AF
P 5750 5550
F 0 "Pump" H 6050 5600 50  0000 C CNN
F 1 "Switch_DPST" H 6050 5500 50  0000 C CNN
F 2 "" H 5750 5550 50  0000 C CNN
F 3 "" H 5750 5550 50  0000 C CNN
	1    5750 5550
	1    0    0    -1  
$EndComp
$Comp
L Switch_DPST Pump
U 1 1 57E07432
P 5750 4500
F 0 "Pump" H 6050 4550 50  0000 C CNN
F 1 "Switch_DPST" H 6050 4450 50  0000 C CNN
F 2 "" H 5750 4500 50  0000 C CNN
F 3 "" H 5750 4500 50  0000 C CNN
	1    5750 4500
	1    0    0    -1  
$EndComp
$Comp
L SPST E-Stop
U 1 1 57E074A7
P 2300 2150
F 0 "E-Stop" H 2300 2250 50  0000 C CNN
F 1 "SPST" H 2300 2050 50  0000 C CNN
F 2 "" H 2300 2150 50  0000 C CNN
F 3 "" H 2300 2150 50  0000 C CNN
	1    2300 2150
	1    0    0    -1  
$EndComp
$Comp
L SPST 12V
U 1 1 57E0755E
P 4300 2150
F 0 "12V" H 4300 2250 50  0000 C CNN
F 1 "SPST" H 4300 2050 50  0000 C CNN
F 2 "" H 4300 2150 50  0000 C CNN
F 3 "" H 4300 2150 50  0000 C CNN
	1    4300 2150
	1    0    0    -1  
$EndComp
$Comp
L SPST 120V
U 1 1 57E075BA
P 4300 4300
F 0 "120V" H 4300 4400 50  0000 C CNN
F 1 "SPST" H 4300 4200 50  0000 C CNN
F 2 "" H 4300 4300 50  0000 C CNN
F 3 "" H 4300 4300 50  0000 C CNN
	1    4300 4300
	1    0    0    -1  
$EndComp
$Comp
L Pump #1
U 1 1 57E0769C
P 8450 4500
F 0 "#1" H 8450 4400 60  0001 C CNN
F 1 "Pump" H 8450 4700 60  0000 C CNN
F 2 "" H 8450 4500 60  0000 C CNN
F 3 "" H 8450 4500 60  0000 C CNN
	1    8450 4500
	1    0    0    -1  
$EndComp
$Comp
L Pump #2
U 1 1 57E0770F
P 8450 5550
F 0 "#2" H 8450 5450 60  0001 C CNN
F 1 "Pump" H 8450 5750 60  0000 C CNN
F 2 "" H 8450 5550 60  0000 C CNN
F 3 "" H 8450 5550 60  0000 C CNN
	1    8450 5550
	1    0    0    -1  
$EndComp
$Comp
L Power_Supply_with_AC Switch
U 1 1 57E07805
P 6650 3550
F 0 "Switch" H 6650 3400 60  0000 C CNN
F 1 "Power_Supply_with_AC" H 6650 3800 60  0000 C CNN
F 2 "" H 6650 3550 60  0000 C CNN
F 3 "" H 6650 3550 60  0000 C CNN
	1    6650 3550
	1    0    0    -1  
$EndComp
$Comp
L Power_Supply_with_AC Linear
U 1 1 57E078E2
P 6650 2250
F 0 "Linear" H 6650 2100 60  0000 C CNN
F 1 "Power_Supply_with_AC" H 6650 2500 60  0000 C CNN
F 2 "" H 6650 2250 60  0000 C CNN
F 3 "" H 6650 2250 60  0000 C CNN
	1    6650 2250
	1    0    0    -1  
$EndComp
Text GLabel 1550 2150 0    60   Input ~ 0
+120VAC
Text GLabel 1550 2550 0    60   Input ~ 0
Neutral_120VAC
Text GLabel 1550 3000 0    60   Input ~ 0
GND_120VAC
$Comp
L SPST Master
U 1 1 57E07B25
P 3250 2150
F 0 "Master" H 3250 2250 50  0000 C CNN
F 1 "SPST" H 3250 2050 50  0000 C CNN
F 2 "" H 3250 2150 50  0000 C CNN
F 3 "" H 3250 2150 50  0000 C CNN
	1    3250 2150
	1    0    0    -1  
$EndComp
Text GLabel 7300 4450 0    60   Input ~ 0
Neutral_120VAC
Text GLabel 7300 5650 0    60   Input ~ 0
GND_120VAC
Text GLabel 5450 4700 0    60   Input ~ 0
+5VLinear
Text GLabel 5450 5750 0    60   Input ~ 0
+5VLinear
Text GLabel 6050 4700 2    60   Input ~ 0
ToArduino
Text GLabel 6050 5750 2    60   Input ~ 0
ToArduino
Text GLabel 8150 1800 2    60   Input ~ 0
+12VLinear
Text GLabel 8150 2700 2    60   Input ~ 0
GND_12VLinear
Text GLabel 9350 2050 2    60   Input ~ 0
+5VLinear
Text GLabel 9350 2450 2    60   Input ~ 0
GND_5VLinear
Text GLabel 7800 3400 2    60   Input ~ 0
+12VSwitchMode
Text GLabel 7800 3700 2    60   Input ~ 0
GND_12VSwitchMode
$Comp
L VR MOV
U 1 1 5AEA568E
P 8300 3900
F 0 "MOV" V 8360 3854 50  0000 C TNN
F 1 "VR" V 8300 3900 50  0000 C CNN
F 2 "" H 8300 3900 50  0000 C CNN
F 3 "" H 8300 3900 50  0000 C CNN
	1    8300 3900
	0    1    1    0   
$EndComp
$Comp
L VR MOV
U 1 1 5AEA5794
P 8300 4950
F 0 "MOV" V 8360 4904 50  0000 C TNN
F 1 "VR" V 8300 4950 50  0000 C CNN
F 2 "" H 8300 4950 50  0000 C CNN
F 3 "" H 8300 4950 50  0000 C CNN
	1    8300 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	5800 2250 5550 2250
Wire Wire Line
	5550 2250 5550 3550
Wire Wire Line
	5550 2550 1550 2550
Wire Wire Line
	5550 3550 5800 3550
Connection ~ 5550 2550
Wire Wire Line
	5350 2350 5350 3650
Wire Wire Line
	5350 3650 5800 3650
Wire Wire Line
	5350 2350 5800 2350
Wire Wire Line
	4800 2150 5800 2150
Wire Wire Line
	5800 2150 5800 3450
Wire Wire Line
	3750 2150 3800 2150
Wire Wire Line
	2800 2150 3000 2150
Wire Wire Line
	1550 2150 1800 2150
Wire Wire Line
	3750 2150 3750 4300
Wire Wire Line
	3750 4300 3800 4300
Wire Wire Line
	4600 4300 5450 4300
Wire Wire Line
	4750 4300 4750 5350
Wire Wire Line
	4750 5350 5450 5350
Wire Wire Line
	7300 5650 7650 5650
Wire Wire Line
	7450 5650 7450 4600
Wire Wire Line
	7450 4600 7650 4600
Connection ~ 7450 5650
Wire Wire Line
	7300 4450 7650 4450
Wire Wire Line
	7550 3900 7550 5500
Wire Wire Line
	7550 5500 7650 5500
Connection ~ 7550 4450
Wire Wire Line
	7450 2200 8150 2200
Wire Wire Line
	8150 2200 8150 2050
Wire Wire Line
	7450 2300 8150 2300
Wire Wire Line
	8150 2300 8150 2450
Wire Wire Line
	6050 4300 7650 4300
Wire Wire Line
	7800 2300 7800 2700
Wire Wire Line
	7800 2700 8150 2700
Connection ~ 7800 2300
Wire Wire Line
	7800 2200 7800 1800
Wire Wire Line
	7800 1800 8150 1800
Connection ~ 7800 2200
Wire Wire Line
	1550 3000 7500 3000
Connection ~ 5350 3000
Wire Wire Line
	6050 5350 7650 5350
Wire Wire Line
	7450 3500 7650 3500
Wire Wire Line
	7650 3500 7650 3400
Wire Wire Line
	7650 3400 7800 3400
Wire Wire Line
	7450 3600 7650 3600
Wire Wire Line
	7650 3600 7650 3700
Wire Wire Line
	7650 3700 7800 3700
Wire Wire Line
	7500 3000 7500 2300
Connection ~ 7500 2300
Wire Wire Line
	7650 4300 7650 4100
Wire Wire Line
	7650 4100 8850 4100
Wire Wire Line
	8850 4100 8850 3900
Wire Wire Line
	8850 3900 8550 3900
Wire Wire Line
	7650 5350 7650 5150
Wire Wire Line
	7650 5150 8850 5150
Wire Wire Line
	8850 5150 8850 4950
Wire Wire Line
	8850 4950 8550 4950
Wire Wire Line
	7550 3900 8050 3900
Wire Wire Line
	7550 4950 8050 4950
Connection ~ 7550 4950
Text Notes 4950 5950 0    60   ~ 0
Arduino side of switch is normally closed (NC)
Text Notes 4950 4900 0    60   ~ 0
Arduino side of switch is normally closed (NC)
$EndSCHEMATC
