#!/bin/bash
x = $(stat -c "%X" bomb.txt)
y = 1
time=&(echo $((x - y)))
echo "$time"


