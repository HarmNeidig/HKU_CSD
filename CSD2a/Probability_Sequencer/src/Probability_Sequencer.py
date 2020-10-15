# []
import simpleaudio as sa
import time as t
import random as r
import math
from midiutil import MIDIFile

hatTimeStamps = []
snareTimeStamps = []
kickTimeStamps = []
masArray = []
midiMasArray = []
blockArray = []
mf = MIDIFile(1)

kick = sa.WaveObject.from_wave_file("kick.wav")
snare = sa.WaveObject.from_wave_file("snare.wav")
hat = sa.WaveObject.from_wave_file("hihat.wav")

def hatTiming(hatTimingInput):
    if hatTimingInput == 8:
        x = float(Amount8th)
        print("Aantal 8sten nodig = ",x)
        # if even
        if (Amount16th%2) == 0:
            for i in range(0,int(Amount8th)):
                hatTimeStamps.append(1)
                hatTimeStamps.append(0)
        # if odd
        else:
            while x >= 1.0:
                hatTimeStamps.append(1)
                hatTimeStamps.append(0)
                x -= 1.0
            while x == 0.5:
                hatTimeStamps.append(1)
                x -= 0.5
            if x == 0.0:
                return
                print(hatTimeStamps)
    if hatTimingInput == 16:
        for i in range(0,Amount16th):
            hatTimeStamps.append(1)

def snareTiming(snareAmountInput,Amount16th,TS_beginRotate):
    snareCycle = int(Amount16th / snareAmountInput)
    print("snareCycle = ",snareCycle)
    for i in range(0,snareAmountInput):
        snareTimeStamps.append(snareProbablityInput)
        for i in range(snareCycle-1):
            snareTimeStamps.append(0)
    print(len(snareTimeStamps))
    if len(snareTimeStamps) != Amount16th:
        missingSnares = Amount16th - len(snareTimeStamps)
        print("missingSnares = ", missingSnares)
        for i in range(missingSnares):
            snareTimeStamps.insert((r.randint(0,len(snareTimeStamps))), 0)


def kickTiming(kickAmountInput,Amount16th):
    kickCycle = int(Amount16th / kickAmountInput)
    print("kickCycle = ",kickCycle)
    for i in range(0,kickAmountInput):
        kickTimeStamps.append(kickProbablityInput)
        for i in range(kickCycle-1):
            kickTimeStamps.append(0)
    print(len(kickTimeStamps))
    if len(kickTimeStamps) != Amount16th:
        missingKicks = Amount16th - len(kickTimeStamps)
        print("missingKicks = ", missingKicks)
        for i in range(missingKicks):
            kickTimeStamps.insert((r.randint(0,len(kickTimeStamps))), 0)

def makeMasArray(lstHat, lstSnare, lstKick):
    for i in range(0,Amount16th):
        Ts_Array = []
        # makes arrays of three
        Ts_Array.append(lstHat[i])
        Ts_Array.append(lstSnare[i])
        Ts_Array.append(lstKick[i])
        masArray.append(Ts_Array)
    return

def eventHandler(lst):
    for array in lst:
        blockArray.clear()
        snareSeed = r.random()
        kickSeed = r.random()
        if array[0] == 1:
            print("hat trigger because ",array[0]," > 0.5")
            hat.play()
            blockArray.append(1)
        else:
            blockArray.append(0)
        if array[1] > snareSeed:
            print("snare trigger because ",array[1]," > ", snareSeed)
            snare.play()
            blockArray.append(1)
        else:
            blockArray.append(0)
        if array[2] > kickSeed:
            print("kick trigger because ",array[2]," > ", kickSeed)
            kick.play()
            blockArray.append(1)
        else:
            blockArray.append(0)
        midiMasArray.append(blockArray)
        t.sleep(Sin16th)
#    quit()

kickMidiNote = 24
snareMidiNote = 26
hatMidiNote = 30

# Format:
# mf.addNote(track, channel, pitch, time, duration, velocity)

def eventHandlerMidi(lst):
    time = 0
    track = 0
    mf.addTempo(track, time, bpm)
    for array in lst:
        time+=1
        if array[0] == 1:
            mf.addNote(0, 0, hatMidiNote, time, 0.25, 127)
        if array[1] == 1:
            mf.addNote(0, 0, snareMidiNote, time, 0.25, 127)
        if array[2] == 1:
            mf.addNote(0, 0, kickMidiNote, time, 0.25, 127)
    with open("symphony.midi",'wb') as outf:
        mf.writeFile(outf)
    quit()



bpm = int(input("What should the BPM be? Type an int "))
Sin4th = 60.0 / bpm
Sin8th = float(Sin4th / 2)
Sin16th = float(Sin8th / 2)

Amount16th = int(input("How many 16th in a measure? Type a number "))
Amount8th = Amount16th/2

hatTimingInput = int(input("Do you want the hihat to play 8ths or 16ths? Type 8 or 16 "))

snareAmountInput = int(input("How many snares do you want in your beat? "))
snareProbablityInput = float(input("What is the probablity that those snares will play. 1.0 = Certain, 0.5 = 50/50 "))

kickAmountInput = int(input("How many kicks do you want in your beat? "))
kickProbablityInput = float(input("What is the probablity that those kicks will play. 1.0 = Certain, 0.5 = 50/50 "))

repeats = int(input("How often do you want to loop the rhythm? type an int "))

snareTiming(snareAmountInput,Amount16th)

print("snareTimeStamps = ", snareTimeStamps)

hatTiming(hatTimingInput)

print("hatTimeStamps = ", hatTimeStamps)

kickTiming(kickAmountInput,Amount16th)

print("kickTimeStamps = ", kickTimeStamps)

makeMasArray(hatTimeStamps,snareTimeStamps,kickTimeStamps)

print(masArray)

eventHandler(masArray*repeats)

print("midi array = ",midiMasArray)

def makeMidiFile():
    a = input("Do you want a midifile for this rhythm? Type y/n ")
    if a == "y":
        eventHandler(midiMasArray)
    if a == "n":
        quit()
