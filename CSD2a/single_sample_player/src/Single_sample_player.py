import time as t
import simpleaudio as sa

kick = sa.WaveObject.from_wave_file("kick.wav")

# define notes with expected output

# noteDurations = [1, 1, 1, 1]
# [0,4,8,12]
noteDurations = [0.5, 0.25, 1, 1]
# [0,2,3,7,11]

# define bpm
bpm = 120
print(bpm)

# define lists
timeStamps16th = []
timeStampsMS = []
intervalsMS = []

# define note note durations
noteDurations4th = 60000 / bpm
noteDurations8th = noteDurations4th / 2
noteDurations16th = noteDurations8th / 2


def durationToTimestamps16th(lst):
    xprev=0
    timeStamps16th.append(xprev)
    for n in lst:
        x = n * 4 + xprev
        timeStamps16th.append(int(x))
        xprev=x
    timeStamps16th.pop(-1)

def timeStamps16thToMS(lst):
    for n in lst:
        x = n * noteDurations16th
        timeStampsMS.append(x)

def intervalInMS(lst):
    for n in lst:
        x = n * noteDurations4th
        intervalsMS.append(x)

def loopplay(lst):
    for n in lst:
        print("kick")
        kick.play()
        t.sleep(n/1000)

intervalInMS(noteDurations)
print("intervalMS list:", intervalsMS)

durationToTimestamps16th(noteDurations)
print("Timestamps in 16ths:", timeStamps16th)

timeStamps16thToMS(timeStamps16th)
print("Timestamps in MS:", timeStampsMS)

Repeat = 4
loopplay(intervalsMS*Repeat)
