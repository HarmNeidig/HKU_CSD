#!/bin/sh

# /Users/harm/Desktop/HKU_CSD/CSD2d/bash/audio_resources/converted_input/10_converted.wav
# /Users/harm/Desktop/HKU_CSD/CSD2d/bash/audio_resources/sox_output/10_converted.wav

echo "Script Name : $0"
echo "Input file : $1"
echo "Output file : $2"
echo "Begin : $3"
echo "Length : $4"

fadeTime=1

# trim (start, length)

sox --norm=-3 $1 $2 trim $3 $4 fade ${fadeTime} $4 ${fadeTime}
