
# MINI AIMS PORTAL
This project aims at cloning some features of IITH's Academic management website.











## Authors

- [@anudeep512](https://www.github.com/anudeep512)


## Tech Stack

**Command Line:** C++
## Prerequisite

Check if a suitable compiler exists for compiling the C++ code

for g++ compiler:

    g++ --version

for clang compiler:

    clang --version

If there isn't any compiler installed, install it using the documentation for the compiler of C++ based on your OS.

Check if CMake exists:

    cmake --version
If there isn't any version of CMake installed on your machine install CMake:

for MacOS:

    brew install cmake 

for Ubuntu:

    sudo apt-get install cmake

## Install and Usage

### Installing project

Clone from repo:

    git clone https://github.com/anudeep512/Mini-Aims-Portal

### Running the Program

After cloning is done redirect control to project folder using:

    cd ./Mini-Aims-Portal

To generate the compilation files run:
    
    cmake .

To actually compile the application, you must use GNU make with the make command:

    make

Launch the application with:

    ./Mini-Aims-Portal


## Features
- Roles available: 
  - Admin 
  - Student
  - Faculty

### Admin Mode
- Add and Delete courses offered by the institute.
- Adding and Removing students from the institute.
- See the list of students registered for a course.

### Teacher Mode
- See the list of students registered for the course.
- Submitting grades for the course.

### Student Mode
- Register and Deregister from a course.
- See the courses registered.
- Checking grades for the courses registered.
