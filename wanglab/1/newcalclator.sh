#!/bin/bash

code newcalclator.c newcalclator.sh
gcc newcalclator.c -o calclator.out
rm -rf calclator.out
gcc newcalclator.c -o calclator.out
./calclator.out
