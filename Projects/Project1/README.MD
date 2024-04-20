# Project Title
This project is a C++ application that performs Gaussian elimination on a given matrix and vector. It reads the matrix and vector from files, validates them, and then performs the necessary computations.

## Functionality
The application performs the following steps:

1. **Read Matrix and Vector from Files:** The application reads a matrix and a vector from files using the `readVectorFromFile` function. The file names are provided as command-line arguments.

2. **Validation:** The application checks if the matrix and vector are valid using the `matrixIsValid` and `vectorIsValid` functions. If either the matrix or vector is invalid, the application prints an error message and exits.

3. **Condition Numbers for 2x2 Matrices:** If the matrix is a 2x2 matrix, the application calculates and prints the condition numbers using the one and infinity norms. This is done using the `calculatePrintConditionNumbers` function.

4. **Merge Matrix and Vector:** The application merges the matrix and vector into a single matrix for ease of computation during the Gaussian elimination process. This is done using the `mergeMatrixAndVector` function.

5. **Gaussian Elimination:** The application performs Gaussian elimination on the merged matrix using the `gaussianElimination` function.

6. **Back Substitution:** The application performs back substitution to find the result. It first gets the last column of the matrix as a vector and removes it from the matrix using the `getLastColumnAsVector` function. It then performs back substitution using the `backSubstitute` function.

## How to Run
To run the application, you need to compile the C++ code and then run the resulting executable. You can do this from the terminal as follows:

1. Change the A and b path according to your own matrix and vector files from the run.sh file
```bash
# Compile the cpp file
g++ -std=c++11 -o main main.cpp

APath="test-files/A1.txt"
bPath="test-files/b1.txt"

# Run the compiled file
./main $APath $bPath
```

2. Run the script
```bash
bash run.sh
```