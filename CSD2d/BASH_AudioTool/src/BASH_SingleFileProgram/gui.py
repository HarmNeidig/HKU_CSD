import tkinter as tk
from tkinter import ttk
import os
from tkinter import filedialog
from ttkthemes import ThemedTk
import simpleaudio as sa
import shutil
import warnings
global root
global listedFilesIn
global listedFilesOut
pathlistIn = []
pathlistOut = []

output_dir = '/Users/harm/desktop/oude_desktop/HKU_CSd/CSD2d/BASH_AudioTool/Audio_resources/sox_output'
temp_in_dir = '/Users/harm/desktop/oude_desktop/HKU_CSd/CSD2d/BASH_AudioTool/Audio_resources/sox_input'

## addes files to input query
def add_files():
    dir = filedialog.askdirectory()
    dir_path = os.listdir(dir)
    for i in range(len(dir_path)):
        if ' ' in dir_path[i]:
            print("ERROR: no whitespaces allowed in files")
            print("white spaces detected in ",i,"th file.")
        else:
            if dir_path[i].endswith('.wav') == True:
                inputFileList.insert(i, dir_path[i])
                pathlistIn.append(dir+'/'+dir_path[i])
                listedFilesIn=+1

## passes the path of the selected file
def get_file_path_in():
    selected_value = get_value_listbox_in()
    for path in pathlistIn:
        head_tail = os.path.split(path)
        tail = head_tail[-1]
        if selected_value == tail:
            return path

## passes the path of the selected file
def get_file_path_out():
    selected_value = get_value_listbox_out()
    for path in pathlistOut:
        head_tail = os.path.split(path)
        tail = head_tail[-1]
        if selected_value == tail:
            return path

## plays the audio of the selected file
def play_file_in():
    path = get_file_path_in()
    print(path)
    wave_temp = sa.WaveObject.from_wave_file(path)
    wave_temp.play()

def play_file_out():
    path = get_file_path_out()
    print(path)
    wave_temp = sa.WaveObject.from_wave_file(path)
    wave_temp.play()

def stop_all():
    sa.stop_all()

def clear_list_in():
    inputFileList.delete(0,tk.END)
    pathlistIn.clear()

def clear_list_out():
    delete_folder_out()
    outputFileList.delete(0,tk.END)
    pathlistOut.clear()

def delete_folder_out():
    for i in pathlistOut:
        print("Deleting: ",i)
        os.remove(i)

def get_value_listbox_in():
    selected_value = [inputFileList.get(i) for i in inputFileList.curselection()]
    return selected_value[0]

def clear_list_in():
    inputFileList.delete(0,tk.END)
    pathlistIn.clear()

def get_value_listbox_out():
    selected_value = [outputFileList.get(i) for i in outputFileList.curselection()]
    return selected_value[0]

def export():
    input_file_path=get_file_path_in()
    output = output_file.get()
    if output != "":
        output = output + '.wav'
        output_file_path=output_dir+'/'+output
        # trim + fade
        if fxSelection.get() == 1:
            if(fxParam1.get()>(fxParam2.get()/2.)):
                print("error: fadetime must be at least half of length")
            else:
                os.system("./sox_01.sh "+input_file_path
                +" "+output_file_path+" "+(str(fxParam1.get()))
                +" "+(str(fxParam2.get())))
                outputFileList.insert(0, output)
                pathlistOut.append(output_dir+'/'+output)
                listedFilesOut=+1
        # delay
        if fxSelection.get() == 2:
            os.system("./sox_02.sh "+input_file_path
            +" "+output_file_path+" "+(str(fxParam1.get()))
            +" "+(str(fxParam2.get())))
            outputFileList.insert(0, output)
            pathlistOut.append(output_dir+'/'+output)
            listedFilesOut=+1
        # reverb
        if fxSelection.get() == 3:
            os.system("./sox_03.sh "+input_file_path
            +" "+output_file_path+" "+(str(fxParam1.get()))
            +" "+(str(fxParam2.get())))
            outputFileList.insert(0, output)
            pathlistOut.append(output_dir+'/'+output)
            listedFilesOut=+1
        # distorion
        if fxSelection.get() == 4:
            os.system("./sox_04.sh "+input_file_path
            +" "+output_file_path+" "+(str(fxParam1.get()*2))
            +" "+(str(fxParam2.get()*2)))
            outputFileList.insert(0, output)
            pathlistOut.append(output_dir+'/'+output)
            listedFilesOut=+1
        # tremolo
        if fxSelection.get() == 5:
            os.system("./sox_05.sh "+input_file_path
            +" "+output_file_path+" "+ (str(fxParam1.get()))
            +" "+(str(fxParam2.get()*10)))
            outputFileList.insert(0, output)
            pathlistOut.append(output_dir+'/'+output)
            listedFilesOut=+1

