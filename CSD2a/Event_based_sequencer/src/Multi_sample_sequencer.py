import time as t
import simpleaudio as sa
import keyboard
import random
from graphics import *
# []

k = sa.WaveObject.from_wave_file("kick.wav")
s = sa.WaveObject.from_wave_file("snare.wav")
h = sa.WaveObject.from_wave_file("hihat.wav")

Repeat = 10
bpm = 120
bpmMS = 60000/bpm
bpmMS16th = bpmMS/4
Amount16th = 16
Range16ths = [*range(0,Amount16th)]

print("bpm 16TH in MS: ", bpmMS16th)

noteDurations_k = [1,1,1,1]
# 0,3,7,13
noteDurations_s = [1,1,1,1]
# 0,3,5,
TS_s = []
TS_k = []
Xwidth = 1000
stepX = Xwidth / Amount16th
Yheight = 750
#PrevY_hat = Yheight / 2

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
    win = GraphWin("My Circle", Xwidth, Yheight)
    win.setBackground(color_rgb(0,0,0))
    stepX = Xwidth / Amount16th
    Current_TS = 0
    PrevY_hat = Yheight / 2
    hatPole = 1
    for i in lst:
        r = random.randrange(50,255)
        g = random.randrange(50,255)
        b = random.randrange(50,255)
        print(Current_TS)
        Current_TS = Current_TS + 1
        rhythmXaxis = stepX * Current_TS / Repeat
        Y_Dev = random.randrange(0,10)
        SleepMS = (float(bpmMS16th/1000))
        t.sleep(SleepMS)
        if i in TS_s:
            Y_snare = Yheight / 3 + Y_Dev
            sizeSnare = random.randrange(1,9)
            circleSnare = Circle(Point(rhythmXaxis,Y_snare), sizeSnare)
            circleSnare.setFill(color_rgb(r,0,0))
            circleSnare.draw(win)
            s.play()
            print("Snare op:", Current_TS)
        if i in TS_k:
            Y_kick = ((Yheight / 3) * 2) - Y_Dev
            sizeKick = random.randrange(10,13)
            circleKick = Circle(Point(rhythmXaxis,Y_kick), sizeKick)
            circleKick.setFill(color_rgb(0,0,g))
            circleKick.draw(win)
            k.play()
            print("Kick op:", Current_TS)
        if i in range(0,Amount16th):
            Y_hat = (PrevY_hat +- ((random.randrange(15)) * hatPole)
            #if (Y_snare >= Y_hat <= Y_kick):
            #    print("switch")
#                hatPole = hatPole * -1
#            sizeHihat = random.randrange(2,4)
            circleHat = Circle(Point(rhythmXaxis,Y_hat), 5)
            circleHat.setFill(color_rgb(b,b,b))
            circleHat.draw(win)
            h.play()
            PrevY_hat = Y_hat
            print("Hihat op:", Current_TS)
        if i == (Amount16th):
            print(Current_TS)
            quit()

EventHandler(Range16ths*Repeat)
