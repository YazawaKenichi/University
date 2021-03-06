EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Connector_Generic:Conn_01x02 J1
U 1 1 617A6273
P 700 1050
F 0 "J1" H 618 725 50  0000 C CNN
F 1 "Batt" H 618 816 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 700 1050 50  0001 C CNN
F 3 "~" H 700 1050 50  0001 C CNN
	1    700  1050
	-1   0    0    1   
$EndComp
$Comp
L Device:CP C2
U 1 1 617A3917
P 1450 1200
F 0 "C2" H 1568 1246 50  0000 L CNN
F 1 "100u" H 1568 1155 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_6.3x5.9" H 1488 1050 50  0001 C CNN
F 3 "~" H 1450 1200 50  0001 C CNN
	1    1450 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 617A41FF
P 1050 1200
F 0 "C1" H 1165 1246 50  0000 L CNN
F 1 "0.1u" H 1165 1155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1088 1050 50  0001 C CNN
F 3 "~" H 1050 1200 50  0001 C CNN
	1    1050 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 617A4249
P 2350 1200
F 0 "C3" H 2465 1246 50  0000 L CNN
F 1 "0.1u" H 2465 1155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2388 1050 50  0001 C CNN
F 3 "~" H 2350 1200 50  0001 C CNN
	1    2350 1200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 617A78D8
P 2350 950
F 0 "#PWR0101" H 2350 800 50  0001 C CNN
F 1 "+5V" H 2365 1123 50  0000 C CNN
F 2 "" H 2350 950 50  0001 C CNN
F 3 "" H 2350 950 50  0001 C CNN
	1    2350 950 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 617BA643
P 4800 850
F 0 "#PWR0102" H 4800 700 50  0001 C CNN
F 1 "+5V" H 4815 1023 50  0000 C CNN
F 2 "" H 4800 850 50  0001 C CNN
F 3 "" H 4800 850 50  0001 C CNN
	1    4800 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 617BAD12
P 5100 1850
F 0 "#PWR0103" H 5100 1600 50  0001 C CNN
F 1 "GND" H 5105 1677 50  0000 C CNN
F 2 "" H 5100 1850 50  0001 C CNN
F 3 "" H 5100 1850 50  0001 C CNN
	1    5100 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2450 3550 2450
$Comp
L Device:R R5
U 1 1 617CEF04
P 3900 1650
F 0 "R5" V 3693 1650 50  0000 C CNN
F 1 "1k" V 3784 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3830 1650 50  0001 C CNN
F 3 "~" H 3900 1650 50  0001 C CNN
	1    3900 1650
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 617CF7F3
P 4150 1500
F 0 "R4" V 3943 1500 50  0000 C CNN
F 1 "1k" V 4034 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4080 1500 50  0001 C CNN
F 3 "~" H 4150 1500 50  0001 C CNN
	1    4150 1500
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 617CFDC1
P 3900 1350
F 0 "R3" V 3693 1350 50  0000 C CNN
F 1 "1k" V 3784 1350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3830 1350 50  0001 C CNN
F 3 "~" H 3900 1350 50  0001 C CNN
	1    3900 1350
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 617D01B5
P 4150 1200
F 0 "R2" V 3943 1200 50  0000 C CNN
F 1 "1k" V 4034 1200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4080 1200 50  0001 C CNN
F 3 "~" H 4150 1200 50  0001 C CNN
	1    4150 1200
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 617D0671
P 3900 1050
F 0 "R1" V 3693 1050 50  0000 C CNN
F 1 "1k" V 3784 1050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3830 1050 50  0001 C CNN
F 3 "~" H 3900 1050 50  0001 C CNN
	1    3900 1050
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 1150 4400 1050
Wire Wire Line
	4400 1250 4400 1200
Wire Wire Line
	4400 1450 4400 1500
Wire Wire Line
	4400 1550 4400 1650
Entry Wire Line
	3550 1050 3450 1150
Entry Wire Line
	3550 1200 3450 1300
Entry Wire Line
	3550 1350 3450 1450
Entry Wire Line
	3550 1500 3450 1600
Entry Wire Line
	3550 1650 3450 1750
Wire Wire Line
	3700 2550 3550 2550
Wire Wire Line
	3700 2150 3550 2150
Wire Wire Line
	3700 2250 3550 2250
Wire Wire Line
	3700 2350 3550 2350
Entry Wire Line
	3550 2550 3450 2450
Entry Wire Line
	3550 2150 3450 2050
Entry Wire Line
	3550 2250 3450 2150
Entry Wire Line
	3550 2350 3450 2250
Entry Wire Line
	3550 2450 3450 2350
Text Label 3550 2550 0    50   ~ 0
ADC1
Text Label 3550 2450 0    50   ~ 0
ADC2
Text Label 3550 2350 0    50   ~ 0
ADC3
Text Label 3550 2250 0    50   ~ 0
ADC4
Text Label 3550 2150 0    50   ~ 0
ADC5
Text Label 3550 1650 0    50   ~ 0
ADC5
Text Label 3550 1500 0    50   ~ 0
ADC4
Text Label 3550 1350 0    50   ~ 0
ADC3
Text Label 3550 1200 0    50   ~ 0
ADC2
Text Label 3550 1050 0    50   ~ 0
ADC1
Wire Notes Line
	4450 950  4450 1700
Wire Notes Line
	5850 1700 5850 950 
Text Notes 4450 950  0    50   ~ 0
ADC
$Comp
L power:+3V3 #PWR0106
U 1 1 61808B06
P 2700 850
F 0 "#PWR0106" H 2700 700 50  0001 C CNN
F 1 "+3V3" H 2715 1023 50  0000 C CNN
F 2 "" H 2700 850 50  0001 C CNN
F 3 "" H 2700 850 50  0001 C CNN
	1    2700 850 
	1    0    0    -1  
$EndComp
Wire Notes Line
	4450 950  5850 950 
Wire Notes Line
	5850 1700 4450 1700
Wire Wire Line
	2700 850  2700 1050
Wire Wire Line
	4400 1650 4050 1650
Wire Wire Line
	4300 1500 4400 1500
Wire Wire Line
	4400 1200 4300 1200
Wire Wire Line
	4400 1050 4050 1050
Wire Wire Line
	4400 1150 4500 1150
Wire Wire Line
	4400 1250 4500 1250
Wire Wire Line
	4500 1350 4050 1350
Wire Wire Line
	4400 1450 4500 1450
Wire Wire Line
	4500 1550 4400 1550
Wire Wire Line
	3050 1650 2700 1650
Wire Wire Line
	2700 1500 2800 1500
Connection ~ 2700 1500
Wire Wire Line
	2700 1500 2700 1650
Wire Wire Line
	2700 1350 3050 1350
Connection ~ 2700 1350
Wire Wire Line
	2700 1350 2700 1500
Wire Wire Line
	2700 1200 2800 1200
Connection ~ 2700 1200
Wire Wire Line
	2700 1200 2700 1350
Wire Wire Line
	2700 1050 3050 1050
Connection ~ 2700 1050
Wire Wire Line
	2700 1050 2700 1200
$Comp
L original:Regulator U1
U 1 1 6184244A
P 2000 950
F 0 "U1" H 2000 1315 50  0000 C CNN
F 1 "NJM7805SDL1" H 2000 1224 50  0000 C CNN
F 2 "original:Regulator" H 2000 950 50  0001 C CNN
F 3 "" H 2000 950 50  0001 C CNN
	1    2000 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 61845925
P 900 1450
F 0 "#PWR0107" H 900 1200 50  0001 C CNN
F 1 "GND" H 905 1277 50  0000 C CNN
F 2 "" H 900 1450 50  0001 C CNN
F 3 "" H 900 1450 50  0001 C CNN
	1    900  1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  1450 900  1050
$Comp
L power:GND #PWR0108
U 1 1 618490F7
P 1050 1450
F 0 "#PWR0108" H 1050 1200 50  0001 C CNN
F 1 "GND" H 1055 1277 50  0000 C CNN
F 2 "" H 1050 1450 50  0001 C CNN
F 3 "" H 1050 1450 50  0001 C CNN
	1    1050 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  950  1050 950 
Wire Wire Line
	1050 1350 1050 1450
Wire Wire Line
	1050 1050 1050 950 
