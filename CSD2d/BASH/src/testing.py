import os

pathlist = ['boem/bats/jo.wav','boem/bats/b.wav','boem/bats/hallo.txt']

def play_file():
    selected_value = ["hallo.txt"]
    print(selected_value)
    for path in pathlist:
        head_tail = os.path.split(path)
        tail = head_tail[-1]
        if selected_value == tail:
            print("GETGETGETGETGOTGOTGOTGOT")
            print(path)

play_file()
