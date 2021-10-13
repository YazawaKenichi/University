#!/bin/bash

gcc arithmetic.c -o arithmetic.out
gcc functional.c -o functional.out -lm
gcc calclator.c -o calclator.out -lm

./calclator.out