Connection ~ 1050 950 
$Comp
L power:GND #PWR0109
U 1 1 6184BB54
P 2000 1450
F 0 "#PWR0109" H 2000 1200 50  0001 C CNN
F 1 "GND" H 2005 1277 50  0000 C CNN
F 2 "" H 2000 1450 50  0001 C CNN
F 3 "" H 2000 1450 50  0001 C CNN
	1    2000 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 1450 2000 1250
$Comp
L power:GND #PWR0110
U 1 1 61850178
P 1450 1450
F 0 "#PWR0110" H 1450 1200 50  0001 C CNN
F 1 "GND" H 1455 1277 50  0000 C CNN
F 2 "" H 1450 1450 50  0001 C CNN
F 3 "" H 1450 1450 50  0001 C CNN
	1    1450 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 618501B6
P 2350 1450
F 0 "#PWR0111" H 2350 1200 50  0001 C CNN
F 1 "GND" H 2355 1277 50  0000 C CNN
F 2 "" H 2350 1450 50  0001 C CNN
F 3 "" H 2350 1450 50  0001 C CNN
	1    2350 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1350 1450 1450
Wire Wire Line
	2350 1450 2350 1350
Wire Wire Line
	2350 1050 2350 950 
Text Label 3400 2750 0    50   ~ 0
INPUT4
Text Label 3400 2650 0    50   ~ 0
INPUT3
$Comp
L power:GND #PWR0115
U 1 1 618AFE90
P 6550 4250
F 0 "#PWR0115" H 6550 4000 50  0001 C CNN
F 1 "GND" H 6555 4077 50  0000 C CNN
F 2 "" H 6550 4250 50  0001 C CNN
F 3 "" H 6550 4250 50  0001 C CNN
	1    6550 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  2850 850  2850
Connection ~ 950  2550
Wire Wire Line
	950  2550 950  2850
$Comp
L L293E:L293E U3
U 1 1 61892FC9
P 2550 3750
F 0 "U3" H 3400 4115 50  0000 C CNN
F 1 "L293E" H 3400 4024 50  0000 C CNN
F 2 "original:Socket_DIP_14pin" H 2550 4250 50  0001 L CNN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/3f/2a/59/15/61/43/45/af/CD00000058.pdf/files/CD00000058.pdf/jcr:content/translations/en.CD00000058.pdf" H 2550 4350 50  0001 L CNN
F 4 "IC" H 2550 4450 50  0001 L CNN "category"
F 5 "IC MOTOR DRIVER PAR 20-PWRDIP" H 2550 4550 50  0001 L CNN "digikey description"
F 6 "497-3622-ND" H 2550 4650 50  0001 L CNN "digikey part number"
F 7 "DIP880W50P254L2480H510Q20" H 2550 4750 50  0001 L CNN "ipc land pattern name"
F 8 "yes" H 2550 4850 50  0001 L CNN "lead free"
F 9 "322db7b24db234d9" H 2550 4950 50  0001 L CNN "library id"
F 10 "STMicroelectronics" H 2550 5050 50  0001 L CNN "manufacturer"
F 11 "511-L293E" H 2550 5150 50  0001 L CNN "mouser part number"
F 12 "PWRDIP20" H 2550 5250 50  0001 L CNN "package"
F 13 "yes" H 2550 5350 50  0001 L CNN "rohs"
F 14 "+150??C" H 2550 5450 50  0001 L CNN "temperature range high"
F 15 "-40??C" H 2550 5550 50  0001 L CNN "temperature range low"
F 16 "" H 2550 5650 50  0001 L CNN "voltage"
	1    2550 3750
	-1   0    0    1   
$EndComp
Connection ~ 2450 2350
Wire Wire Line
	2450 2250 2450 2350
Wire Wire Line
	2450 2350 2450 2450
Connection ~ 2450 2250
Wire Wire Line
	2450 2150 2450 2250
Connection ~ 950  2450
Wire Wire Line
	950  2450 950  2350
Wire Wire Line
	950  2550 950  2450
Connection ~ 950  2350
Wire Wire Line
	950  2350 950  2250
Text Label 2800 2650 2    50   ~ 0
MOTOROUT4
Text Label 2800 2750 2    50   ~ 0
MOTOROUT3
Text Label 2800 2850 2    50   ~ 0
MOTOROUT2
Text Label 2800 2950 2    50   ~ 0
MOTOROUT1
Text Label 1800 4800 2    50   ~ 0
MOTOROUT1
Entry Wire Line
	1900 4600 1800 4700
Entry Wire Line
	1900 4700 1800 4800
Entry Wire Line
	1900 5900 1800 6000
Entry Wire Line
	1900 6000 1800 6100
Wire Wire Line
	1450 5200 1600 5200
Connection ~ 1450 5200
$Comp
L power:GND #PWR0116
U 1 1 6183621D
P 1450 5200
F 0 "#PWR0116" H 1450 4950 50  0001 C CNN
F 1 "GND" H 1455 5027 50  0000 C CNN
F 2 "" H 1450 5200 50  0001 C CNN
F 3 "" H 1450 5200 50  0001 C CNN
	1    1450 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 4800 1600 4900
Connection ~ 1600 4800
Wire Wire Line
	1800 4800 1600 4800
Wire Wire Line
	1300 4700 1300 4900
Connection ~ 1300 4700
Wire Wire Line
	1800 4700 1300 4700
Wire Wire Line
	1600 4600 1600 4800
Wire Wire Line
	1300 4600 1300 4700
Wire Wire Line
	1300 5200 1450 5200
$Comp
L Connector_Generic:Conn_01x02 J11
U 1 1 617F64C7
P 1000 4800
F 0 "J11" H 1080 4792 50  0000 L CNN
F 1 "CN2" H 1080 4701 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1000 4800 50  0001 C CNN
F 3 "~" H 1000 4800 50  0001 C CNN
	1    1000 4800
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J12
U 1 1 617F5BD3
P 1000 6100
F 0 "J12" H 1080 6092 50  0000 L CNN
F 1 "CN1" H 1080 6001 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1000 6100 50  0001 C CNN
F 3 "~" H 1000 6100 50  0001 C CNN
	1    1000 6100
	-1   0    0    1   
$EndComp
Wire Wire Line
	2700 3750 2450 3750
Wire Wire Line
	2450 3650 2700 3650
$Comp
L power:GND #PWR0117
U 1 1 617AE477
P 3150 4250
F 0 "#PWR0117" H 3150 4000 50  0001 C CNN
F 1 "GND" H 3155 4077 50  0000 C CNN
F 2 "" H 3150 4250 50  0001 C CNN
F 3 "" H 3150 4250 50  0001 C CNN
	1    3150 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener D8
U 1 1 617ADE24
P 3150 4100
F 0 "D8" V 3104 4180 50  0000 L CNN
F 1 "3.3V" V 3195 4180 50  0000 L CNN
F 2 "original:SOD323F" H 3150 4100 50  0001 C CNN
F 3 "~" H 3150 4100 50  0001 C CNN
	1    3150 4100
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 617ACB72
P 3150 3800
F 0 "R7" H 3220 3846 50  0000 L CNN
F 1 "1k" H 3220 3755 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3080 3800 50  0001 C CNN
F 3 "~" H 3150 3800 50  0001 C CNN
	1    3150 3800
	1    0    0    -1  
$EndComp
Text Label 2700 3450 2    50   ~ 0
INPUT1
Text Label 2700 3350 2    50   ~ 0
INPUT2
Text Label 2700 3250 2    50   ~ 0
INPUT3
Text Label 2700 3150 2    50   ~ 0
INPUT4
Entry Wire Line
	2700 3150 2800 3250
Entry Wire Line
	2700 3250 2800 3350
Entry Wire Line
	2700 3350 2800 3450
Entry Wire Line
	2700 3450 2800 3550
Entry Wire Line
	2800 2650 2900 2750
Entry Wire Line
	2800 2750 2900 2850
Entry Wire Line
	2800 2850 2900 2950
Entry Wire Line
	2800 2950 2900 3050
Wire Wire Line
	2450 3150 2700 3150
Wire Wire Line
	2700 3250 2450 3250
Wire Wire Line
	2450 2650 2800 2650
Wire Wire Line
	2450 2750 2800 2750
Wire Wire Line
	2450 2850 2800 2850
Wire Wire Line
	2450 2950 2800 2950
Wire Wire Line
	4950 3550 5250 3550
Wire Wire Line
	5250 3650 4950 3650
