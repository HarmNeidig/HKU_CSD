import time as t
import simpleaudio as sa
import keyboard
# []

k = sa.WaveObject.from_wave_file("kick.wav")
s = sa.WaveObject.from_wave_file("snare.wav")
h = sa.WaveObject.from_wave_file("hihat.wav")

Repeat = 4
bpm = 120
bpmMS = 60000/bpm
bpmMS16th = bpmMS/4

Amount16th = 32
Range16ths = [*range(0,Amount16th)]

print("bpm 16TH in MS: ", bpmMS16th)

noteDurations_k = [1.5, 0.5, 2]
noteDurations_s = [0.5, 0.5, 1.5, 0.5]
TS_s = []
TS_k = []

def durationToTimestamps16th(lst, namearray):
    xprev=0
    namearray.append(xprev)
    for n in lst:
        x = n * 4 + xprev
        namearray.append(int(x))
        xprev=x
    namearray.pop(-1)

durationToTimestamps16th(noteDurations_s, TS_s)
durationToTimestamps16th(noteDurations_k, TS_k)

print("TS_s", TS_s)

def EventHandler(lst):
    x = 0
    Current_TS = 0
    for i in lst:
        print(Current_TS)
        Current_TS = Current_TS + 1
        SleepMS = (float(bpmMS16th/1000))
        t.sleep(SleepMS)
        if i in TS_s:
            s.play()
            print("snaaar")
        if i in TS_k:
            k.play()
            print("boom")
        if i in range(0,Amount16th):
            h.play()
            print("HAT")
        if i == (Amount16th):
            print(Current_TS)
            quit()

EventHandler(Range16ths*Repeat)
