EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
LIBS:74hc
LIBS:open-project
LIBS:flipdot-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74HC4514 D?
U 1 1 5AB1137A
P 1350 3250
F 0 "D?" V 1300 2950 60  0000 C CNN
F 1 "74HC4514" V 1300 2550 60  0000 C CNN
F 2 "" H 1350 3250 60  0000 C CNN
F 3 "" H 1350 3250 60  0000 C CNN
	1    1350 3250
	1    0    0    -1  
$EndComp
Text HLabel 900  3550 0    60   Input ~ 0
C1
Text HLabel 900  3450 0    60   Input ~ 0
C0
Text HLabel 900  3650 0    60   Input ~ 0
C2
Text HLabel 900  3750 0    60   Input ~ 0
Color
Text HLabel 900  4200 0    60   Input ~ 0
~E~
$Comp
L Earth #PWR?
U 1 1 5AB113B6
P 1250 2550
F 0 "#PWR?" H 1250 2300 50  0001 C CNN
F 1 "Earth" H 1250 2400 50  0001 C CNN
F 2 "" H 1250 2550 50  0001 C CNN
F 3 "" H 1250 2550 50  0001 C CNN
	1    1250 2550
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR?
U 1 1 5AB113CC
P 1400 2250
F 0 "#PWR?" H 1400 2100 50  0001 C CNN
F 1 "+5V" H 1400 2390 50  0000 C CNN
F 2 "" H 1400 2250 50  0001 C CNN
F 3 "" H 1400 2250 50  0001 C CNN
	1    1400 2250
	1    0    0    -1  
$EndComp
NoConn ~ 1800 3700
NoConn ~ 1800 2900
Wire Wire Line
	900  2350 900  3050
Wire Wire Line
	1400 2250 1400 2350
Wire Wire Line
	1400 2350 1400 2550
$Comp
L ULN2003A U?
U 1 1 5AB11445
P 2750 4100
F 0 "U?" H 2750 4625 50  0000 C CNN
F 1 "ULN2003A" H 2750 4550 50  0000 C CNN
F 2 "" H 2800 3450 50  0001 L CNN
F 3 "" H 2850 4000 50  0001 C CNN
	1    2750 4100
	1    0    0    -1  
$EndComp
$Comp
L TD62783 U?
U 1 1 5AB1158E
P 2750 3000
F 0 "U?" H 2750 3650 50  0000 C CNN
F 1 "TD62783" H 2750 3550 50  0000 C CNN
F 2 "" H 2750 3000 60  0000 C CNN
F 3 "" H 2750 3000 60  0000 C CNN
	1    2750 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 4400 1800 4400
Wire Wire Line
	1800 4300 2350 4300
Wire Wire Line
	2350 4200 1800 4200
Wire Wire Line
	1800 4100 2350 4100
Wire Wire Line
	2350 4000 1800 4000
Wire Wire Line
	1800 3900 2350 3900
Wire Wire Line
	2350 3800 1800 3800
$Comp
L Earth #PWR?
U 1 1 5AB1187E
P 2750 4800
F 0 "#PWR?" H 2750 4550 50  0001 C CNN
F 1 "Earth" H 2750 4650 50  0001 C CNN
F 2 "" H 2750 4800 50  0001 C CNN
F 3 "" H 2750 4800 50  0001 C CNN
	1    2750 4800
	1    0    0    -1  
$EndComp
$Comp
L Earth #PWR?
U 1 1 5AB118A5
P 3150 3400
F 0 "#PWR?" H 3150 3150 50  0001 C CNN
F 1 "Earth" H 3150 3250 50  0001 C CNN
F 2 "" H 3150 3400 50  0001 C CNN
F 3 "" H 3150 3400 50  0001 C CNN
	1    3150 3400
	0    -1   -1   0   
$EndComp
$Comp
L +24V #PWR?
U 1 1 5AB118B8
P 2350 3450
F 0 "#PWR?" H 2350 3300 50  0001 C CNN
F 1 "+24V" H 2350 3590 50  0000 C CNN
F 2 "" H 2350 3450 50  0001 C CNN
F 3 "" H 2350 3450 50  0001 C CNN
	1    2350 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	2350 3400 2350 3450
Wire Wire Line
	2350 3200 2200 3200
Wire Wire Line
	2200 3200 2200 3600
Wire Wire Line
	2200 3600 1800 3600
Wire Wire Line
	1800 3500 2150 3500
Wire Wire Line
	2150 3500 2150 3100
Wire Wire Line
	2150 3100 2350 3100
Wire Wire Line
	2350 3000 2100 3000
Wire Wire Line
	2100 3000 2100 3400
Wire Wire Line
	2100 3400 1800 3400
Wire Wire Line
	1800 3300 2050 3300
Wire Wire Line
	2050 3300 2050 2900
Wire Wire Line
	2050 2900 2350 2900
Wire Wire Line
	2350 2800 2000 2800
Wire Wire Line
	2000 2800 2000 3200
Wire Wire Line
	2000 3200 1800 3200
Wire Wire Line
	1800 3100 1950 3100
Wire Wire Line
	1950 3100 1950 2700
Wire Wire Line
	1950 2700 2350 2700
Wire Wire Line
	1800 3000 1900 3000
Wire Wire Line
	1900 3000 1900 2600
Wire Wire Line
	1900 2600 2350 2600
Wire Wire Line
	900  2350 1400 2350
Connection ~ 1400 2350
NoConn ~ 3150 3300
$Comp
L +24V #PWR?
U 1 1 5AB11AEC
P 3150 4650
F 0 "#PWR?" H 3150 4500 50  0001 C CNN
F 1 "+24V" H 3150 4790 50  0000 C CNN
F 2 "" H 3150 4650 50  0001 C CNN
F 3 "" H 3150 4650 50  0001 C CNN
	1    3150 4650
	-1   0    0    1   
$EndComp
Wire Wire Line
	3150 4650 3150 4600
$EndSCHEMATC
