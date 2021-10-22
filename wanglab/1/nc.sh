#!/bin/bash

rm -rf *.out
gcc newcalclator.c -o nc.out -lm
./nc.out
