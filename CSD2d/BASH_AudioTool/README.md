Unix Sounddesign Tool

Hello! This is a unix Sounddesign tool i wrote for a school assignment.
It consists of two seprate applications.

Single File Program

This program is for single files. It allows you to continously work on
the file through the 'output list to input list' button.

Multi File Program

This program is for multiple files. It is very similar to the single file program,
exept for the 'select all', which allows you to process multiple files.

Effect processors

I've made some bash scripts with sox audio effect processing.
Here are the ones I've implemented:

Trim

Trim allows you to fade and trim a sample. The first parameter is the fade time, which cant exceed the length of the total sample, which is the second parameter.

Delay

Delay adds the same sound but delayed. The first parameter is the initial delay time, the second is the long delay time.

Reverb

Reverb adds a reverb, the first parameter controls the damping and the second parameter controls the room size.

Distortion

Distorion uses the overdrive processor from sox. The first parameter is the gain and the second parameter is the color.

Tremolo

The tremolo adds a amplitude modulation effect. The first parameter controls the speed and the second controls the depth.
