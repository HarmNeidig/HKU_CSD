# Import libraries
import simpleaudio as sa
import time as t
import random as r
from midiutil import MIDIFile

# Define lists
snareTimeStamps = []
rotatedSnareTimeStamps = []
hatTimeStamps = []
kickTimeStamps = []
masArray = []
midiMasArray = []
blockArray = []
# Define midifile
mf = MIDIFile(1)

# Define Audio paths
kick = sa.WaveObject.from_wave_file("audio/kick.wav")
snare = sa.WaveObject.from_wave_file("audio/snare.wav")
hat = sa.WaveObject.from_wave_file("audio/hihat.wav")

# Make a array for the hihat timestamps
def hatTiming(hatTimingInput):
    # Calculate timestamps if the user selected 8ths
    if hatTimingInput == 8:
        x = float(Amount8th)
        # If even
        if (Amount16th%2) == 0:
            for i in range(0,int(Amount8th)):
                hatTimeStamps.append(1)
                hatTimeStamps.append(0)
        # If odd
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
    # Calculate timestamps if the user selected 16ths
    if hatTimingInput == 16:
        for i in range(0,Amount16th):
            hatTimeStamps.append(1)

# Calculate snare timestamp list
def snareTiming(snareAmountInput,Amount16th):
    # Calculates how many rests after a snare there should be
    snareCycle = int(Amount16th / snareAmountInput)
    # Append the probability of the snare
    for i in range(0,snareAmountInput):
        snareTimeStamps.append(snareProbablityInput)
        # Append rests
        for i in range(snareCycle-1):
            snareTimeStamps.append(0)
    # If the length of the snare timestamps list is not equal to the total amount of 16th
    if len(snareTimeStamps) != Amount16th:
        # Randomly adds rests to the beat until the snare timestamps list is equal to the amount of 16th
        missingSnareRest = Amount16th - len(snareTimeStamps)
        for i in range(missingSnareRest):
            snareTimeStamps.insert((r.randint(0,len(snareTimeStamps))), 0)

# This function is for the rotation of the snare timestamp list
def rotateSnare(lst, snareRotInput):
    lst = lst[snareRotInput:] + lst[:snareRotInput]
    for i in lst:
        rotatedSnareTimeStamps.append(i)

# Calculate kick timestamps list
def kickTiming(kickAmountInput,Amount16th):
    # Calculates how many rests after a kick there should be
    kickCycle = int(Amount16th / kickAmountInput)
    # Append the probability of the kick
    for i in range(0,kickAmountInput):
        kickTimeStamps.append(kickProbablityInput)
        # Append rests
        for i in range(kickCycle-1):
            kickTimeStamps.append(0)
    # If the length of the kick timestamps list is not equal to the total amount of 16th
    if len(kickTimeStamps) != Amount16th:
        # Randomly adds rests to the beat until the kick timestamps list is equal to the amount of 16th
        missingKickRest = Amount16th - len(kickTimeStamps)
        for i in range(missingKickRest):
            kickTimeStamps.insert((r.randint(0,len(kickTimeStamps))), 0)

# Joins the 3 timestamp lists to a master array
def makeMasArray(lstHat, lstSnare, lstKick):
    # Each list in the master array is a individual timestamp
    for i in range(0,Amount16th):
        Ts_Array = []
        # Makes arrays of three (index 0 = hat, index 1 = snare and index 2 = kick)
        Ts_Array.append(lstHat[i])
        Ts_Array.append(lstSnare[i])
        Ts_Array.append(lstKick[i])
        # Append the current timestamp list to the master array
        masArray.append(Ts_Array)
    return

# Calculates seeds for snare and kick. Plays them if the probability is higher than the seed
def eventHandler(lst):
    for array in lst:
        # The blockArray is for making the midifile. If the probablity is bigger than the seed it appends an 1, else a 0.
        blockArray = []
        # Generates seeds to compare to the propabilities
        snareSeed = r.random()
        kickSeed = r.random()
        # For loop for playing hihat
        if array[0] == 1:
            hat.play()
            blockArray.append(1)
        else:
            blockArray.append(0)
        # For loop for playing snare, calculates if the snare should be played
        if array[1] > snareSeed:
            snare.play()
            blockArray.append(1)
        else:
            blockArray.append(0)
        # For loop for playing kick, calculates if the kick should be played
        if array[2] > kickSeed:
            kick.play()
            blockArray.append(1)
        else:
            blockArray.append(0)
        # Appends current timestamp array to the midi master array
        midiMasArray.append(blockArray)
        # Sleep until the next timestamp should be played
        t.sleep(Sin16th)

# Define midi notes
kickMidiNote = 24
snareMidiNote = 26
hatMidiNote = 30

# Function to convert the master midi array to the midi file
def eventHandlerMidi(lst):
    time = 0
    track = 0
    mf.addTempo(track, time, bpm)
    for array in lst:
        if array[0] == 1:
            mf.addNote(0, 0, hatMidiNote, time, 0.25, 127)
        if array[1] == 1:
            mf.addNote(0, 0, snareMidiNote, time, 0.25, 127)
        if array[2] == 1:
            mf.addNote(0, 0, kickMidiNote, time, 0.25, 127)
        time+=1
    # Writes the midi file
    with open("BEAT_GENERATOR.midi",'wb') as outf:
        mf.writeFile(outf)
    quit()

# Asks if you want to make a midifile
def makeMidiFile():
    a = input("Do you want a midifile for this rhythm? Type y/n ")
    if a == "y":
        eventHandlerMidi(midiMasArray)
    if a == "n":
        quit()

