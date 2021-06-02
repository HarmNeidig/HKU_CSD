#!/bin/sh

# Tremolo

echo "Script Name : $0"
echo "Input file : $1"
echo "Output file : $2"
echo "Speed : $3"
echo "Depth : $4"

sox $1 $2 tremolo $3 $4
