#!/bin/bash
input_dir=~/desktop/HKU_CSD/CSD2d/BASH/audio_resources/input/

count=0

for f in ${input_dir}*.mp3;
do
  count=$(($count+1))
  file $f ;
done;

echo "Files in the Directory: $count"
exit 0