Text Label 5250 3550 2    50   ~ 0
INPUT2
Text Label 5250 3650 2    50   ~ 0
INPUT1
Entry Wire Line
	5250 3650 5350 3750
Entry Wire Line
	5250 3550 5350 3650
Wire Wire Line
	2700 3650 2700 3750
Wire Wire Line
	2700 3650 3000 3650
Wire Wire Line
	3000 3650 3000 3950
Wire Wire Line
	3000 3950 3150 3950
Connection ~ 2700 3650
Connection ~ 3150 3950
$Comp
L power:GND #PWR0118
U 1 1 619430EE
P 850 2850
F 0 "#PWR0118" H 850 2600 50  0001 C CNN
F 1 "GND" H 855 2677 50  0000 C CNN
F 2 "" H 850 2850 50  0001 C CNN
F 3 "" H 850 2850 50  0001 C CNN
	1    850  2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 619436E2
P 2450 2450
F 0 "#PWR0119" H 2450 2200 50  0001 C CNN
F 1 "GND" H 2455 2277 50  0000 C CNN
F 2 "" H 2450 2450 50  0001 C CNN
F 3 "" H 2450 2450 50  0001 C CNN
	1    2450 2450
	1    0    0    -1  
$EndComp
Connection ~ 2450 2450
$Comp
L Device:C C4
U 1 1 61944F38
P 700 2300
F 0 "C4" H 815 2346 50  0000 L CNN
F 1 "0.1u" H 815 2255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 738 2150 50  0001 C CNN
F 3 "~" H 700 2300 50  0001 C CNN
	1    700  2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 619455C6
P 700 2450
F 0 "#PWR0120" H 700 2200 50  0001 C CNN
F 1 "GND" H 705 2277 50  0000 C CNN
F 2 "" H 700 2450 50  0001 C CNN
F 3 "" H 700 2450 50  0001 C CNN
	1    700  2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  2150 800  2150
Wire Wire Line
	1300 6500 1450 6500
Wire Wire Line
	1300 5900 1300 6000
Wire Wire Line
	1600 5900 1600 6100
Wire Wire Line
	1800 6000 1300 6000
Connection ~ 1300 6000
Wire Wire Line
	1300 6000 1300 6200
Wire Wire Line
	1800 6100 1600 6100
Connection ~ 1600 6100
Wire Wire Line
	1600 6100 1600 6200
$Comp
L power:GND #PWR0121
U 1 1 6183584C
P 1450 6500
F 0 "#PWR0121" H 1450 6250 50  0001 C CNN
F 1 "GND" H 1455 6327 50  0000 C CNN
F 2 "" H 1450 6500 50  0001 C CNN
F 3 "" H 1450 6500 50  0001 C CNN
	1    1450 6500
	1    0    0    -1  
$EndComp
Connection ~ 1450 6500
Wire Wire Line
	1450 6500 1600 6500
Text Label 1800 6100 2    50   ~ 0
MOTOROUT3
Text Label 1800 6000 2    50   ~ 0
MOTOROUT4
Wire Wire Line
	1200 6000 1300 6000
Wire Wire Line
	1200 6100 1600 6100
Wire Wire Line
	1200 4700 1300 4700
Wire Wire Line
	1200 4800 1600 4800
Wire Bus Line
	2900 4100 1900 4100
Wire Wire Line
	3400 2650 3700 2650
Entry Wire Line
	3400 2650 3300 2750
Entry Wire Line
	3400 2750 3300 2850
Entry Bus Bus
	3300 4450 3200 4550
$Comp
L power:+5V #PWR0122
U 1 1 619C72FB
P 9150 850
F 0 "#PWR0122" H 9150 700 50  0001 C CNN
F 1 "+5V" H 9165 1023 50  0000 C CNN
F 2 "" H 9150 850 50  0001 C CNN
F 3 "" H 9150 850 50  0001 C CNN
	1    9150 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 619C7301
P 9450 1850
F 0 "#PWR0123" H 9450 1600 50  0001 C CNN
F 1 "GND" H 9455 1677 50  0000 C CNN
F 2 "" H 9450 1850 50  0001 C CNN
F 3 "" H 9450 1850 50  0001 C CNN
	1    9450 1850
	1    0    0    -1  
$EndComp
Wire Notes Line
	8800 950  8800 1700
Wire Notes Line
	10200 1700 10200 950 
Text Notes 8800 950  0    50   ~ 0
GPIO
Wire Notes Line
	8800 950  10200 950 
Wire Notes Line
	10200 1700 8800 1700
$Comp
L power:+5V #PWR0124
U 1 1 619CD3CA
P 7050 850
F 0 "#PWR0124" H 7050 700 50  0001 C CNN
F 1 "+5V" H 7065 1023 50  0000 C CNN
F 2 "" H 7050 850 50  0001 C CNN
F 3 "" H 7050 850 50  0001 C CNN
	1    7050 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0125
U 1 1 619CD3D0
P 7350 1850
F 0 "#PWR0125" H 7350 1600 50  0001 C CNN
F 1 "GND" H 7355 1677 50  0000 C CNN
F 2 "" H 7350 1850 50  0001 C CNN
F 3 "" H 7350 1850 50  0001 C CNN
	1    7350 1850
	1    0    0    -1  
$EndComp
Text Notes 6700 950  0    50   ~ 0
SERVO\n
Wire Notes Line
	6700 950  8100 950 
Wire Notes Line
	8100 1650 6700 1650
Entry Wire Line
	8550 1150 8450 1250
Entry Wire Line
	8550 1250 8450 1350
Entry Wire Line
	8550 1350 8450 1450
Entry Wire Line
	8550 1450 8450 1550
Entry Wire Line
	8550 1550 8450 1650
Entry Wire Line
	8350 2650 8450 2550
Entry Wire Line
	8350 2850 8450 2750
Entry Wire Line
	8350 2950 8450 2850
Entry Wire Line
	8350 3150 8450 3050
Entry Wire Line
	8350 3250 8450 3150
Wire Wire Line
	4950 2750 5950 2750
Wire Wire Line
	5950 3850 6150 3850
Wire Wire Line
	4950 3050 5850 3050
Wire Wire Line
	5850 4050 6150 4050
Entry Wire Line
	6250 2250 6350 2150
Entry Wire Line
	6250 2350 6350 2250
Entry Wire Line
	6250 3350 6350 3250
Entry Wire Line
	6250 3450 6350 3350
Entry Wire Line
	6450 1150 6350 1250
Entry Wire Line
	6450 1250 6350 1350
Entry Wire Line
	6450 1350 6350 1450
Entry Wire Line
	6450 1450 6350 1550
Wire Wire Line
	8550 1150 8850 1150
Wire Wire Line
	8550 1250 8850 1250
Wire Wire Line
	8550 1350 8850 1350
Wire Wire Line
	8550 1450 8850 1450
Wire Wire Line
	8550 1550 8850 1550
Wire Wire Line
	6450 1450 6750 1450
Wire Wire Line
	6450 1350 6750 1350
Wire Wire Line
	6450 1250 6750 1250
Wire Wire Line
	6450 1150 6750 1150
Wire Wire Line
	5950 2750 5950 3850
Wire Wire Line
	5850 3050 5850 4050
Wire Wire Line
	2450 3350 2700 3350
Wire Wire Line
	2700 3450 2450 3450
Text Label 8550 1150 0    50   ~ 0
GPIO1
Text Label 8550 1250 0    50   ~ 0
GPIO2
Text Label 8550 1350 0    50   ~ 0
GPIO3
Text Label 8550 1450 0    50   ~ 0
GPIO4
Text Label 8550 1550 0    50   ~ 0
GPIO5
Text Label 6450 1150 0    50   ~ 0
SERVO1
Text Label 6450 1250 0    50   ~ 0
SERVO2
Text Label 6450 1350 0    50   ~ 0
SERVO3
Text Label 6450 1450 0    50   ~ 0
SERVO4
Text Label 8350 2650 2    50   ~ 0
GPIO1
Text Label 8350 2850 2    50   ~ 0
GPIO2
Text Label 8350 2950 2    50   ~ 0
GPIO3
Text Label 8350 3150 2    50   ~ 0
GPIO4
Text Label 8350 3250 2    50   ~ 0
GPIO5
Entry Bus Bus
	8450 2450 8550 2350
Entry Bus Bus
	8900 2350 9000 2450
