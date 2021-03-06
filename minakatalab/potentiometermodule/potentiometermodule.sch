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
L Device:R_POT RV1
U 1 1 625FA18F
P 1500 1500
F 0 "RV1" H 1431 1546 50  0000 R CNN
F 1 "R_POT" H 1431 1455 50  0000 R CNN
F 2 "Variable_Resistor:SV01A103AEA01R00" H 1500 1500 50  0001 C CNN
F 3 "~" H 1500 1500 50  0001 C CNN
	1    1500 1500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 625FAC4D
P 2150 1500
F 0 "J1" H 2230 1542 50  0000 L CNN
F 1 "Conn_01x03" H 2230 1451 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2150 1500 50  0001 C CNN
F 3 "~" H 2150 1500 50  0001 C CNN
	1    2150 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 1500 1650 1500
Wire Wire Line
	1500 1350 1500 1250
Wire Wire Line
	1500 1250 1650 1250
Wire Wire Line
	1850 1250 1850 1400
Wire Wire Line
	1850 1400 1950 1400
Wire Wire Line
	1950 1600 1850 1600
Wire Wire Line
	1850 1600 1850 1750
Wire Wire Line
	1850 1750 1650 1750
Wire Wire Line
	1500 1750 1500 1650
$Comp
L power:+5V #PWR01
U 1 1 625FAFD6
P 1650 1150
F 0 "#PWR01" H 1650 1000 50  0001 C CNN
F 1 "+5V" H 1665 1323 50  0000 C CNN
F 2 "" H 1650 1150 50  0001 C CNN
F 3 "" H 1650 1150 50  0001 C CNN
	1    1650 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 1150 1650 1250
Connection ~ 1650 1250
Wire Wire Line
	1650 1250 1850 1250
$Comp
L power:GND #PWR02
U 1 1 625FB202
P 1650 1850
F 0 "#PWR02" H 1650 1600 50  0001 C CNN
F 1 "GND" H 1655 1677 50  0000 C CNN
F 2 "" H 1650 1850 50  0001 C CNN
F 3 "" H 1650 1850 50  0001 C CNN
	1    1650 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 1850 1650 1750
Connection ~ 1650 1750
Wire Wire Line
	1650 1750 1500 1750
$Comp
L power:PWR_FLAG #FLG02
U 1 1 625FB43A
P 1500 1850
F 0 "#FLG02" H 1500 1925 50  0001 C CNN
F 1 "PWR_FLAG" H 1500 2023 50  0000 C CNN
F 2 "" H 1500 1850 50  0001 C CNN
F 3 "~" H 1500 1850 50  0001 C CNN
	1    1500 1850
	-1   0    0    1   
$EndComp
Wire Wire Line
	1500 1850 1500 1750
Connection ~ 1500 1750
$Comp
L power:PWR_FLAG #FLG01
U 1 1 625FB5BB
P 1500 1150
F 0 "#FLG01" H 1500 1225 50  0001 C CNN
F 1 "PWR_FLAG" H 1500 1323 50  0000 C CNN
F 2 "" H 1500 1150 50  0001 C CNN
F 3 "~" H 1500 1150 50  0001 C CNN
	1    1500 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1250 1500 1150
Connection ~ 1500 1250
$Comp
L Mechanical:MountingHole H1
U 1 1 625FF216
P 2200 2000
F 0 "H1" H 2300 2046 50  0000 L CNN
F 1 "MountingHole" H 2300 1955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 2200 2000 50  0001 C CNN
F 3 "~" H 2200 2000 50  0001 C CNN
	1    2200 2000
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 625FF279
P 2200 2200
F 0 "H2" H 2300 2246 50  0000 L CNN
F 1 "MountingHole" H 2300 2155 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 2200 2200 50  0001 C CNN
F 3 "~" H 2200 2200 50  0001 C CNN
	1    2200 2200
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 625FF516
P 2200 2400
F 0 "H3" H 2300 2446 50  0000 L CNN
F 1 "MountingHole" H 2300 2355 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 2200 2400 50  0001 C CNN
F 3 "~" H 2200 2400 50  0001 C CNN
	1    2200 2400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 625FF7E5
P 2200 2600
F 0 "H4" H 2300 2646 50  0000 L CNN
F 1 "MountingHole" H 2300 2555 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 2200 2600 50  0001 C CNN
F 3 "~" H 2200 2600 50  0001 C CNN
	1    2200 2600
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H5
U 1 1 62601DE7
P 2200 2800
F 0 "H5" H 2300 2846 50  0000 L CNN
F 1 "MountingHole" H 2300 2755 50  0000 L CNN
F 2 "MountingHole:MountingHole_4mm" H 2200 2800 50  0001 C CNN
F 3 "~" H 2200 2800 50  0001 C CNN
	1    2200 2800
	1    0    0    -1  
$EndComp
$EndSCHEMATC
