# []
import simpleaudio as sa
import time as t
import random as r

Amount16th = 16
repeats = 6

# define bpm and calculate to time
bpm = 350
Sin4th = 60.0 / bpm
Sin8th = float(Sin4th / 2)
Sin16th = float(Sin8th / 2)


print("16th length in secs = ", Sin16th)

#define propabilities
hatTimeStamps = [1,0.5,1,0.5,1,0.5,1,0.5,1,0.5,1,0.5,1,0.5,1,0.5]
snareTimeStamps = [1,0.6,0.5,0.1,0,0,1,0,1,0.7,0.5,0,1,0,0.2,0.2]
kickTimeStamps = [1,0,0,0,1,0,0.5,0,1,0,0.3,0,1,0,0.8,0.4]

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

#handles events
def eventHandler(lst):
    for array in lst:
        hatSeed = r.random()
        snareSeed = r.random()
        kickSeed = r.random()
        if array[0] > hatSeed:
            print("hat trigger because ",array[0]," > ", hatSeed)
            hat.play()
        if array[1] > snareSeed:
            print("snare trigger because ",array[1]," > ", snareSeed)
            snare.play()
        if array[2] > kickSeed:
            print("kick trigger because ",array[2]," > ", kickSeed)
            kick.play()
        t.sleep(Sin16th)
    quit()

eventHandler(masArray*repeats)