Text Label 9100 2600 0    50   ~ 0
GPIO1
Text Label 9100 2700 0    50   ~ 0
GPIO2
Text Label 9100 2800 0    50   ~ 0
GPIO3
Text Label 9100 2900 0    50   ~ 0
GPIO4
Text Label 9100 3000 0    50   ~ 0
GPIO5
Wire Wire Line
	9350 2600 9100 2600
Wire Wire Line
	9350 2700 9100 2700
Wire Wire Line
	9100 2800 9350 2800
Wire Wire Line
	9350 2900 9100 2900
Wire Wire Line
	9100 3000 9350 3000
Entry Wire Line
	9000 2500 9100 2600
Entry Wire Line
	9000 2500 9100 2600
Entry Wire Line
	9000 2600 9100 2700
Entry Wire Line
	9000 2700 9100 2800
Entry Wire Line
	9000 2800 9100 2900
Entry Wire Line
	9000 2900 9100 3000
$Comp
L power:GND #PWR0126
U 1 1 61D83361
P 10050 3300
F 0 "#PWR0126" H 10050 3050 50  0001 C CNN
F 1 "GND" V 10055 3172 50  0000 R CNN
F 2 "" H 10050 3300 50  0001 C CNN
F 3 "" H 10050 3300 50  0001 C CNN
	1    10050 3300
	0    -1   -1   0   
$EndComp
Text Label 10300 2600 2    50   ~ 0
OUT1
Text Label 10300 2700 2    50   ~ 0
OUT2
Text Label 10300 2800 2    50   ~ 0
OUT3
Text Label 10300 2900 2    50   ~ 0
OUT4
Text Label 10300 3000 2    50   ~ 0
OUT5
Wire Wire Line
	10300 2600 10050 2600
Wire Wire Line
	10050 2700 10300 2700
Wire Wire Line
	10300 2800 10050 2800
Wire Wire Line
	10050 2900 10300 2900
Wire Wire Line
	10300 3000 10050 3000
Entry Wire Line
	10300 2600 10400 2700
Entry Wire Line
	10300 2700 10400 2800
Entry Wire Line
	10300 2800 10400 2900
Entry Wire Line
	10300 2900 10400 3000
Entry Wire Line
	10300 3000 10400 3100
Wire Bus Line
	8550 2350 8900 2350
$Comp
L Device:LED D6
U 1 1 61DF1B0A
P 9900 3750
F 0 "D6" H 9893 3495 50  0000 C CNN
F 1 "LED" H 9893 3586 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 9900 3750 50  0001 C CNN
F 3 "~" H 9900 3750 50  0001 C CNN
	1    9900 3750
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D7
U 1 1 61DF5041
P 9600 3950
F 0 "D7" H 9593 3695 50  0000 C CNN
F 1 "LED" H 9593 3786 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 9600 3950 50  0001 C CNN
F 3 "~" H 9600 3950 50  0001 C CNN
	1    9600 3950
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D9
U 1 1 61DF592E
P 9900 4150
F 0 "D9" H 9893 3895 50  0000 C CNN
F 1 "LED" H 9893 3986 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 9900 4150 50  0001 C CNN
F 3 "~" H 9900 4150 50  0001 C CNN
	1    9900 4150
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D10
U 1 1 61DF5E84
P 9600 4350
F 0 "D10" H 9593 4095 50  0000 C CNN
F 1 "LED" H 9593 4186 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 9600 4350 50  0001 C CNN
F 3 "~" H 9600 4350 50  0001 C CNN
	1    9600 4350
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D13
U 1 1 61DF6942
P 9900 4550
F 0 "D13" H 9893 4295 50  0000 C CNN
F 1 "LED" H 9893 4386 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 9900 4550 50  0001 C CNN
F 3 "~" H 9900 4550 50  0001 C CNN
	1    9900 4550
	-1   0    0    1   
$EndComp
Entry Wire Line
	10400 4450 10300 4550
Entry Wire Line
	10400 4250 10300 4350
Entry Wire Line
	10400 4050 10300 4150
Entry Wire Line
	10400 3850 10300 3950
Entry Wire Line
	10400 3650 10300 3750
Wire Wire Line
	10050 3750 10300 3750
Wire Wire Line
	10300 3950 9750 3950
Wire Wire Line
	10050 4150 10300 4150
Wire Wire Line
	10300 4350 9750 4350
Wire Wire Line
	10050 4550 10300 4550
$Comp
L Device:R R11
U 1 1 61E93236
P 9350 4550
F 0 "R11" V 9143 4550 50  0000 C CNN
F 1 "RLED" V 9234 4550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9280 4550 50  0001 C CNN
F 3 "~" H 9350 4550 50  0001 C CNN
	1    9350 4550
	0    1    1    0   
$EndComp
$Comp
L Device:R R10
U 1 1 61E9386C
P 9100 4350
F 0 "R10" V 8893 4350 50  0000 C CNN
F 1 "RLED" V 8984 4350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9030 4350 50  0001 C CNN
F 3 "~" H 9100 4350 50  0001 C CNN
	1    9100 4350
	0    1    1    0   
$EndComp
$Comp
L Device:R R9
U 1 1 61E93C3D
P 9350 4150
F 0 "R9" V 9143 4150 50  0000 C CNN
F 1 "RLED" V 9234 4150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9280 4150 50  0001 C CNN
F 3 "~" H 9350 4150 50  0001 C CNN
	1    9350 4150
	0    1    1    0   
$EndComp
$Comp
L Device:R R8
U 1 1 61E9443E
P 9100 3950
F 0 "R8" V 8893 3950 50  0000 C CNN
F 1 "RLED" V 8984 3950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9030 3950 50  0001 C CNN
F 3 "~" H 9100 3950 50  0001 C CNN
	1    9100 3950
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 61E947DA
P 9350 3750
F 0 "R6" V 9143 3750 50  0000 C CNN
F 1 "RLED" V 9234 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9280 3750 50  0001 C CNN
F 3 "~" H 9350 3750 50  0001 C CNN
	1    9350 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	9500 3750 9750 3750
Wire Wire Line
	9450 3950 9250 3950
Wire Wire Line
	9500 4150 9750 4150
Wire Wire Line
	9450 4350 9250 4350
Wire Wire Line
	9500 4550 9750 4550
$Comp
L power:+5V #PWR0128
U 1 1 61EC7C16
P 8850 3450
F 0 "#PWR0128" H 8850 3300 50  0001 C CNN
F 1 "+5V" H 8865 3623 50  0000 C CNN
F 2 "" H 8850 3450 50  0001 C CNN
F 3 "" H 8850 3450 50  0001 C CNN
	1    8850 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 3450 8850 3750
Wire Wire Line
	8850 4550 9200 4550
Wire Wire Line
	8950 4350 8850 4350
Connection ~ 8850 4350
Wire Wire Line
	8850 4350 8850 4550
Wire Wire Line
	8950 3950 8850 3950
Connection ~ 8850 3950
Wire Wire Line
	8850 3950 8850 4150
Wire Wire Line
	9200 3750 8850 3750
Connection ~ 8850 3750
Wire Wire Line
	8850 3750 8850 3950
$Comp
L power:+5V #PWR0129
U 1 1 61EF2B81
P 9150 1950
F 0 "#PWR0129" H 9150 1800 50  0001 C CNN
F 1 "+5V" V 9165 2078 50  0000 L CNN
F 2 "" H 9150 1950 50  0001 C CNN
F 3 "" H 9150 1950 50  0001 C CNN
	1    9150 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 2250 4950 2250
Wire Wire Line
	4950 2350 6250 2350
Wire Wire Line
	6250 3350 4950 3350
Wire Wire Line
	4950 3450 6250 3450
Wire Wire Line
	8350 2950 4950 2950
Wire Wire Line
	4950 2850 8350 2850
Wire Wire Line
	8350 2650 4950 2650
Wire Notes Line
	8100 950  8100 1650
Wire Notes Line
	6700 1650 6700 950 
Wire Wire Line
	9200 4150 8850 4150
Connection ~ 8850 4150
Wire Wire Line
	8850 4150 8850 4350
$Comp
L 74HC04N:SN74HC04PWR U2
U 1 1 618131F2
P 9700 2850
F 0 "U2" H 9700 3565 50  0000 C CNN
F 1 "SN74HC04PWR" H 9700 3474 50  0000 C CNN
F 2 "original:TSSOP_P0.65mm" H 10050 2900 50  0001 C CNN
F 3 "" H 10050 2900 50  0001 C CNN
	1    9700 2850
	1    0    0    -1  
