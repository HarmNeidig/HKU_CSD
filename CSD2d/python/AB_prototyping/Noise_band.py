import librosa as lr
import numpy as np
import pandas as pd
import os
from glob import glob
import simpleaudio as sa

## set path to audio files
input_dir = '/Users/harm/Desktop/audio'
output_dir = '/Users/harm/Desktop/audio'
num_file = 1

kick = sa.WaveObject.from_wave_file("audio/kick.wav")
kick.play()

## read audio files
for i in os.listdir(input_dir):
    # List files with 1.wav
    if i.endswith(str(num_file)+".wav"):
        print("Files with extension 1.wav are:",i)
        audio_file = input_dir + '/' + i

stream = librosa.stream(audio_file,
                      block_length=256,
                      frame_length=4096,
                      hop_length=1024)


audio, sfreq = lr.load(audio_file, sr=sfreq)
time = np.arange(0,len(audio))
