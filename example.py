from mikkola import *
import numpy as np
from matplotlib import pyplot as plt

pi = np.pi

e = 0.4
u0s = np.linspace(-4*pi,4*pi,1000)
ls  = u0s - e*np.sin(u0s)
#us  = np.zeros_like(ls)

#for i,l in enumerate(ls):
#    us[i] = MIKKOLA(l,e)

#us = np.array(tuple(map(lambda l: MIKKOLA(l,e), ls)))
us = MIKKOLA(ls,e)
    
plt.plot(ls,np.abs((u0s-us)/us))
plt.title("Elliptic")
plt.xlabel("l")
plt.ylabel("Fractional error")
plt.grid()
plt.show()

#***************

e = 1.1
u0s = np.linspace(-5,5,1000)
ls = e*np.sinh(u0s) - u0s
us = MIKKOLAh(ls,e)

plt.plot(ls,np.abs((u0s-us)/us))
plt.title("Hyperbolic")
plt.xlabel("l")
plt.ylabel("Fractional error")
plt.grid()
plt.show()