$EndComp
Text Notes 2900 700  0    50   ~ 0
1N4148W:???????????????????????? 0.715 V ??????????????? 1.0mA ???????????????????????????????????????\n???????????????????????????????????????????????????
$Comp
L Diode:1N4148W D1
U 1 1 61832435
P 3200 1050
F 0 "D1" H 3200 1267 50  0000 C CNN
F 1 "1N4148W" H 3200 1176 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 3200 875 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 3200 1050 50  0001 C CNN
	1    3200 1050
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148W D2
U 1 1 61837FB9
P 2950 1200
F 0 "D2" H 2950 1417 50  0000 C CNN
F 1 "1N4148W" H 2950 1326 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 2950 1025 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2950 1200 50  0001 C CNN
	1    2950 1200
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148W D3
U 1 1 61838464
P 3200 1350
F 0 "D3" H 3200 1567 50  0000 C CNN
F 1 "1N4148W" H 3200 1476 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 3200 1175 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 3200 1350 50  0001 C CNN
	1    3200 1350
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148W D4
U 1 1 618388F1
P 2950 1500
F 0 "D4" H 2950 1717 50  0000 C CNN
F 1 "1N4148W" H 2950 1626 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 2950 1325 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2950 1500 50  0001 C CNN
	1    2950 1500
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148W D5
U 1 1 61838DA1
P 3200 1650
F 0 "D5" H 3200 1867 50  0000 C CNN
F 1 "1N4148W" H 3200 1776 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 3200 1475 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 3200 1650 50  0001 C CNN
	1    3200 1650
	1    0    0    -1  
$EndComp
$Comp
L MCU_ST_STM32F3:STM32F303K8Tx U4
U 1 1 6185B098
P 3400 6500
F 0 "U4" H 3350 5411 50  0000 C CNN
F 1 "STM32F303K8Tx" H 3350 5320 50  0000 C CNN
F 2 "Package_QFP:LQFP-32_7x7mm_P0.8mm" H 2900 5600 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00092070.pdf" H 3400 6500 50  0001 C CNN
	1    3400 6500
	1    0    0    -1  
$EndComp
Text GLabel 3900 5800 2    50   Input ~ 0
PA0
Text GLabel 3900 5900 2    50   Input ~ 0
PA1
Text GLabel 3900 6100 2    50   Input ~ 0
PA3
Text GLabel 3900 6200 2    50   Input ~ 0
PA4
Text GLabel 3900 6300 2    50   Input ~ 0
PA5
Text GLabel 3900 6400 2    50   Input ~ 0
PA6
Text GLabel 3900 6500 2    50   Input ~ 0
PA7
Text GLabel 3900 6600 2    50   Input ~ 0
PA8
Text GLabel 3900 6700 2    50   Input ~ 0
PA9
Text GLabel 2800 6700 0    50   Input ~ 0
PB0
Text GLabel 2800 6800 0    50   Input ~ 0
PB1
Text GLabel 2800 6400 0    50   Input ~ 0
PF0
Text GLabel 2800 6500 0    50   Input ~ 0
PF1
Text Label 10300 3750 2    50   ~ 0
OUT1
Text Label 10300 3950 2    50   ~ 0
OUT2
Text Label 10300 4150 2    50   ~ 0
OUT3
Text Label 10300 4350 2    50   ~ 0
OUT4
Text Label 10300 4550 2    50   ~ 0
OUT5
Text Label 6250 3350 2    50   ~ 0
SERVO1
Text Label 6250 2250 2    50   ~ 0
SERVO2
Text Label 6250 2350 2    50   ~ 0
SERVO3
Text Label 6250 3450 2    50   ~ 0
SERVO4
$Comp
L Device:R R13
U 1 1 61953B3A
P 2650 6000
F 0 "R13" V 2443 6000 50  0000 C CNN
F 1 "10k" V 2534 6000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2580 6000 50  0001 C CNN
F 3 "~" H 2650 6000 50  0001 C CNN
	1    2650 6000
	0    1    1    0   
$EndComp
Text GLabel 3700 2750 2    50   Input ~ 0
PA3
Text GLabel 3700 2650 2    50   Input ~ 0
PA1
Text GLabel 4950 3650 0    50   Input ~ 0
PB4
Text GLabel 4950 3550 0    50   Input ~ 0
PB5
Text GLabel 4950 3450 0    50   Input ~ 0
PA11
Text GLabel 4950 3350 0    50   Input ~ 0
PA8
Text GLabel 4950 2850 0    50   Input ~ 0
PB7
Text GLabel 4950 2750 0    50   Input ~ 0
PB0
Text GLabel 4950 2350 0    50   Input ~ 0
PA10
Text GLabel 4950 2250 0    50   Input ~ 0
PA9
$Comp
L power:GND #PWR0130
U 1 1 61954724
P 2500 6000
F 0 "#PWR0130" H 2500 5750 50  0001 C CNN
F 1 "GND" V 2505 5872 50  0000 R CNN
F 2 "" H 2500 6000 50  0001 C CNN
F 3 "" H 2500 6000 50  0001 C CNN
	1    2500 6000
	0    1    1    0   
$EndComp
$Comp
L original:Filter FB1
U 1 1 619B4AC8
P 3500 5200
F 0 "FB1" H 3578 5246 50  0000 L CNN
F 1 "Filter" H 3578 5155 50  0000 L CNN
F 2 "Inductor_SMD:L_0603_1608Metric" H 3500 5200 50  0001 C CNN
F 3 "" H 3500 5200 50  0001 C CNN
	1    3500 5200
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0131
U 1 1 619C0739
P 3500 4950
F 0 "#PWR0131" H 3500 4800 50  0001 C CNN
F 1 "+3V3" H 3515 5123 50  0000 C CNN
F 2 "" H 3500 4950 50  0001 C CNN
F 3 "" H 3500 4950 50  0001 C CNN
	1    3500 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 4950 3400 4950
Wire Wire Line
	3300 4950 3300 5600
Connection ~ 3500 4950
Wire Wire Line
	3400 4950 3400 5600
Connection ~ 3400 4950
Wire Wire Line
	3400 4950 3300 4950
Wire Wire Line
	3300 7500 3350 7500
$Comp
L power:GND #PWR0132
U 1 1 61A61B4F
P 3350 7500
F 0 "#PWR0132" H 3350 7250 50  0001 C CNN
F 1 "GND" H 3355 7327 50  0000 C CNN
F 2 "" H 3350 7500 50  0001 C CNN
F 3 "" H 3350 7500 50  0001 C CNN
	1    3350 7500
	1    0    0    -1  
$EndComp
Connection ~ 3350 7500
Wire Wire Line
	3350 7500 3400 7500
$Comp
L Connector_Generic:Conn_01x05 J14
U 1 1 61A62597
P 5500 7000
F 0 "J14" H 5580 7042 50  0000 L CNN
F 1 "SWD" H 5580 6951 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 5500 7000 50  0001 C CNN
F 3 "~" H 5500 7000 50  0001 C CNN
	1    5500 7000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J13
U 1 1 61A62BE6
P 5250 5600
F 0 "J13" H 5330 5642 50  0000 L CNN
F 1 "UART2" H 5330 5551 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 5250 5600 50  0001 C CNN
F 3 "~" H 5250 5600 50  0001 C CNN
	1    5250 5600
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0133
U 1 1 61A8BB2E
P 5300 6800
F 0 "#PWR0133" H 5300 6650 50  0001 C CNN
F 1 "+3V3" V 5315 6928 50  0000 L CNN
F 2 "" H 5300 6800 50  0001 C CNN
F 3 "" H 5300 6800 50  0001 C CNN
	1    5300 6800
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR0134
U 1 1 61A8BBE8
P 5050 5400
F 0 "#PWR0134" H 5050 5250 50  0001 C CNN
F 1 "+3V3" V 5065 5528 50  0000 L CNN
F 2 "" H 5050 5400 50  0001 C CNN
F 3 "" H 5050 5400 50  0001 C CNN
	1    5050 5400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0135
U 1 1 61A8CA1A
P 5300 7000
F 0 "#PWR0135" H 5300 6750 50  0001 C CNN
F 1 "GND" V 5305 6872 50  0000 R CNN
F 2 "" H 5300 7000 50  0001 C CNN
F 3 "" H 5300 7000 50  0001 C CNN
	1    5300 7000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0136
