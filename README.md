# cCourseAllocation
A C-based course allocation system for a Computer Science department. Reads and processes course and professor data from files. Features include retrieving course info, identifying professors for courses, and calculating statistics. Emphasizes file handling, command-line arguments, and modular design.

## Features

- **File Handling**: Read course names, IDs, and professor assignments from external files.
- **Course & Professor Management**: Retrieve course names based on IDs, identify professors teaching specific courses, and calculate the average number of courses taught by professors.
- **Command-Line Interface**: Interact with the program through a user-friendly command-line interface.
- **Error Handling**: Robust error handling to manage file reading and data processing errors.
- **Modular Design**: The program is divided into functions for better code organization and reusability.

## Requirements

- **C Compiler**: Ensure you have a C compiler like GCC installed.
- **Makefile**: Use the provided Makefile to compile and run the program.

## Files Included

- **cCourseAllocation.c**: Contains the main function implementations.
- **cCourseAllocationMain.c**: The main driver program to test and run the functions.
- **header.h**: Header file with function prototypes, constants, and structure definitions.
- **makefile**: Script to compile the program using `gcc`.

## How to Compile and Run

1. Clone the repository.
2. Navigate to the project directory.
3. Run `make` to compile the program using the provided Makefile.
4. Execute the program using `./cCourseAllocation`.

### Example Usage

```bash
./cCourseAllocation courses.txt data.txt
