import tkinter as tk
from tkinter import ttk
import os
from tkinter import filedialog
from ttkthemes import ThemedTk
import simpleaudio as sa
import shutil

global root
global listedFilesIn
global listedFilesOut
pathlistIn = []
pathlistOut = []

output_dir = '/Users/harm/desktop/HKU_CSd/CSD2d/BASH_AudioTool/Audio_resources/sox_output'
temp_in_dir = '/Users/harm/desktop/HKU_CSd/CSD2d/BASH_AudioTool/Audio_resources/sox_input'

## addes files to input query
def add_files():
    dir = filedialog.askdirectory()
    dir_path = os.listdir(dir)
    for i in range(len(dir_path)):
        if dir_path[i].endswith('.wav') == True:
            inputFileList.insert(i, dir_path[i])
            pathlistIn.append(dir+'/'+dir_path[i])
            listedFilesIn=+1

## passes the path of the selected file
def get_file_path_in(file):
    selected_value = file
    for path in pathlistIn:
        head_tail = os.path.split(path)
        tail = head_tail[-1]
        if selected_value == tail:
            return path

## passes the path of the selected file
def get_file_path_out():
    selected_values = get_values_listbox_out()
    for selected_value in selected_values:
        for path in pathlistOut:
            head_tail = os.path.split(path)
            tail = head_tail[-1]
            if selected_value == tail:
                return path

def play_file_out():
    path = get_file_path_out()
    wave_temp = sa.WaveObject.from_wave_file(path)
    wave_temp.play()

def stop_all():
    sa.stop_all()

def select_all():
    inputFileList.select_set(0, END)

def clear_list_in():
    inputFileList.delete(0,'end')
    pathlistIn.clear()

def clear_list_out():
    outputFileList.delete(0,'end')
    pathlistOut.clear()

def get_values_listbox_in():
    selected_values = []
    for i in inputFileList.curselection():
        selected_values.append(inputFileList.get(i))
    return selected_values

def clear_list_in():
    inputFileList.delete(0,'end')
    pathlistIn.clear()

def get_values_listbox_out():
    selected_values = []
    for i in outputFileList.curselection():
        selected_values.append(outputFileList.get(i))
    return selected_values

def export():
    values_to_export = get_values_listbox_in()
    print(values_to_export)
    for file in values_to_export:
        input_file_path=str(get_file_path_in(file))
        output = str(output_file.get())
        if output != "":
            if file.endswith(".wav"):
                output = output + file
            else:
                output = file + output + '.wav'
            output_file_path=output_dir+'/'+output
            # trim + fade
            if fxSelection.get() == 1:
                os.system(
                "./sox_01.sh "+input_file_path+" "+output_file_path+
                " "+(str(fxParam1.get()))+" "+(str(fxParam2.get()))
                )
            # delay
            if fxSelection.get() == 2:
                os.system(
                "./sox_02.sh "+input_file_path+" "+output_file_path+
                " "+(str(fxParam1.get()))+" "+(str(fxParam2.get()))
                )
            # reverb
            if fxSelection.get() == 3:
                os.system(
                "./sox_03.sh "+input_file_path+" "+output_file_path+
                " "+(str(fxParam1.get()))+" "+(str(fxParam2.get()))
                )
            # distorion
            if fxSelection.get() == 4:
                os.system(
                "./sox_04.sh "+input_file_path+" "+output_file_path+
                " "+(str(fxParam1.get()*2))+" "+(str(fxParam2.get()*2))
                )
            # tremolo
            if fxSelection.get() == 5:
                os.system(
                "./sox_05.sh "+input_file_path+" "+output_file_path+
                " "+(str(fxParam1.get()))+" "+(str(fxParam2.get()*10))
                )
            outputFileList.insert(0, output)
            pathlistOut.append(output_dir+'/'+output)
            listedFilesOut=+1

def output_list_to_input():
    clear_list_in()
    for path in pathlistOut:
        head_tail = os.path.split(path)
        tail = head_tail[-1]
        new_path = temp_in_dir+'/'+tail
        dest = shutil.move(path,new_path)
        pathlistIn.append(new_path)
        inputFileList.insert(0,tail)
    clear_list_out()

## sets up window
root=ThemedTk(theme="black")
root.configure(bg='black')
root.title('UNIX Sounddesign tool')

## initalize widgets
inputFileTxt = ttk.Label(root, text="Select input file")
addFilesButton = ttk.Button(root, text="add files", command=add_files)
inputFileList = tk.Listbox(root, selectmode='MULTIPLE')
inputFileList.config(bg='grey75')
clearListButton = ttk.Button(root, text="clear list", command=clear_list_in)
selectAllButton = ttk.Button(root, text="select all", command=select_all)
fxSelection = tk.IntVar()
SelectFxCb1 = ttk.Radiobutton(root, text='Trim',variable=fxSelection, value=1)
SelectFxCb2 = ttk.Radiobutton(root, text='Delay',variable=fxSelection, value=2)
SelectFxCb3 = ttk.Radiobutton(root, text='Reverb',variable=fxSelection, value=3)
SelectFxCb4 = ttk.Radiobutton(root, text='Distortion',variable=fxSelection, value=4)
SelectFxCb5 = ttk.Radiobutton(root, text='Tremolo',variable=fxSelection, value=5)
outputFileTxt = ttk.Label(root, text="Select output name")
output_file = tk.StringVar()
outputFileEntry = ttk.Entry(root, width = 15, textvariable = output_file,background='grey50')
exportButton = ttk.Button(root, text='export files', command=export)
playButton2 = ttk.Button(root, text="play file", command=play_file_out)
fxParam1 = tk.IntVar()
fxParamSlider1 = ttk.Scale(root, from_=1, to=10, variable=fxParam1)
fxParam2 = tk.IntVar()
fxParamSlider2 = ttk.Scale(root, from_=1, to=10, variable=fxParam2)
outputFileTxt = ttk.Label(root, text="Select output file")
outputFileList = tk.Listbox()
outputFileList.config(bg='grey75')

outputListToInputListButton = ttk.Button(root, text='Output list to input list', command=output_list_to_input)


for file in os.listdir(output_dir):
    outputFileList.insert(tk.END, file)
    pathlistOut.append(output_dir + '/' + file)

for file in os.listdir(temp_in_dir):
    inputFileList.insert(tk.END, file)
    pathlistIn.append(temp_in_dir + '/' + file)


## adds widgets
inputFileTxt.pack()
addFilesButton.pack()
inputFileList.pack(expand=True)
clearListButton.pack()
selectAllButton.pack()
fxParamSlider1.pack()
fxParamSlider2.pack()

SelectFxCb1.pack()
SelectFxCb2.pack()
SelectFxCb3.pack()
SelectFxCb4.pack()
SelectFxCb5.pack()

outputFileTxt.pack()
outputFileEntry.pack()
exportButton.pack()
playButton2.pack()
outputFileTxt.pack()
outputFileList.pack(expand=True)
outputListToInputListButton.pack()
## application main loop
root.mainloop()
