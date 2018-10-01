# mikkola

## Introduction

This is an implementation of Mikkola's method to solve Kepler's equation.
(Ref: <adsabs.harvard.edu/full/1987CeMec..40..329M>)

This package defines two functions:
  
1)  double MIKKOLA(double l, double e)		--- Solves the Elliptic Kepler equation.
  
2)  double MIKKOLAh(double l, double e)		--- Solves the Hyperbolic Kepler equation.

## Requirements
- g++
- python
- swig3.0
- python-dev  and  python3-dev
- The python example requires numpy and matplotlib.


## Building
- To build the python interface, type
> make python_interface

Note that the by default this creates a wrapper for Python3. 
To make a wrapper for Python2 change the PYTHONI variable in the Makefile to the location of Python.h in your Python2 installation.

- To build the C++ example programs, type
> make tests


## Python interface
Please see example.py for usage.


## Troubleshooting
- If "make python_interface" fails complaining about missing Python.h, make sure that the PYTHONI variable in Makefile points to the location of Python.h.
Also, ensure that the packages "python-dev" and "python3-dev" are installed.


