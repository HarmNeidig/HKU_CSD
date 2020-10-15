# []
import simpleaudio as sa
import time as t
import random as r
# grapics reference: https://www.pas.rochester.edu/~rsarkis/csc161/python/graphics.html
from graphics import *
# import numpy

Amount16th = 16
repeats = 2

bpm = 120
Sin4th = 60.0 / bpm
Sin8th = float(Sin4th / 2)
Sin16th = float(Sin8th / 2)





print("16th length in secs = ", Sin16th)

hatTimeStamps = [1,0.5,1,0.5,1,0.5,1,0.5,1,0.5,1,0.5,1,0.5,1,0.5]
snareTimeStamps = [1,0,0.5,0,0,0,1,0,1,0,0.5,0,1,0,0.2,0.2]
kickTimeStamps = [1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0]
masArray = []

kick = sa.WaveObject.from_wave_file("kick.wav")
snare = sa.WaveObject.from_wave_file("snare.wav")
hat = sa.WaveObject.from_wave_file("hihat.wav")

# make a master array [[h,s,k][][][]] index = timestamp
def makeMasArray(lstHat, lstSnare, lstKick):
    for i in range(0,Amount16th):
        Ts_Array = []
        # makes arrays of three
        Ts_Array.append(lstHat[i])
        Ts_Array.append(lstSnare[i])
        Ts_Array.append(lstKick[i])
        masArray.append(Ts_Array)
#        print(Ts_Array)
    return


makeMasArray(hatTimeStamps,snareTimeStamps,kickTimeStamps)
print(masArray)

#handles individual events
def eventHandler(lst):
    for array in lst:
        hatSeed = r.random()
        print(hatSeed)
        if array[0] >= hatSeed:
            hat.play()
        if array[1] >= hatSeed:
            print("snare trigger bc ",array[1]," >= ", hatSeed)
            snare.play()
        if array[2] == 1:
            kick.play()
        t.sleep(Sin16th)
    quit()


def main():
    Xwidth = 500
    Yheight = 500
    win = GraphWin("window", Xwidth, Yheight)
    win.setBackground(color_rgb(0,0,0))
    Xmiddle = Xwidth/2
    Ymiddle = Yheight/2
    mainCircle = Circle(Point(Xmiddle,Ymiddle),250)
    mainCircle.setFill(color_rgb(125,125,125))
    XminPT = Point(Xwidth/2,0)
    YminPT = Point(0,Yheight/2)
    XplusPT = Point(Xwidth, Yheight/2)
    YplusPT = Point(Xwidth/2,Yheight)
    Xline = Line(XminPT,XplusPT)
    Xline.setWidth(6)
    Xline.setWidth(6)

    Xline.draw(win)
    mainCircle.draw(win)

main()
eventHandler(masArray)

#loop over Amount16th and if 0 == 1 than play hihat if 1 == 1 play snare if 2 == 1 play kickTimeStamps
