import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
#from matplotlib import cm

mpl.use('Agg')
import sys
from math import pi, sin, cos
DEGREES_TO_RADIANS = pi / 180
from math import isnan
# plt.rcParams['axes.facecolor'] = 'green'
# cmap=plt.get_cmap('ocean')

def plot_coords(coords, fname, bare_plot=False, background_color='green', plot_color='r'):
    if bare_plot:
        # Turns off the axis markers.
        plt.axis('off')

    # Set the background color
    plt.gcf().set_facecolor(background_color)

    # Ensures equal aspect ratio.
    plt.axes().set_aspect('equal', 'datalim')

    # Converts a list of coordinates into
    # lists of X and Y values, respectively.
    X, Y = zip(*coords)

    # Draws the plot.
    plt.plot(X, Y, plot_color)
    plt.axis('off')
    plt.savefig(fname)


def print_coords(coords):
    for (x, y) in coords:
        if isnan(x):
            print('<gap>')
        else:
            print('({:.2f}, {:.2f})'.format(x, y))

def turtle_to_coords(turtle_program, turn_amount=60):
    # The state variable tracks the current location and angle of the turtle.
    # The turtle starts at (0, 0) facing right (0 degrees).
    state = (0.0, 0.0, 0.0)

    # Throughout the turtle's journey, we "yield" its location. These coordinate
    # pairs become the path that plot_coords draws.
    yield (0.0, 0.0)

    # Loop over the program, one character at a time.
    for command in turtle_program:
        x, y, angle = state

        if command in 'FB':      # Move turtle forward or backward
            direction = -1 if command == 'F' else 1
            state = (x + direction * cos(angle * DEGREES_TO_RADIANS),
                     y - direction * sin(angle * DEGREES_TO_RADIANS),
                     angle)
            yield (state[0], state[1])


        elif command == '+':     # Turn turtle clockwise without moving
            state = (x, y, angle + turn_amount)

        elif command == '-':     # Turn turtle counter-clockwise without moving
            state = (x, y, angle - turn_amount)

def run_turtle_program(in_fname, out_fname, angle, background_color, plot_color):
    with open(in_fname, 'r') as file:
        data = file.read().replace('\n', ' ')
        plot_coords(turtle_to_coords(data, angle), out_fname, background_color=background_color, plot_color=plot_color)

def get_color_input(prompt):
    while True:
        color = input(prompt)
        # Uses matplotlib colors to determine if a valid color is entered
        if mcolors.is_color_like(color):
            return color
        else:
            print("Invalid color. Please enter a valid color.")

# Ask user for colors
background_color = get_color_input('Enter background color: ')
plot_color = get_color_input('Enter plot color: ')

# Handle command line arguments
try:
    in_fname = sys.argv[1]
    out_fname = sys.argv[2]
    angle = int(sys.argv[3])
except IndexError:
    print("Please provide an input file, an output file, and an angle.")
    sys.exit(1)

# Run the turtle program
try:
    run_turtle_program(in_fname, out_fname, angle, background_color, plot_color)
except FileNotFoundError:
    print(f"File not found: {in_fname}")
    sys.exit(1)
except ValueError:
    print("Invalid angle. Please enter a number.")
    sys.exit(1)
