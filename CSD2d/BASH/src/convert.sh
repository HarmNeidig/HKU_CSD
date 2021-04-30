#!/bin/bash
input_dir=~/desktop/HKU_CSD/CSD2d/BASH/audio_resources/input/
output_dir=~/desktop/HKU_CSD/CSD2d/BASH/audio_resources/output/
file_extention=_converted.wav
sample_freq=24000
count=0

for f in ${input_dir}*.mp3;
do
  count=$(($count+1))
  filename= basename ${f%%.*}
  target_file=${output_dir}${filename}${extention}
  ffmpeg -i ${f} ${target_file}
done;

echo "Files in the Directory: $count"
exit 0