U 1 1 61A8CD3D
P 5050 5800
F 0 "#PWR0136" H 5050 5550 50  0001 C CNN
F 1 "GND" V 5055 5672 50  0000 R CNN
F 2 "" H 5050 5800 50  0001 C CNN
F 3 "" H 5050 5800 50  0001 C CNN
	1    5050 5800
	0    1    1    0   
$EndComp
$Comp
L Device:R R14
U 1 1 61AA6398
P 4400 6500
F 0 "R14" H 4470 6546 50  0000 L CNN
F 1 "100k" H 4470 6455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4330 6500 50  0001 C CNN
F 3 "~" H 4400 6500 50  0001 C CNN
	1    4400 6500
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0137
U 1 1 61AA6CCC
P 4400 6350
F 0 "#PWR0137" H 4400 6200 50  0001 C CNN
F 1 "+3V3" H 4415 6523 50  0000 C CNN
F 2 "" H 4400 6350 50  0001 C CNN
F 3 "" H 4400 6350 50  0001 C CNN
	1    4400 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 6650 4400 6900
Wire Wire Line
	3900 7200 4400 7200
Wire Wire Line
	3900 7100 4850 7100
Wire Wire Line
	2250 5800 2250 6150
Wire Wire Line
	2350 6150 2250 6150
Wire Wire Line
	2350 6550 2250 6550
Connection ~ 2250 6150
Wire Wire Line
	2250 5800 2800 5800
$Comp
L Device:C C6
U 1 1 61B2D8E9
P 2100 6350
F 0 "C6" H 2215 6396 50  0000 L CNN
F 1 "0.1u" H 2215 6305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2138 6200 50  0001 C CNN
F 3 "~" H 2100 6350 50  0001 C CNN
	1    2100 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 6150 2100 6150
Wire Wire Line
	2100 6150 2100 6200
Wire Wire Line
	2100 6500 2100 6550
Wire Wire Line
	2100 6550 2250 6550
Connection ~ 2250 6550
Wire Wire Line
	2250 6550 2250 6700
$Comp
L power:GND #PWR0138
U 1 1 61B5779C
P 2250 6700
F 0 "#PWR0138" H 2250 6450 50  0001 C CNN
F 1 "GND" H 2255 6527 50  0000 C CNN
F 2 "" H 2250 6700 50  0001 C CNN
F 3 "" H 2250 6700 50  0001 C CNN
	1    2250 6700
	1    0    0    -1  
$EndComp
Text GLabel 2250 5800 0    50   Input ~ 0
nRST
Text GLabel 5300 7200 0    50   Input ~ 0
nRST
Text GLabel 5050 5600 0    50   Input ~ 0
RX
Text GLabel 5050 5700 0    50   Input ~ 0
TX
Text GLabel 3900 6000 2    50   Input ~ 0
TX
Text GLabel 3900 7300 2    50   Input ~ 0
RX
Wire Wire Line
	2250 5800 2250 5650
Connection ~ 2250 5800
$Comp
L Device:R R12
U 1 1 61B83698
P 2250 5500
F 0 "R12" H 2320 5546 50  0000 L CNN
F 1 "10k" H 2320 5455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2180 5500 50  0001 C CNN
F 3 "~" H 2250 5500 50  0001 C CNN
	1    2250 5500
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0139
U 1 1 61B848EC
P 2250 5350
F 0 "#PWR0139" H 2250 5200 50  0001 C CNN
F 1 "+3V3" H 2265 5523 50  0000 C CNN
F 2 "" H 2250 5350 50  0001 C CNN
F 3 "" H 2250 5350 50  0001 C CNN
	1    2250 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R15
U 1 1 61B8599C
P 4850 6500
F 0 "R15" H 4920 6546 50  0000 L CNN
F 1 "100k" H 4920 6455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4780 6500 50  0001 C CNN
F 3 "~" H 4850 6500 50  0001 C CNN
	1    4850 6500
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0140
U 1 1 61B859A2
P 4850 6350
F 0 "#PWR0140" H 4850 6200 50  0001 C CNN
F 1 "+3V3" H 4865 6523 50  0000 C CNN
F 2 "" H 4850 6350 50  0001 C CNN
F 3 "" H 4850 6350 50  0001 C CNN
	1    4850 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 6650 4850 7100
Connection ~ 4850 7100
Wire Wire Line
	4850 7100 5300 7100
Wire Wire Line
	5300 6900 4650 6900
Connection ~ 4400 6900
Wire Wire Line
	4400 6900 4400 7200
Wire Wire Line
	5050 5500 4650 5500
Wire Wire Line
	4650 5500 4650 6900
Connection ~ 4650 6900
Wire Wire Line
	4650 6900 4400 6900
$Comp
L Diode:1N4148W D14
U 1 1 61BFCB93
P 1300 5050
F 0 "D14" V 1254 5130 50  0000 L CNN
F 1 "1N4148W" V 1345 5130 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1300 4875 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1300 5050 50  0001 C CNN
	1    1300 5050
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148W D15
U 1 1 61BFCC1C
P 1600 5050
F 0 "D15" V 1554 5130 50  0000 L CNN
F 1 "1N4148W" V 1645 5130 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1600 4875 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1600 5050 50  0001 C CNN
	1    1600 5050
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148W D17
U 1 1 61BFCD4D
P 1600 5750
F 0 "D17" V 1554 5830 50  0000 L CNN
F 1 "1N4148W" V 1645 5830 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1600 5575 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1600 5750 50  0001 C CNN
	1    1600 5750
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148W D11
U 1 1 61BFCF88
P 1300 4450
F 0 "D11" V 1254 4530 50  0000 L CNN
F 1 "1N4148W" V 1345 4530 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1300 4275 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1300 4450 50  0001 C CNN
	1    1300 4450
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148W D12
U 1 1 61C0C83E
P 1600 4450
F 0 "D12" V 1554 4530 50  0000 L CNN
F 1 "1N4148W" V 1645 4530 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1600 4275 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1600 4450 50  0001 C CNN
	1    1600 4450
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148W D16
U 1 1 61C0CB00
P 1300 5750
F 0 "D16" V 1254 5830 50  0000 L CNN
F 1 "1N4148W" V 1345 5830 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1300 5575 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1300 5750 50  0001 C CNN
	1    1300 5750
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148W D18
U 1 1 61C0CC31
P 1300 6350
F 0 "D18" V 1254 6430 50  0000 L CNN
F 1 "1N4148W" V 1345 6430 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1300 6175 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1300 6350 50  0001 C CNN
	1    1300 6350
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148W D19
U 1 1 61C0CEE6
P 1600 6350
F 0 "D19" V 1554 6430 50  0000 L CNN
F 1 "1N4148W" V 1645 6430 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1600 6175 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1600 6350 50  0001 C CNN
	1    1600 6350
	0    1    1    0   
$EndComp
Text GLabel 3900 6800 2    50   Input ~ 0
PA10
Text GLabel 3900 6900 2    50   Input ~ 0
PA11
Text GLabel 3900 7000 2    50   Input ~ 0
PA12
Text GLabel 2800 7300 0    50   Input ~ 0
PB7
Text GLabel 2800 7200 0    50   Input ~ 0
PB6
Text GLabel 2800 7100 0    50   Input ~ 0
PB5
Text GLabel 2800 7000 0    50   Input ~ 0
PB4
Wire Wire Line
	3400 2750 3700 2750
Wire Wire Line
	6600 3150 8350 3150
Wire Wire Line
	8350 3250 6600 3250
$Comp
L Device:C C5
U 1 1 61D6A23E
P 9150 2100
F 0 "C5" H 9265 2146 50  0000 L CNN
F 1 "0.1u" H 9265 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9188 1950 50  0001 C CNN
F 3 "~" H 9150 2100 50  0001 C CNN
	1    9150 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 61D6BB79
P 9150 2250
F 0 "#PWR01" H 9150 2000 50  0001 C CNN
F 1 "GND" H 9155 2077 50  0000 C CNN
F 2 "" H 9150 2250 50  0001 C CNN
F 3 "" H 9150 2250 50  0001 C CNN
	1    9150 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 1950 9350 1950
Wire Wire Line
	9350 1950 9350 2400
Connection ~ 9150 1950
Wire Wire Line
	10050 3100 10250 3100
Wire Wire Line
	10250 3100 10250 3250