# Error handeling for the bpm input
def inputBpm():
    global Sin4th, Sin8th, Sin16th, bpm
    bpm = (input("What should the BPM be? Type an int "))
    try:
        bpm = int(bpm)
        if bpm not in list(range(50,200)):
            print("seems like your bpm is out of range")
            inputBpm()
        else:
            Sin4th = 60.0 / bpm
            Sin8th = float(Sin4th / 2)
            Sin16th = float(Sin8th / 2)
            print("bpm is",bpm)
    except ValueError:
        print("please type an int")
        inputBpm()

# Error handeling for the amount of 16th input
def inputAmount():
    global Amount16th, Amount8th
    Amount16th = (input("How many 16th in a measure? Type an int "))
    try:
        Amount16th = int(Amount16th)
        if Amount16th not in list(range(4,20)):
            print("seems like your prefered amount is out of range")
            inputAmount()
        else:
            Amount8th = Amount16th/2
            print("Amount of 16ths is",Amount16th)
    except ValueError:
        print("please type an int")
        inputAmount()

# Error handeling for the hihat input
def inputHat():
    global hatTimingInput
    hatTimingInput = input("Do you want the hihat to play 8ths or 16ths? Type 8 or 16 ")
    try:
        hatTimingInput = int(hatTimingInput)
        if hatTimingInput == 8 or hatTimingInput == 16:
            if hatTimingInput == 8:
                print("The hat will play 8ths")
            elif hatTimingInput == 16:
                print("The hat will play 16ths")
        else:
            print("please enter a 8 or 16")
            inputHat()
    except ValueError:
        print("please type an int")
        inputHat()

# Error handeling for the snare amount input
def inputAmountSnare():
    global snareAmountInput
    snareAmountInput = input("How many snares do you want in your beat? ")
    try:
        snareAmountInput = int(snareAmountInput)
        if snareAmountInput > Amount16th:
            print("please enter a number smaller than the amount of 16th")
            inputAmountSnare()
        else:
            print("your amount of snares is",snareAmountInput)
    except ValueError:
        print("please type an int")
        inputAmountSnare()

# Error handeling for the snare rotation input
def inputRotSnare():
    global snareRotInput
    snareRotInput = input("Do you want to rotate your snare list? if not type 0, else type an int with the rotation amount ")
    try:
        snareRotInput = int(snareRotInput)
    except ValueError:
        print("please type an int")
        inputRotSnare()

# Error handeling for the snare probablity input
def inputProbSnare():
    global snareProbablityInput
    snareProbablityInput = input("What is the probablity that those snares will play. 1.0 = Certain, 0.5 = 50/50 ")
    try:
        snareProbablityInput = float(snareProbablityInput)
        if snareProbablityInput > 1.0:
            print("please enter a float between 0.0 and 1.0")
            inputProbSnare()
        elif snareProbablityInput < 0.0:
            print("please enter a float between 0.0 and 1.0")
            inputProbSnare()
        elif snareProbablityInput == 0.0:
            print("please enter a float between 0.0 and 1.0")
            inputProbSnare()
        else:
            print("the probablity of your snares will be", snareProbablityInput)
    except ValueError:
        print("please type an float")
        inputProbSnare()

# Error handeling for the kick amount input
def inputAmountKick():
    global kickAmountInput
    kickAmountInput = input("How many kicks do you want in your beat? ")
    try:
        kickAmountInput = int(kickAmountInput)
        if kickAmountInput > Amount16th:
            print("please enter a number smaller than the amount of 16th")
            inputAmountKick()
        else:
            print("your amount of kicks is",kickAmountInput)
    except ValueError:
        print("please type an int")
        inputAmountKick()

# Error handeling for the kick probablity input
def inputProbKick():
    global kickProbablityInput
    kickProbablityInput = input("What is the probablity that those snares will play. 1.0 = Certain, 0.5 = 50/50 ")
    try:
        kickProbablityInput = float(kickProbablityInput)
        if kickProbablityInput > 1.0:
            print("please enter a float between 0.0 and 1.0")
            inputProbKick()
        elif kickProbablityInput < 0.0:
            print("please enter a float between 0.0 and 1.0")
            inputProbKick()
        else:
            print("the probablity of your kicks will be", kickProbablityInput)
    except ValueError:
        print("please type an float")
        inputProbKick()

# Error handeling for the repeat input
def inputRepeat():
    global repeats
    repeats = input("How often do you want to loop the rhythm? type an int ")
    try:
        repeats = int(repeats)
        if repeats == 0:
            print("why would you make a beat if you aren't going to play it?")
            inputRepeat()
        elif repeats > 100:
            print("That's too much.. try a lower int")
            inputRepeat()
        else:
            print("Your beat will repeat", repeats,"times")
    except ValueError:
        print("please type an int")
        inputRepeat()

# Runs all the input functions
inputBpm()
inputAmount()
inputHat()
inputAmountSnare()
inputProbSnare()
inputRotSnare()
inputAmountKick()
inputProbKick()
inputRepeat()

# Runs all the functions that calculate the timestamps
hatTiming(hatTimingInput)
snareTiming(snareAmountInput,Amount16th)
rotateSnare(snareTimeStamps, snareRotInput)
kickTiming(kickAmountInput,Amount16th)
makeMasArray(hatTimeStamps,rotatedSnareTimeStamps,kickTimeStamps)
# Plays the rhythm
eventHandler(masArray*repeats)
# Makes the midi file
makeMidiFile()
