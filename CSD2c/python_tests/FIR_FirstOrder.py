import numpy as np
from matplotlib import pyplot as plt

to_plot_Y = []
to_plot_X = []

# Overdrachts functie voor eerste orde FIR
def Overdrachts_Functie_1(x0,n):
    # initialize xx x[n-1] as 0
    xx = 0
    # initilize x as x[0]
    x = x0
    # generate the impuls response for N points
    for i in range(0,n):
        # Formula on page 10 of pieter's book
        y = 0.5 * (x + xx)
        # Sets xx to x one iteration ago
        xx = x
        # Sets the impuls to 0
        x = 0
        to_plot_X.append(i)
        to_plot_Y.append(y)

# Overdrachts functie voor eerste orde FIR
def Overdrachts_Functie_2(x0,n):
    xx = 0
    x = x0
    for i in range(0,n):
        # Formula on page 10 of pieter's book
        y = (x * 0.5) + (xx * -0.5)
        # Sets xx to x one iteration ago
        xx = x
        # Sets the impuls to 0
        x = 0
        to_plot_X.append(i)
        to_plot_Y.append(y)

def impulsResponsGrafiek():
    plt.stem(to_plot_X,to_plot_Y)
    plt.show()


print(Overdrachts_Functie_2(1,5))
impulsResponsGrafiek()
