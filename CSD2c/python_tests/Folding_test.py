import matplotlib.pylab as plt
import numpy as np

gain = 1.5
outList = []
inList = []
x = np.linspace(np.pi, (2 * np.pi), 44100)

def wrap(x):
    amountFold = 0
    for sample in x:
        print(amountFold)
        #append sample if between 1 and -1
        if sample < 1 and sample > -1:
            outList.append(sample)
        elif sample > 1:
            #if sample is above 1 go to 0 and calulate excess
            if sample > 1 and amountFold == 0:
                excessSample = sample - 1
                outList.append(excessSample)
                amountFold+=1
            #if sample is above 1 and its already folded
            elif sample > (1+amountFold) and amountFold != 0:
                excessSample = sample - (1 + amountFold)
                outList.append(excessSample)
                amountFold+=1
            #if sample is below 1
            elif sample < (1+amountFold) and amountFold != 0:
                amountFold-=1
                excessSample = sample - (1 + amountFold)
                outList.append(excessSample)

        elif sample < -1:
            #if sample is below -1 go to 0,
            if sample < -1 and amountFold == 0:
                excessSample = sample + 1
                outList.append(excessSample)
                amountFold+=1
            #if sample is below -1 go to 0,
            elif sample < (-1-amountFold) and amountFold != 0:
                excessSample = sample + (amountFold + 1)
                outList.append(excessSample)
                amountFold+=1
            #if sample is above -1, and rising
            elif sample > (-1-amountFold) and amountFold != 0:
                amountFold-=1
                excessSample = sample + (amountFold + 1)
                outList.append(excessSample)

def fold(x):
    amountFold = 0
    for sample in x:
        #append sample if between 1 and -1
        if sample < 1 and sample > -1:
            outList.append(sample)
        elif sample > 1:
            #if sample is above 1 go to 0 and calulate excess
            if sample > 1 and amountFold == 0:
                excessSample = sample - 1
                foldedSample = sample - excessSample
                outList.append(foldedSample)
                amountFold+=1
            #if sample is above 1 and its already folded
            elif sample > (1+amountFold) and amountFold != 0:
                excessSample = sample - (1 + amountFold)
                foldedSample = sample - excessSample
                outList.append(foldedSample)
                amountFold+=1
            #if sample is below 1
            elif sample < (1+amountFold) and amountFold != 0:
                amountFold-=1
                excessSample = sample - (1 + amountFold)
                foldedSample = sample - excessSample
                outList.append(foldedSample)

        elif sample < -1:
            #if sample is below -1 go to 0,
            if sample < -1 and amountFold == 0:
                excessSample = sample + 1
                foldedSample = sample + excessSample
                outList.append(foldedSample)
                amountFold+=1
            #if sample is below -1 go to 0,
            elif sample < (-1-amountFold) and amountFold != 0:
                excessSample = sample + (amountFold + 1)
                foldedSample = sample + excessSample
                outList.append(foldedSample)
                amountFold+=1
            #if sample is above -1, and rising
            elif sample > (-1-amountFold) and amountFold != 0:
                amountFold-=1
                excessSample = sample + (amountFold + 1)
                foldedSample = sample + excessSample
                outList.append(foldedSample)

def make_inList(x):
    for i in x:
        hoi = np.sin(i) * gain
        inList.append(hoi)

make_inList(x)
print(inList)

fold(inList)


plt.plot(outList)
plt.axis('tight')
plt.show()
