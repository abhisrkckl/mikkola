from mikkola import MIKKOLA
import numpy as np
from matplotlib import pyplot as plt

pi = np.pi

e = 0.4
u0s = np.linspace(-2*pi,2*pi,1000)
ls  = u0s - e*np.sin(u0s)
us  = np.zeros_like(ls)

for i,l in enumerate(ls):
    us[i] = MIKKOLA(l,e)

plt.plot(ls,np.abs((u0s-us)/us))
plt.xlabel("l")
plt.ylabel("Fractional error")
plt.show()
