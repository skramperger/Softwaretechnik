# Softwaretechnik

## Overview

This repository contains all the programs written for school, starting from the 3rd semester at HTL Bulme Graz-Gösting. The repository aims to represent the ongoing learning path for C programming throughout the entire learning period.

## Repository Structure

The repository is organized into several folders and files, each representing different semesters and topics:

### 3ABELI

This folder contains a variety of C and C++ programs created during the 3rd semester. The programs cover fundamental concepts of programming, such as control structures, functions, arrays, and sensor interfacing with hardware components like LEDs and ultrasonic sensors.

- **Labor**
  - `led_control.cpp`: Controls an LED.
  - `led_running_light.cpp`: Implements a running light using LEDs.
  - `led_running_light_millis.cpp`: Controls a running light using the `millis` function for timing.
  - `ultraschall_sensor.cpp`: Interfaces with an ultrasonic sensor to read distance measurements.

- **Exercises**
  - `02und03Übungen.c`: Basic programming exercises covering control structures.
  - `04ÜbungenSchleifen.c`: Exercises focusing on loops.
  - `05ÜbungenSchleifen&Felder.c`: Exercises on loops and arrays.
  - `06ÜbungenFunktionen.c`: Exercises related to functions.
  - `07ÜbungenFunktionen2.c`: Additional exercises on functions.
  - `08ÜbungenFelderFunktionen.c`: Exercises combining arrays and functions.

- **Test and Practice Programs**
  - `1. Test.c`: Initial test program.
  - `2. Test.c`: Another test program with different logic.
  - `Felder.c`: Demonstrates array usage.
  - `Funktionen mit Präprozessoren.c`: Utilizes preprocessor directives with functions.
  - `Quersumme.c`: Calculates the cross sum of a number.
  - `Rekursion.c`: Demonstrates recursion.
  - `pointer.c`: Explores pointer usage.
  - `strings.c`: Handles string operations.

### 4ABELI

This folder contains various C++ programs created during the 4th semester. These programs focus on advanced topics such as digital port manipulation, analog-to-digital conversion, pin change interrupts, and file editing.

- **Exercises**
  - `02Übungen Digitaler Port mit P...cpp`: Exercises on digital port manipulation with preprocessor directives.
  - `02Übungen Digitaler Port.cpp`: Exercises on digital port manipulation.
  - `09ÜbungenADWandler.cpp`: Exercises on analog-to-digital conversion.
  - `10Übungen PinChangeInterrup...cpp`: Exercises on handling pin change interrupts.

- **Test Programs**
  - `1. Test.cpp`: Initial test program focusing on digital port manipulation and other topics.
  - `2. Test.cpp`: Another test program with different focus areas.

- **Project and Utility Programs**
  - `PortManipulation.cpp`: Program demonstrating various techniques for port manipulation.
  - `file_editing.cpp`: Program for editing files, demonstrating file handling techniques in C++.
  - `interupts.cpp`: Program dealing with interrupts, showcasing the implementation and handling of interrupt service routines.

### 5ABELI

This folder contains various C++ programs and projects developed during the 5th semester. The focus during this semester includes advanced embedded systems programming with ARM architecture, interrupt handling, and RGB light control.

- **Test and Preparation Programs**
  - `2. Test FSST rework.cpp`: Reworked test program for FSST (Fachschule für Softwaretechnik).
  - `Test_Vorbereitung(5ACELI-Test).cpp`: Preparation program for the 5ACELI test.

- **Embedded Systems and Control Programs**
  - `Introduction_mbed.cpp`: An introductory program for the mbed platform, demonstrating basic functionalities.
  - `LED interrupt control.cpp`: Program to control an LED using interrupts.
  - `Ultraschall-Sensor-ARM.cpp`: Program interfacing with an ultrasonic sensor using ARM architecture.
  - `rgb_light_control.cpp`: Program for controlling RGB lights, demonstrating color mixing and control techniques.

- **Utility Programs**
  - `pointer_revision.cpp`: A program revising pointer concepts and their applications.

### 6ABELI

This folder contains various projects and programs developed during the 6th semester. The focus during this semester includes web-based games and practice projects for tests.

- **canvas_snake**: A project folder containing the implementation of the classic Snake game using HTML5 Canvas.
- **completed-practice-for-1st-test**: A project folder with completed practice exercises for the first test.
- **ping_pong.html**: An HTML file implementing a simple Ping Pong game.

These projects demonstrate proficiency in web development and interactive programming, combining both visual elements and logic to create engaging applications.

## Getting Started

To use the programs in this repository, follow these steps:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/repositoryname.git
   cd repositoryname

2. **Compile the programs**:
Use a C/C++ compiler like gcc for C files or g++ for C++ files. For example:
   ```bash
   gcc 1.Test.c -o test
   ./test
   ```

### Usage
Each program in the repository serves a different educational purpose. Refer to the comments within the code for specific usage instructions and details about what each program does.

### Example
To run the LED running light program:
   ```bash
   cd 3ABELI/Labor
   g++ led_running_light_millis.cpp -o led_running_light
   ./led_running_light
   ```

### Contributing
Contributions are welcome! To contribute:

  1. Fork the repository.
  2. Create a new branch (git checkout -b feature-branch).
  3. Commit your changes (git commit -am 'Add new feature').
  4. Push to the branch (git push origin feature-branch).
  5. Create a new Pull Request.

## License
This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.


### Acknowledgments
- Thanks to HTL Bulme Graz-Gösting for the educational support.
- Special thanks to all contributors and fellow students.


