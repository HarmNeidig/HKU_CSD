def rotate(lst, beginpoint):
#    beginpoint-=1
    return lst[beginpoint:] + lst[:beginpoint]

lijst = [1, 2, 3, 4]

Begin = int(input("how much rotation"))

lijst = rotate(lijst, Begin)

print(lijst)
