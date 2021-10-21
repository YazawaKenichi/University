#!/bin/bash

rm -rf *.out

gcc main.c calclator.c calclator.h -o calclator.out -lm

./calclator.out
