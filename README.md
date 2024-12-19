# Matrix Multiplication

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Directory Structure](#directory-structure)
- [File Descriptions](#file-descriptions)
- [Usage](#usage)
  - [Setup](#setup)
  - [Running Tests](#running-tests)
- [Performance Benchmarking](#performance-benchmarking)
- [Contributing](#contributing)

---

## Overview
This repository provides a framework for matrix multiplication using different loop orders and evaluates their performance using custom test cases. The main goal is to compare the efficiency of different loop orders under varying conditions.

---

## Features
- **Multiple Variations**: Supports `ijk`, `ikj`, `jik`, `jki`, `kij`, and `kji` loop orders.
- **Performance Reporting**: Time taken for each variation is recorded and logged.
- **Unit testing**: Verifies the correctness of the matrix multiplication results against expected outputs.

---

## Directory Structure
```
.
├── driver.c
├── matmul.c
├── run_tests.sh
├── Results
│   └── time_report.csv
├── Unit_test         
│   ├── unit_1
│   │   ├── A.txt
│   │   ├── B.txt
│   │   └── C.txt
│   └── ...
└── .gitignore
```
---

## File Descriptions

- **.gitignore**: Specifies files and directories to be ignored by Git.
- **driver.c**: The main driver program for running matrix multiplication tests.
- **matmul.c**: Contains matrix multiplication implementations.
- **Results/**: Directory to store test results.
  - **time_report.csv**: CSV file containing the results of the tests.
- **run_tests.sh**: Shell script to compile the driver, run tests, and record results.
- **Unit_test/**: Directory containing test cases.
  - **unit_X/**: Subdirectories for each test case, where `X` is the unit number.
    - **A.txt**: Matrix A.
    - **B.txt**: Matrix B.
    - **C.txt**: Matrix C (result of A * B).

---

## Usage 

### Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/john-jehiel/matrix-multiplication.git
   cd matrix-multiplication
   ```
2. Install dependencies:
   - GCC (for compiling C programs)

### Running Tests
1. Compile the driver program:
   ```bash
   gcc -o driver driver.c
   ```
2. Execute the `run_tests.sh` script:
   ```bash
   bash run_tests.sh
   ```
3. View the results in `Results/time_report.csv`.

---

## Performance Benchmarking
The `run_tests.sh` script records performance metrics for each test case:
- **Test_No**: The test number.
- **Unit_Id**: The unit number.
- **Variation**: The variation of the matrix multiplication algorithm.
- **Status**: The status of the test (Passed or Failed).
- **Time_Taken(ms)**: The time taken to perform the matrix multiplication in milliseconds.

Results are saved in `Results/time_report.csv`.

---

## Contributing
Contributions are highly encouraged! Follow these steps to contribute:

1. **Fork the Repository**  
   Create a fork of this repository on GitHub.
2. **Create a New Branch**  
   Create a branch for your feature or bug fix:
   ```bash
   git checkout -b feature-branch-name
   ```
3. **Make Changes**  
   Implement your feature or fix and commit the changes:
   ```bash
   git commit -m "Describe your changes"
   ```
4. **Push Changes and Open a Pull Request**  
   Push your branch to your forked repository:
   ```bash
   git push origin feature-branch-name
   ```
   Open a pull request on the original repository with a clear description of your changes.