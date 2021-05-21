from tkinter import *
import os
from tkinter import filedialog
import simpleaudio as sa

global root
global listedFiles
pathlist = []

output_dir = '/Users/harm/desktop/HKU_CSd/CSD2d/Bash/Audio_resources/sox_output'


def add_files():
    dir=filedialog.askdirectory()
    dir_path = os.listdir(dir)
    print(dir_path)
    for i in range(len(dir_path)):
        if dir_path[i].endswith('.wav') == True:
            inputFileList.insert(i, dir_path[i])
            pathlist.append(dir+'/'+dir_path[i])
            listedFiles=+1

## vraag aan bas: workaround voor de refrenced before assignment
# if wave_temp.isPlaying() == True
## passes the path of the selected file
def play_file():
    selected_value = get_value_listbox()
    for path in pathlist:
        head_tail = os.path.split(path)
        tail = head_tail[-1]
        if selected_value == tail:
            wave_temp = sa.WaveObject.from_wave_file(path)
            wave_temp.play()

def get_file_path():
    selected_value = get_value_listbox()
    for path in pathlist:
        head_tail = os.path.split(path)
        tail = head_tail[-1]
        if selected_value == tail:
            return path

def stop_all():
    sa.stop_all()

def add_fade():
    print("sox msg here")

def clear_list():
    inputFileList.delete(0,'end')
    pathlist.clear()

def get_value_listbox():
    selected_value = [inputFileList.get(i) for i in inputFileList.curselection()]
    return selected_value[0]

def export():
    input_file_path=get_file_path()
    output = output_file.get()
    if output != "":
        output = output + '.wav'
        output_file_path=output_dir+'/'+output
        if fx1.get() == 1:
            print('run sox')
            os.system("./sox_01.sh "+input_file_path+" "+output_file_path+" 1 4")
        if fx2.get() == 1:
            print('run sox')
            os.system("./sox_01.sh "+input_file_path+" "+output_file_path+" 1 4")

"""
def get_len_in_sec():
    selected_value = get_value_listbox()
    for path in pathlist:
        head_tail = os.path.split(path)
        tail = head_tail[-1]
        if selected_value == tail:
"""


## sets up window
root=Tk()
root.title('UNIX Sounddesign tool')

## initalize widgets
inputFileTxt = Label(root, text="Select input file")
addFilesButton = Button(root, text="add files", command =add_files)
playButton = Button(root, text="play file", command=play_file)
stopButton = Button(root, text="stop audio", command=stop_all)
inputFileList = Listbox()
clearListButton = Button(root, text="clear list", command=clear_list)
fx1 = IntVar()
SelectFxCb1 = Checkbutton(root, text='Effects option 1',variable=fx1, onvalue=1, offvalue=0)
fx2 = IntVar()
SelectFxCb2 = Checkbutton(root, text='Effects option 2',variable=fx2, onvalue=1, offvalue=0)
outputFileTxt = Label(root, text="Select output name")
output_file = StringVar()
outputFileEntry = Entry(root, width = 15, textvariable = output_file)
exportButton = Button(root, text='export file', command=export)
#addFadeButton = Button(root, text="add fades", command=add_fade)
#fadeTxt = Label(root, text="Fade duration in sec")
#fadeDurationSlider = Scale(root, from_=0, to=6, orient=HORIZONTAL)

## adds widgets
inputFileTxt.pack()
addFilesButton.pack()
playButton.pack()
stopButton.pack()
inputFileList.pack()
clearListButton.pack()
SelectFxCb1.pack()
outputFileTxt.pack()
outputFileEntry.pack()
exportButton.pack()
#addFadeButton.pack()
#fadeTxt.pack()
#fadeDurationSlider.pack()

## application main loop
root.mainloop()
