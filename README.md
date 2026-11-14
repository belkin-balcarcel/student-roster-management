# Student Roster Management System (C++)

A console-based student roster management application written in C++ using Object-Oriented Programming (OOP) principles and dynamic memory management.

## Features
  Data Parsing: Parses raw student record strings into structured `Student` objects.
  Roster Management: Dynamically allocates and manages an array of pointers (`classRosterArray`) to add, update, and remove student records.
  Data Validation: Validates student email formats and reports invalid entries.
  Analytics & Filtering: Calculates average days spent in courses per student and filters records by degree program (`SECURITY`, `NETWORK`, `SOFTWARE`).
  Memory Safety: Implements custom destructors to properly release dynamically allocated memory and prevent memory leaks.

## Technologies Used
Language: C++
Concepts: Object-Oriented Programming, Pointers, Dynamic Memory Allocation, Enumerated Types, String Parsing

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com

   ```
2. Compile the source files using any standard C++ compiler (such as `g++` or Visual Studio):
   ```bash
   g++ MyProject/*.cpp -o StudentRoster
   ```
3. Run the executable:
   ```bash
   ./StudentRoster
   ```
