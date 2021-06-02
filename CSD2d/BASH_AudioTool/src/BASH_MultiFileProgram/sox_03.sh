#!/bin/sh

# Reverb

echo "Script Name : $0"
echo "Input file : $1"
echo "Output file : $2"
echo "damping % : $3"
echo "Length : $4"

damping=$((${3}*10))
roomSize=$((${4}*10))

sox --norm=-3 $1 $2 reverb 1.0 ${damping} ${roomSize}
