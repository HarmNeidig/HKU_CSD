# []
import simpleaudio as sa
import time as t
import random as r
from graphics import *
# import numpy

Amount16th = 16
repeats = 20

bpm = 120
Sin4th = 60.0 / bpm
Sin8th = float(Sin4th / 2)
Sin16th = float(Sin8th / 2)


print("16th length in secs = ", Sin16th)

hatTimeStamps = [0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5]
snareTimeStamps = [0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5]
kickTimeStamps = [0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5]
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
        i = lst.index(array)
        hatSeed = r.random()
        if array[0] >= hatSeed:
            print("hat trigger bc ",array[1]," >= ", hatSeed, "on ts ", i)
            hat.play()
        snareSeed = r.random()
        if array[1] >= snareSeed:
            print("snare trigger bc ",array[1]," >= ", snareSeed, "on ts ", i)
            snare.play()
        kickSeed = r.random()
        if array[2] <= kickSeed:
            print("kick trigger bc ",array[1]," >= ", snareSeed,"on ts ", i)
            kick.play()
        t.sleep(Sin16th)
    quit()




eventHandler(masArray*repeats)

#loop over Amount16th and if 0 == 1 than play hihat if 1 == 1 play snare if 2 == 1 play kickTimeStamps
