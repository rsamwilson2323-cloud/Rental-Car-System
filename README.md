# 🚗 Rental Car System (C++)

A simple **console-based Rental Car System developed in C++**.  
This project simulates a small car rental shop where users can view available cars and rent a car through a menu-driven interface.

The program is designed to demonstrate **basic C++ concepts such as structures, vectors, functions, and menu-based programming**.

------------------------------------------------------------

## 📌 Project Overview

The Rental Car System allows users to:

• View available cars for rent  
• Select a car using its ID  
• Rent the car for a specific number of days  
• Automatically calculate the total rental cost  

Once a car is rented, it becomes unavailable until the program is restarted.

------------------------------------------------------------

## ✨ Features

### 1️⃣ View Available Cars
Displays all cars that are currently available for rent.

Information shown:
- Car ID
- Car Model
- Price per Day

Example:

Car ID    Car Model           Price per Day ($)
101       Toyota Corolla      45.50
102       Honda Civic         48.00
103       Ford Mustang        85.00
104       Tesla Model 3       95.00
105       Chevrolet Malibu    55.25

------------------------------------------------------------

### 2️⃣ Rent a Car

Users can rent a car by entering the **Car ID**.

The system will ask:

• Number of days for rental  
• Calculate the total cost  
• Display a rental confirmation

Example:

Car Model   : Toyota Corolla  
Days Rented : 3  
Daily Rate  : $45.50  
Total Cost  : $136.50  

------------------------------------------------------------

### 3️⃣ Availability Tracking

Once a car is rented:

• The system marks the car as **not available**  
• It will no longer appear in the available car list

------------------------------------------------------------

## 📂 Repository File Structure

Rental-Car-System
│
├── LICENSE
├── README.md
├── Rental Car System.cpp
└── Rental Car System.exe

------------------------------------------------------------

## 📄 File Description

**Rental Car System.cpp**

The main C++ source code containing:

• Car structure definition  
• Display available cars function  
• Rent car function  
• Menu-driven main program  

---

**Rental Car System.exe**

Compiled executable file for Windows.  
You can run the program directly without compiling.

---

**LICENSE**

Defines the legal terms for using or modifying this project.

---

**README.md**

Project documentation and explanation.

------------------------------------------------------------

## ⚙️ Technologies Used

Programming Language:
C++

Libraries Used:

iostream  
vector  
string  
iomanip  

------------------------------------------------------------

## 🧠 Concepts Used

• Structures in C++  
• Vectors (Dynamic Arrays)  
• Functions  
• Menu Driven Programming  
• Input / Output Formatting  

------------------------------------------------------------

## 🖥️ How To Run

### Method 1: Run the Executable

Simply run:

Rental Car System.exe

---

### Method 2: Compile the Source Code

Using **g++**

g++ "Rental Car System.cpp" -o rental

Run the program

./rental

or on Windows

rental.exe

------------------------------------------------------------

## 📊 Example Program Output

Welcome to the C++ Auto Rental System!

MAIN MENU

1. View Available Cars  
2. Rent a Car  
3. Exit  

Enter your choice: 1

AVAILABLE CARS FOR RENT

Car ID    Car Model           Price per Day ($)
101       Toyota Corolla      45.50
102       Honda Civic         48.00
103       Ford Mustang        85.00
104       Tesla Model 3       95.00
105       Chevrolet Malibu    55.25

------------------------------------------------------------

## 🚀 Future Improvements

Possible upgrades for this project:

• Add car return system  
• Store data using files  
• Customer management  
• Rental history tracking  
• GUI interface using Qt or C++ frameworks  
• Database integration

------------------------------------------------------------

## 👨‍💻 Author

Sam Wilson R  
B.E Computer Science Engineering (AI / ML)  
Christ The King Engineering College  

Academic Year  
2025 – 2029

GitHub  
https://github.com/rsamwilson2323-cloud

------------------------------------------------------------

⭐ If you like this project, consider giving it a **star on GitHub**!
