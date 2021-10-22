#!/bin/bash

rm -rf kawabata.out
gcc kawabata.c -o kawabata.out -lm
./kawabata.out
