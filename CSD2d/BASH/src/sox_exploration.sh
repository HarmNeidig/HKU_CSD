#!/bin/sh

# /Users/harm/Desktop/HKU_CSD/CSD2d/bash/audio_resources/converted_input/10_converted.wav
# /Users/harm/Desktop/HKU_CSD/CSD2d/bash/audio_resources/sox_output/10_converted.wav

echo "File Name: $0"
echo "First Parameter (input file) : $1"
echo "Second Parameter (output file): $2"
echo "Third Parameter : $3"

sox --norm=-3 $1 $2 fade $3 -$3
