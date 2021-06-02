#!/bin/sh

# Delay

echo "Script Name : $0"
echo "Input file : $1"
echo "Output file : $2"


delayShort=$3
delayLong=$((${delayShort}*($4)))
echo "Delay : $delayShort"
echo "Length : $delayLong"
sox -M $1 $1 $1 $1 $2 delay ${delayShort} ${delayShort} ${delayLong} ${delayLong} remix 1,3,5 2,4,6
