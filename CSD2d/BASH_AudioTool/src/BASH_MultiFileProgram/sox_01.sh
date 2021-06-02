#!/bin/sh

# Trim + fade

echo "Script Name : $0"
echo "Input file : $1"
echo "Output file : $2"
echo "Fadetime : $3"
echo "Length : $4"

begin=0

sox --norm=-18 $1 $2 trim ${begin} $4 fade $3 $4 $3
