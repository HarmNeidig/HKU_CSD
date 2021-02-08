arrayWithSteps = []

def makeArray(bitDepth):
    step = 2. / bitDepth
    bitValue = step
    print("bitValue = ", bitValue)
    firststep = -1.
    arrayWithSteps.append(firststep)
    for step in range(bitDepth):
        firststep+=bitValue
        arrayWithSteps.append(firststep)

makeArray(24)
print(arrayWithSteps)