Text GLabel 9350 3100 0    50   Input ~ 0
PWM
Text GLabel 2800 6900 0    50   Input ~ 0
PWM
$Comp
L Device:R R16
U 1 1 61D88885
P 10800 3250
F 0 "R16" V 10593 3250 50  0000 C CNN
F 1 "RLED" V 10684 3250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 10730 3250 50  0001 C CNN
F 3 "~" H 10800 3250 50  0001 C CNN
	1    10800 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	10350 3250 10250 3250
$Comp
L power:+5V #PWR02
U 1 1 61DBAAB3
P 10950 3250
F 0 "#PWR02" H 10950 3100 50  0001 C CNN
F 1 "+5V" V 10965 3378 50  0000 L CNN
F 2 "" H 10950 3250 50  0001 C CNN
F 3 "" H 10950 3250 50  0001 C CNN
	1    10950 3250
	0    1    1    0   
$EndComp
$Comp
L Device:LED D20
U 1 1 61DD6CA0
P 10500 3250
F 0 "D20" H 10493 2995 50  0000 C CNN
F 1 "LED" H 10493 3086 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 10500 3250 50  0001 C CNN
F 3 "~" H 10500 3250 50  0001 C CNN
	1    10500 3250
	1    0    0    -1  
$EndComp
$Comp
L original:Switch SW3
U 1 1 617FC7E6
P 2350 6350
F 0 "SW3" V 2304 6478 50  0000 L CNN
F 1 "Switch" V 2395 6478 50  0000 L CNN
F 2 "original:Switch" H 2350 6350 50  0001 C CNN
F 3 "" H 2350 6350 50  0001 C CNN
	1    2350 6350
	0    1    1    0   
$EndComp
$Comp
L original:Switch SW2
U 1 1 617FCB16
P 6350 4050
F 0 "SW2" H 6350 4315 50  0000 C CNN
F 1 "Switch" H 6350 4224 50  0000 C CNN
F 2 "original:Switch" H 6350 4050 50  0001 C CNN
F 3 "" H 6350 4050 50  0001 C CNN
	1    6350 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 3850 6550 4050
Connection ~ 6550 4050
Wire Wire Line
	6550 4050 6550 4250
$Comp
L original:Switch SW1
U 1 1 617FEC52
P 6350 3850
F 0 "SW1" H 6350 4115 50  0000 C CNN
F 1 "Switch" H 6350 4024 50  0000 C CNN
F 2 "original:Switch" H 6350 3850 50  0001 C CNN
F 3 "" H 6350 3850 50  0001 C CNN
	1    6350 3850
	1    0    0    -1  
$EndComp
$Comp
L original:Regulator U5
U 1 1 618342A2
P 6000 4850
F 0 "U5" H 6000 5215 50  0000 C CNN
F 1 "NJU7223DL1" H 6000 5124 50  0000 C CNN
F 2 "original:Regulator" H 6000 4850 50  0001 C CNN
F 3 "" H 6000 4850 50  0001 C CNN
	1    6000 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 6183505E
P 5500 5050
F 0 "C7" H 5615 5096 50  0000 L CNN
F 1 "0.1u" H 5615 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5538 4900 50  0001 C CNN
F 3 "~" H 5500 5050 50  0001 C CNN
	1    5500 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 6183518D
P 6500 5050
F 0 "C8" H 6615 5096 50  0000 L CNN
F 1 "0.1u" H 6615 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6538 4900 50  0001 C CNN
F 3 "~" H 6500 5050 50  0001 C CNN
	1    6500 5050
	1    0    0    -1  
$EndComp
Connection ~ 2350 950 
Wire Wire Line
	1050 950  1350 950 
Wire Wire Line
	1450 950  1450 1050
Connection ~ 1450 950 
Wire Wire Line
	1450 950  1650 950 
Wire Wire Line
	5650 4850 5500 4850
Wire Wire Line
	5500 4850 5500 4900
Wire Wire Line
	6350 4850 6500 4850
Wire Wire Line
	6500 4850 6500 4900
$Comp
L power:GND #PWR07
U 1 1 61895ECC
P 6500 5200
F 0 "#PWR07" H 6500 4950 50  0001 C CNN
F 1 "GND" H 6505 5027 50  0000 C CNN
F 2 "" H 6500 5200 50  0001 C CNN
F 3 "" H 6500 5200 50  0001 C CNN
	1    6500 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 6189605B
P 6000 5150
F 0 "#PWR05" H 6000 4900 50  0001 C CNN
F 1 "GND" H 6005 4977 50  0000 C CNN
F 2 "" H 6000 5150 50  0001 C CNN
F 3 "" H 6000 5150 50  0001 C CNN
	1    6000 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 61896188
P 5500 5200
F 0 "#PWR06" H 5500 4950 50  0001 C CNN
F 1 "GND" H 5505 5027 50  0000 C CNN
F 2 "" H 5500 5200 50  0001 C CNN
F 3 "" H 5500 5200 50  0001 C CNN
	1    5500 5200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 61896D01
P 5500 4850
F 0 "#PWR03" H 5500 4700 50  0001 C CNN
F 1 "+5V" H 5515 5023 50  0000 C CNN
F 2 "" H 5500 4850 50  0001 C CNN
F 3 "" H 5500 4850 50  0001 C CNN
	1    5500 4850
	1    0    0    -1  
$EndComp
Connection ~ 5500 4850
$Comp
L power:+3.3V #PWR04
U 1 1 61897750
P 6500 4850
F 0 "#PWR04" H 6500 4700 50  0001 C CNN
F 1 "+3.3V" H 6515 5023 50  0000 C CNN
F 2 "" H 6500 4850 50  0001 C CNN
F 3 "" H 6500 4850 50  0001 C CNN
	1    6500 4850
	1    0    0    -1  
$EndComp
Connection ~ 6500 4850
$Comp
L original:Conn_03x_05_Male J2
U 1 1 619A4C41
P 4800 1350
F 0 "J2" H 5229 1418 50  0000 L CNN
F 1 "ADC" H 5229 1327 50  0000 L CNN
F 2 "original:PinHeader_3x05_P2.54mm_Vertical" H 5100 1150 50  0001 C CNN
F 3 "" H 5100 1150 50  0001 C CNN
	1    4800 1350
	1    0    0    -1  
$EndComp
$Comp
L original:Conn_03x_05_Male J3
U 1 1 619A54E7
P 9150 1350
F 0 "J3" H 9578 1418 50  0000 L CNN
F 1 "GPIO" H 9578 1327 50  0000 L CNN
F 2 "original:PinHeader_3x05_P2.54mm_Vertical" H 9450 1150 50  0001 C CNN
F 3 "" H 9450 1150 50  0001 C CNN
	1    9150 1350
	1    0    0    -1  
$EndComp
$Comp
L original:Conn_03x04_Male U6
U 1 1 619AADC2
P 7050 1050
F 0 "U6" H 7478 868 50  0000 L CNN
F 1 "SERVO" H 7478 777 50  0000 L CNN
F 2 "original:PinHeader_3x04_P2.54mm_Vertical" H 7050 1050 50  0001 C CNN
F 3 "" H 7050 1050 50  0001 C CNN
	1    7050 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 1850 9450 1550
Connection ~ 9450 1250
Wire Wire Line
	9450 1250 9450 1150
Connection ~ 9450 1350
Wire Wire Line
	9450 1350 9450 1250
Connection ~ 9450 1450
Wire Wire Line
	9450 1450 9450 1350
Connection ~ 9450 1550
Wire Wire Line
	9450 1550 9450 1450
Wire Wire Line
	9150 1550 9150 1450
Connection ~ 9150 1150
Wire Wire Line
	9150 1150 9150 850 
Connection ~ 9150 1250
Wire Wire Line
	9150 1250 9150 1150
Connection ~ 9150 1350
Wire Wire Line
	9150 1350 9150 1250
Connection ~ 9150 1450
Wire Wire Line
	9150 1450 9150 1350
Wire Wire Line
	7050 850  7050 1150
Connection ~ 7050 1150
Wire Wire Line
	7050 1150 7050 1250
Connection ~ 7050 1250
Wire Wire Line
	7050 1250 7050 1350
Connection ~ 7050 1350
Wire Wire Line
	7050 1350 7050 1450
Wire Wire Line
	7350 1850 7350 1450
Connection ~ 7350 1250
Wire Wire Line
	7350 1250 7350 1150
