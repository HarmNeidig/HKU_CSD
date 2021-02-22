arrayWithBitVals = []
crushedArray = []
sampleArray = [0.9, -0.9, 0.1, -0.1]

def makeArray(bitDepth):
    step = 2. / bitDepth
    bitValue = step
    print("bitValue = ", bitValue)
    firststep = -1.
    arrayWithBitVals.append(firststep)
    for step in range(bitDepth):
        firststep+=bitValue
        arrayWithBitVals.append(firststep)


## NOG NIET AF
def compareArray(arrayWithBitVals, sampleArray):
    for i in sampleArray:
        for bitVal in arrayWithBitVals:
            if bitVal <= 0.:
                if i >= arrayWithBitVals[1]:
                    crushedArray.append(bitVal)
            if bitVal > 0:
                if i <= arrayWithBitVals[-1]:
                    crushedArray.append(bitVal)


makeArray(4)
print("SampleArray= ")
print(sampleArray)
print("arrayWithBitDepth= ")
print(arrayWithBitVals)
compareArray(arrayWithBitVals, sampleArray)
print(crushedArray)
