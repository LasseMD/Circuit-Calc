# ElectroCalc

ElectroCalc is a C program designed for analyzing and calculating electrical circuits. It includes three dynamic libraries for various circuit calculations and a main program to test these libraries.

## Libraries

### libresistance.so

This library provides functions to calculate the total resistance for resistors connected in series or parallel.

- `float calc_resistance(int count, char conn, float *array);`
  - Calculates the total resistance based on the number of components, connection type (serial or parallel), and an array of component values.
  - Returns the resulting resistance.
  - Returns 0 if any resistor is zero in parallel connection.
  - Returns -1 for invalid arguments.

### libpower.so

This library offers functions to calculate the total power dissipation in a circuit with a voltage source connected in series with a resistor.

- `float calc_power_r(float volt, float resistance);`
  - Calculates power based on voltage and resistance.
  - Returns the power value.

- `float calc_power_i(float volt, float current);`
  - Calculates power based on voltage and current.
  - Returns the power value.

### libcomponent.so

This library includes a function to determine the nearest three resistors in the E12 series that can replace a given resistance value.

- `int count = e_resistance(float orig_resistance, float *res_array);`
  - Finds the closest three resistors in the E12 series to the specified resistance.
  - Fills an array with these resistor values.
  - Returns the number of resistors used (between 0 and 3).

## Usage

To compile the libraries and main program, use the provided Makefile:

- `make lib`: Build only the libraries.
- `make all`: Build both the program and libraries, placing the libraries in the `lib` directory.
- `make install`: Copy the program and libraries to appropriate directories (`/usr/bin/` and `/usr/lib/`) and link the program to the public libraries.
- `make clean`: Remove object and executable files.
