#!/bin/bash

rm -rf submission.out
mv 提出.c submission.c
gcc submission.c -o submission.out -lm
./submission.out
