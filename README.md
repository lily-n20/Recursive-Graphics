# Recursive-Graphics
Final Project for CSC 212


**Recursive Graphics**
^^^

**_Implement recursive fractals_**
  - Sierpinski Triangle
  - Hilbert Curve
  - Koch snowflake

**_Save each output to a PDF or image file_**

USE/Research:
- L Systems
- Python Turtle
- Tessellation (extra if we finish?)


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
g++ SierpinskiTriangle.cpp -o sierpinski
./sierpinski 5
```
To plot the l-system into a viewable image:
```
python lsystemplotter.py l-system.txt sierpinski.png 120
```
### Hilbert's Curve
To create the l-system.txt file:
```
g++ Hilbert.cpp -o hilbert
./hilbert l-system.txt 4
```
