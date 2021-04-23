import os
import tkinter

## HARDCODED INPUT
input = 'audioresources/input/115505_853818-lq.mp3'
outputname = 'audioresources/output/biatch.mp3'

## MAKE SEPARATE SOUNDS

## CONCAT SOUNDS UNTILL 5 SEC

os.system('sox ' + input + outputname + ' trim 0.1 0.1')

## CONVERT MP3 TO WAV
os.system('ffmpeg -i input.mp3 output.wav')
