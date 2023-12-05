# Recursive-Graphics
Final Project for CSC 212


**Recursive Graphics**
^^^


### Python Setup
```
pip install matplotlib
```
if an upgrade is needed, run the command:
```
pip install --upgrade pip
```

### Sierpinski Triangle
To create the l-system.txt file:
```
g++ STriangle.cpp -o sTriangle
./sTriangle <num of levels>
```
To plot the l-system into a viewable image:
```
python3 l-system-plotter.py l-system.txt sierpinski 120
```
The l-system-plotter.py will then prompt you for a background color and then plot color. The color options that are available are listed below.

### Koch Snowflake
To create the l-system.txt file:
```
g++ koch.cpp -o ksnowflake
./ksnowflake <num of levels>
```
To plot the l-system into a viewable image:
```
python3 l-system-plotter.py l-system.txt kSnowflake 60
```
The l-system-plotter.py will then prompt you for a background color and then plot color. The color options that are available are listed below.

### Hilbert's Curve
To create the l-system.txt file:
```
g++ hilbert.cpp -o hilbert
./hilbert l-system.txt <num of levels>
```
To plot the l-system into a viewable image:
```
python3 l-system-plotter.py l-system.txt hilbertCurve 90 
```
The l-system-plotter.py will then prompt you for a background color and then plot color. The color options that are available are listed below.

### L-System Plotter
The L-System plotter comes with the functionality of asking the user for a color for the plot background and lines. The list of available colors can be found here:

![image](https://github.com/lily-n20/Recursive-Graphics/assets/113806047/eff943d5-e0db-4de8-9122-46c201d021f3)