Connection ~ 7350 1350
Wire Wire Line
	7350 1350 7350 1250
Connection ~ 7350 1450
Wire Wire Line
	7350 1450 7350 1350
Wire Wire Line
	5100 1150 5100 1250
Connection ~ 5100 1250
Wire Wire Line
	5100 1250 5100 1350
Connection ~ 5100 1350
Wire Wire Line
	5100 1350 5100 1450
Connection ~ 5100 1450
Wire Wire Line
	5100 1450 5100 1550
Connection ~ 5100 1550
Wire Wire Line
	5100 1550 5100 1850
Wire Wire Line
	4800 1150 4800 850 
Connection ~ 4800 1150
Wire Wire Line
	4800 1250 4800 1150
Connection ~ 4800 1250
Wire Wire Line
	4800 1350 4800 1250
Connection ~ 4800 1350
Wire Wire Line
	4800 1550 4800 1450
Wire Wire Line
	4800 1450 4800 1350
Connection ~ 4800 1450
Text Label 1800 4700 2    50   ~ 0
MOTOROUT2
$Comp
L power:+3V3 #PWR0105
U 1 1 61B1A289
P 5950 5650
F 0 "#PWR0105" H 5950 5500 50  0001 C CNN
F 1 "+3V3" H 5965 5823 50  0000 C CNN
F 2 "" H 5950 5650 50  0001 C CNN
F 3 "" H 5950 5650 50  0001 C CNN
	1    5950 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 61B1AC8F
P 5950 5800
F 0 "C11" H 6065 5846 50  0000 L CNN
F 1 "0.1u" H 6065 5755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5988 5650 50  0001 C CNN
F 3 "~" H 5950 5800 50  0001 C CNN
	1    5950 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 61B1B1F5
P 6300 5800
F 0 "C12" H 6415 5846 50  0000 L CNN
F 1 "0.1u" H 6415 5755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6338 5650 50  0001 C CNN
F 3 "~" H 6300 5800 50  0001 C CNN
	1    6300 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 61B1B659
P 6650 5800
F 0 "C13" H 6765 5846 50  0000 L CNN
F 1 "0.1u" H 6765 5755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6688 5650 50  0001 C CNN
F 3 "~" H 6650 5800 50  0001 C CNN
	1    6650 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C14
U 1 1 61B1B98C
P 7000 5800
F 0 "C14" H 7115 5846 50  0000 L CNN
F 1 "0.1u" H 7115 5755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7038 5650 50  0001 C CNN
F 3 "~" H 7000 5800 50  0001 C CNN
	1    7000 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 5650 6300 5650
Connection ~ 5950 5650
Connection ~ 6300 5650
Wire Wire Line
	6300 5650 6650 5650
Connection ~ 6650 5650
Wire Wire Line
	6650 5650 7000 5650
$Comp
L Device:C C15
U 1 1 61B2A301
P 7350 5800
F 0 "C15" H 7465 5846 50  0000 L CNN
F 1 "4.7u" H 7465 5755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7388 5650 50  0001 C CNN
F 3 "~" H 7350 5800 50  0001 C CNN
	1    7350 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 5650 7350 5650
Connection ~ 7000 5650
Wire Wire Line
	7350 5950 7000 5950
Connection ~ 6300 5950
Wire Wire Line
	6300 5950 5950 5950
Connection ~ 6650 5950
Wire Wire Line
	6650 5950 6300 5950
Connection ~ 7000 5950
Wire Wire Line
	7000 5950 6650 5950
$Comp
L power:GND #PWR0112
U 1 1 61B1AC51
P 5950 5950
F 0 "#PWR0112" H 5950 5700 50  0001 C CNN
F 1 "GND" H 5955 5777 50  0000 C CNN
F 2 "" H 5950 5950 50  0001 C CNN
F 3 "" H 5950 5950 50  0001 C CNN
	1    5950 5950
	1    0    0    -1  
$EndComp
Connection ~ 5950 5950
$Comp
L power:+9V #PWR0113
U 1 1 61B9AE72
P 1350 950
F 0 "#PWR0113" H 1350 800 50  0001 C CNN
F 1 "+9V" H 1365 1123 50  0000 C CNN
F 2 "" H 1350 950 50  0001 C CNN
F 3 "" H 1350 950 50  0001 C CNN
	1    1350 950 
	1    0    0    -1  
$EndComp
Connection ~ 1350 950 
Wire Wire Line
	1350 950  1450 950 
$Comp
L power:+9V #PWR0114
U 1 1 61B9B566
P 800 2150
F 0 "#PWR0114" H 800 2000 50  0001 C CNN
F 1 "+9V" H 815 2323 50  0000 C CNN
F 2 "" H 800 2150 50  0001 C CNN
F 3 "" H 800 2150 50  0001 C CNN
	1    800  2150
	1    0    0    -1  
$EndComp
Connection ~ 800  2150
Wire Wire Line
	800  2150 950  2150
$Comp
L power:+9V #PWR0127
U 1 1 61B9CE80
P 3150 3650
F 0 "#PWR0127" H 3150 3500 50  0001 C CNN
F 1 "+9V" H 3165 3823 50  0000 C CNN
F 2 "" H 3150 3650 50  0001 C CNN
F 3 "" H 3150 3650 50  0001 C CNN
	1    3150 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 4300 1450 4300
$Comp
L power:+9V #PWR0141
U 1 1 61B9D6EC
P 1450 4300
F 0 "#PWR0141" H 1450 4150 50  0001 C CNN
F 1 "+9V" H 1465 4473 50  0000 C CNN
F 2 "" H 1450 4300 50  0001 C CNN
F 3 "" H 1450 4300 50  0001 C CNN
	1    1450 4300
	1    0    0    -1  
$EndComp
Connection ~ 1450 4300
Wire Wire Line
	1450 4300 1600 4300
Wire Wire Line
	1300 5600 1450 5600
$Comp
L power:+9V #PWR0142
U 1 1 61B9DC09
P 1450 5600
F 0 "#PWR0142" H 1450 5450 50  0001 C CNN
F 1 "+9V" H 1465 5773 50  0000 C CNN
F 2 "" H 1450 5600 50  0001 C CNN
F 3 "" H 1450 5600 50  0001 C CNN
	1    1450 5600
	1    0    0    -1  
$EndComp
Connection ~ 1450 5600
Wire Wire Line
	1450 5600 1600 5600
Wire Wire Line
	3500 5450 3500 5600
Text GLabel 4950 2950 0    50   Input ~ 0
PB6
Text GLabel 4950 3050 0    50   Input ~ 0
PB1
Text GLabel 4950 2650 0    50   Input ~ 0
PA12
Text GLabel 6600 3150 0    50   Input ~ 0
PF0
Text GLabel 6600 3250 0    50   Input ~ 0
PF1
Text GLabel 3700 2550 2    50   Input ~ 0
PA0
Text GLabel 3700 2450 2    50   Input ~ 0
PA4
Text GLabel 3700 2350 2    50   Input ~ 0
PA5
Text GLabel 3700 2250 2    50   Input ~ 0
PA6
Text GLabel 3700 2150 2    50   Input ~ 0
PA7
Wire Bus Line
	2800 4550 5350 4550
Wire Bus Line
	3300 2750 3300 4450
Wire Bus Line
	5350 3650 5350 4550
Wire Wire Line
	3350 1650 3750 1650
Wire Wire Line
	3100 1500 4000 1500
Wire Wire Line
	3350 1350 3750 1350
Wire Wire Line
	3100 1200 4000 1200
Wire Wire Line
	3350 1050 3750 1050
Wire Bus Line
	9000 2450 9000 2900
Wire Bus Line
	2900 2750 2900 4100
Wire Bus Line
	2800 3250 2800 4550
Wire Bus Line
	1900 4100 1900 6000
Wire Bus Line
	3450 1150 3450 2450
Wire Bus Line
	6350 1250 6350 3350
Wire Bus Line
	10400 2700 10400 4450
Wire Bus Line
	8450 1250 8450 3150
$Comp
L power:+9V #PWR?
U 1 1 620CE12A
P 950 3850
F 0 "#PWR?" H 950 3700 50  0001 C CNN
F 1 "+9V" V 965 3978 50  0000 L CNN
F 2 "" H 950 3850 50  0001 C CNN
F 3 "" H 950 3850 50  0001 C CNN
	1    950  3850
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