def output_list_to_input():
    clear_list_in()
    for path in pathlistOut:
        head_tail = os.path.split(path)
        tail = head_tail[-1]
        new_path = temp_in_dir+'/'+tail
        print(new_path)
        dest = shutil.move(path,new_path)
        print(dest)
        pathlistIn.append(new_path)
        inputFileList.insert(0,tail)
    clear_list_out()

## sets up window
root=ThemedTk(theme='black')
root.configure(bg='black')
root.title('UNIX Sounddesign tool')

## initalize widgets
inputFileTxt = ttk.Label(root, text="Select input file")
addFilesButton = ttk.Button(root, text="add files", command=add_files)
playButton1 = ttk.Button(root, text="play file", command=play_file_in)
stopButton = ttk.Button(root, text="stop audio", command=stop_all)
inputFileList = tk.Listbox()
inputFileList.config(bg='grey75')
clearListButton = ttk.Button(root, text="clear list", command=clear_list_in)
fxSelection = tk.IntVar()
SelectFxCb1 = ttk.Radiobutton(root, text='Trim',variable=fxSelection, value=1)
SelectFxCb2 = ttk.Radiobutton(root, text='Delay',variable=fxSelection, value=2)
SelectFxCb3 = ttk.Radiobutton(root, text='Reverb',variable=fxSelection, value=3)
SelectFxCb4 = ttk.Radiobutton(root, text='Distortion',variable=fxSelection, value=4)
SelectFxCb5 = ttk.Radiobutton(root, text='Tremolo',variable=fxSelection, value=5)
outputFileTxt = ttk.Label(root, text="Select output name")
output_file = tk.StringVar()
outputFileEntry = ttk.Entry(root, width = 15, textvariable = output_file)
exportButton = ttk.Button(root, text='export file', command=export)
playButton2 = ttk.Button(root, text="play file", command=play_file_out)
fxParam1 = tk.IntVar()
fxParamSlider1 = ttk.Scale(root, from_=1, to=10, variable=fxParam1)
fxParam2 = tk.IntVar()
fxParamSlider2 = ttk.Scale(root, from_=1, to=10, variable=fxParam2)
outputFileTxt = ttk.Label(root, text="Select output file")
outputFileList = tk.Listbox()
outputFileList.config(bg='grey75')
outputFolderClearButton = ttk.Button(root, text='Delete all output files', command=clear_list_out)
outputListToInputListButton = ttk.Button(root, text='Output list to inputlist', command=output_list_to_input)


for file in os.listdir(output_dir):
    outputFileList.insert(tk.END, file)
    pathlistOut.append(output_dir + '/' + file)

for file in os.listdir(temp_in_dir):
    inputFileList.insert(tk.END, file)
    pathlistIn.append(temp_in_dir + '/' + file)

print(pathlistOut)

## adds widgets
inputFileTxt.pack()
addFilesButton.pack()
playButton1.pack()
stopButton.pack()
inputFileList.pack(expand=True)
clearListButton.pack()
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
outputFolderClearButton.pack()
outputListToInputListButton.pack()
## application main loop
root.mainloop()
