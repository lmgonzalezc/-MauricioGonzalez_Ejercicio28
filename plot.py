import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Calor.dat")
grid = np.reshape(data, (200, 200))

plt.figure()
plt.imshow(grid)
plt.xlabel("X")
plt.ylabel("Y")
plt.savefig("plot.png")
