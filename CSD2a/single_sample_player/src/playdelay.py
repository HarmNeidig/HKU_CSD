import simpleaudio as sa
import time
kick=sa.WaveObject.from_wave_file("kick.wav")
t = 0

in_list = list(input("Type bpm then type your desired notelengths with 1 being a quarternote, 0.5 being a eighth.").split(' '))

bpm = in_list.pop(0)

print(in_list)
print(bpm)


while t==0:
    Antwoord = input("do you want to hear your creation? y / n")
    if Antwoord == "y":
        for f in in_list:
            play_obj = kick.play()
            time.sleep(float(f)*(60/(int (bpm))))
    if Antwoord == "n":
        Antwoord2 = input("do you want to change your rhythm? y / n")
        if Antwoord2 == "y":
            in_list.clear()
            in_list = list(input("Type bpm then type your desired notelengths with 1 being a quarternote, 0.5 being a eighth.").split(' '))
        if Antwoord2 == "n":
            t = 0
    else:
        print("error")
