#!/bin/sh

# Distortion

echo "Script Name : $0"
echo "Input file : $1"
echo "Output file : $2"
echo "Gain : $3"
echo "Color : $4"

sox --norm=-6 $1 $2 overdrive $3 $4
