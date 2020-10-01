# []
import simpleaudio as sa
# import numpy

Amount16th = 16
hatTimeStamps = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
snareTimeStamps = [1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0]
kickTimeStamps = [1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0]
masArray = []
Ts_Array = []

kick = sa.WaveObject.from_wave_file("kick.wav")
snare = sa.WaveObject.from_wave_file("snare.wav")
hat = sa.WaveObject.from_wave_file("hihat.wav")

# make a master array [timestamp[h,s,k][][][]]

matrix = []

def makeMatrix():
    for i in range(len(Amount16th)):
        matrix.append([hatTimeStamps[i], snareTimeStamps[i], kickTimeStamps[i]])

print(matrix)

'''
def makeMasArray(lstHat, lstSnare, lstKick):
    for i in range(0,Amount16th):
        Ts_filled = False
        # makes arrays of three
        while Ts_filled == False:
            Ts_Array.append(lstHat[i])
            Ts_Array.append(lstSnare[i])
            Ts_Array.append(lstKick[i])
            Ts_filled = True
        masArray.append(Ts_Array)
        return
        Ts_Array.clear()

makeMasArray(hatTimeStamps,snareTimeStamps,kickTimeStamps)

#handles individual events
def eventHandler(lst):
    for array in lst:
        if array[0] == 1:
            hat.play()
        if array[1] == 1:
            snare.play()
        if array[2] == 1:
            kick.play()

eventHandler(masArray)
'''
#loop over Amount16th and if 0 == 1 than play hihat if 1 == 1 play snare if 2 == 1 play kickTimeStamps

print(masArray)
