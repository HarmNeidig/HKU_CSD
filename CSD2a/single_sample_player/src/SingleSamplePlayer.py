# note durations: 0.25 = a 16th, 0.50 = a 8th and 1 is a 4th
noteDurations = [1, 1, 1, 1]
# [0,4,8,12]
timeStamps16th = []
# noteDurationsLen = (len(noteDurations))
# print(noteDurationsLen)
# default bpm, prints starting bpm
bpm = 120
print(bpm)
duration4th = 60/bpm
duration16th = duration4th/4

def durationToTimestamps16th(lst):
    for i in lst:
        x = i*4
        if lst.index(i) == 0:
            timeStamps16th.append(0)
            timeStamps16th.append(int(x))
            xprev = x
        if lst.index(i) <= 1:
            x = x + xprev
            timeStamps16th.append(int(x))
            xprev = x

durationToTimestamps16th(noteDurations)
print(timeStamps16th)

#print(duration4th)
#print(duration16th)
