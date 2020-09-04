import simpleaudio as sa
import time
trigger=0
wave_obj = sa.WaveObject.from_wave_file("nootc.wav")

while trigger==0:
    speelAantal = input("Hoe vaak moet de sample spelen?")
    delay = input ("Hoe veel seconden tussen iedere sample? ")
    if(speelAantal.isdigit()):
        trigger=1
        speelAantal = int(speelAantal)
        delay = float(delay)
        for x in range(speelAantal):
            print(x+1)
            play_obj = wave_obj.play()
            time.sleep(delay)
    else:
        print("Error: voer een nummer in")
