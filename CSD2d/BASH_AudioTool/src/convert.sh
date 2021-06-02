#!/bin/bash
input_dir=~/desktop/HKU_CSD/CSD2d/BASH_AudioTool/audio_resources/raw_input/
output_dir=~/desktop/HKU_CSD/CSD2d/BASH_AudioTool/audio_resources/converted_input/
extention='_converted.wav'
sample_freq=24000
count=0

# looks in input dir and convert all from MP3 to WAV using ffmpeg
for f in ${input_dir}*.mp3;
do
  count=$(($count+1))
  filename= basename ${f%%.*}
  target_file=${output_dir}${count}${extention}
  ffmpeg -i ${f} ${target_file}
done;

echo "Files in the Directory: $count"
exit 0
