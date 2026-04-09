# C++ Secure Password Generator

A lightweight, command-line password generator written in modern C++. It creates highly customizable, cryptographically safe (hardware-seeded) random passwords.
## Features

* **Customizable Length:** Generate passwords of any specific length.
* **Granular Character Sets:** Choose exactly what types of characters to include:
  * `L` or `l`: Letters (A-Z, a-z)
  * `D` or `d`: Digits (0-9)
  * `S` or `s`: Symbols (`~`!@#$%^&*()_+=-{}[];:<>,.?/`)
* **Hardware Entropy Generation:** Uses `std::random_device` to pull true randomness from the operating system, avoiding the biases of legacy `rand()` functions.
* **Optional Seeded Generation:** Input a custom integer seed to generate the exact same password reliably across different runs.
* **Robust Error Handling:** Survives bad user input, empty character sets, and gracefully falls back to true randomness if a bad seed format is entered.

## Prerequisites

To compile this program, you need a C++ compiler that supports at least the C++11 standard (which includes the modern `<random>` library). 
If you are on an Arch-based system like EndeavourOS, ensure you have the basic build tools installed:
```bash
sudo pacman -S base-devel

##Compilation
g++ -O2 main.cpp -o passgen

##Run the program
./passgen

Example output :
Enter password length : 15
Enter the character sets you want to use (LDS) : lds
Enter randomizer seed (press Enter to skip) : 123
Password : ~!ZmU~x!!sm&?k0
