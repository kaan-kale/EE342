# Project 1
[GitHub Repository](https://github.com/kaan-kale/EE342/tree/main/Projects/Project1)

This project is a C++ application that performs Gaussian elimination with partial pivoting on a given matrix A and vector b. It reads the matrix and vector from files, validates them, and then performs the necessary computations.

## Functionality
The application performs the following steps:

1. **Read Matrix and Vector from Files:** The application reads a matrix and a vector from files using the `readVectorFromFile` function. The file names are provided as command-line arguments.

2. **Validation:** The application checks if the matrix and vector are valid using the `matrixIsValid` and `vectorIsValid` functions. If either the matrix or vector is invalid, the application prints an error message and exits.

3. **Condition Numbers for 2x2 Matrices:** If the matrix is a 2x2 matrix, the application calculates and prints the condition numbers using the one and infinity norms. This is done using the `calculatePrintConditionNumbers` function.

4. **Merge Matrix and Vector:** The application merges the matrix and vector into a single matrix for ease of computation during the Gaussian elimination process. This is done using the `mergeMatrixAndVector` function.

5. **Gaussian Elimination:** The application performs Gaussian elimination on the merged matrix using the `gaussianElimination` function.

6. **Back Substitution:** The application performs back substitution to find the result. It first gets the last column of the matrix as a vector and removes it from the matrix using the `getLastColumnAsVector` function. It then performs back substitution using the `backSubstitute` function.

6. The program returns:
   - **1** if the file names for the Matrix A or the vector b are not provided.
   - **2** if either the matrix A or the vector B is invalid.
   - **3** if the matrix A is singular.
   - **0** if all operations are completed without any errors.

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

2. Or run the script provided
```bash
bash run.sh
```

## High Condition Numbers: Brief Analysis

The numerical experiments with the given 2x2 matrix A showcase the implications of high condition numbers, which are indicators of sensitivity in a system of linear equations. With condition numbers of 1 and infinity reaching 4004, the matrix is near singular, and small changes in the vector b lead to substantial changes in the solution x.

### Results Overview:

## Matrix A

The matrix A used in the test cases is as follows:

```plaintext
1.000 1.000 
1.000 1.001
```

**Test Case 11:**

Solution: `[2, 0]` for vector `b1`

**Test Case 12:**

Solution: `[1, 1]` for vector `b2`

### Inference:

The high condition number implies that A is nearly singular. Therefore, the solutions to `Ax = b` are significantly influenced by slight perturbations in `b`. The results demonstrate the practical effects of this sensitivity: while the difference between `b1` and `b2` is minuscule (only 0.001 in one component), the solutions differ by a whole integer. This exemplifies the care required when dealing with such systems and emphasizes the importance of precision in computational methods.