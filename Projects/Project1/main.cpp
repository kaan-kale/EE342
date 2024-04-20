#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * @brief Struct to represent a matrix.
 * The matrix is represented as a 2D array of doubles, with the number of rows
 * and columns stored as integers.
 * The matrix data is stored as a double pointer, where each row is a pointer
 * to a double array.
 */
struct Matrix {
  double **data;
  int rows;
  int cols;
};

/**
 * @brief Struct to represent a vector.
 * The vector is represented as a 1D array of doubles, with the size of the
 * vector stored as an integer.
 */
struct Vector {
  double *data;
  int size;
};

/**
 * @brief Performs Gaussian elimination on a given matrix.
 *
 * This function modifies the input matrix to its row echelon form using
 * the Gaussian elimination algorithm. The input matrix is expected to be
 * a merged matrix, where the last column is the vector to be solved. But the
 * number of iterations is based on the number of rows in the matrix. So a
 * square matrix is also valid.
 *
 * @param mergedMatrix The matrix to perform Gaussian elimination on. This
 * matrix is modified in-place.
 *
 * @return void
 */
void gaussianElimination(Matrix &mergedMatrix);

/**
 * @brief Performs back substitution on a given square matrix and vector.
 *
 * @param matrix The square matrix A to perform back substitution on.
 * @param vector The vector b to perform back substitution on.
 *
 * @return Vector The result vector x.
 */
Vector backSubstitute(Matrix matrix, Vector vector);

/**
 * @brief Merges a matrix and a vector into a single matrix. This operation
 * is useful for Gaussian elimination and back substitution.
 *
 * @param matrix The matrix A to merge.
 * @param vector The vector b to merge.
 *
 * @return Matrix The merged matrix.
 */
Matrix mergeMatrixAndVector(const Matrix &matrix, const Vector &vector);

/**
 * @brief Extracts the last column of a matrix as a vector. Useful operation
 * after Gaussian elimination to get the vector to be solved.
 *
 * @param matrix The matrix to extract the last column from.
 * @param delete_last_column If true, the last column is deleted from the
 * matrix.
 *
 * @return Vector The last column of the matrix.
 */
Vector getLastColumnAsVector(Matrix &matrix, bool delete_last_column = true);

/**
 * @brief Checks if a matrix is a 2x2 matrix.
 *
 * @param matrix The matrix to check.
 *
 * @return bool True if the matrix is a 2x2 matrix, false otherwise.
 */
bool is2x2Matrix(Matrix matrix);

/**
 * @brief Checks if a matrix is valid.
 *
 * @param matrix The matrix to check.
 *
 * @return bool True if the matrix is valid, false otherwise.
 */
bool matrixIsValid(Matrix matrix);

/**
 * @brief Checks if a vector is valid.
 *
 * @param vector The vector to check.
 *
 * @return bool True if the vector is valid, false otherwise.
 */
bool vectorIsValid(Vector vector);

/**
 * @brief Finds the inverse of a 2x2 matrix.
 *
 * @param matrix The 2x2 matrix to find the inverse of.
 *
 * @return Matrix The inverse of the 2x2 matrix.
 */
Matrix inverse2x2Matrix(Matrix matrix);

/**
 * @brief Finds the infinity norm of a matrix.
 *
 * The infinity norm of a matrix is the maximum row sum of the matrix.
 *
 * @param matrix The matrix to find the infinity norm of.
 *
 * @return double The infinity norm of the matrix.
 */
double findInfNorm(Matrix matrix);

/**
 * @brief Finds the one norm of a matrix.
 *
 * The one norm of a matrix is the maximum column sum of the matrix.
 *
 * @param matrix The matrix to find the one norm of.
 *
 * @return double The one norm of the matrix.
 */
double findOneNorm(Matrix matrix);

/**
 * @brief Calculates and prints the condition numbers of a 2x2 matrix.
 *
 * The condition numbers are calculated using the one and infinity norms.
 *
 * @param matrixA The 2x2 matrix to calculate the condition numbers of.
 *
 * @return void
 */
void calculatePrintConditionNumbers(Matrix matrixA);

/**
 * @brief Reads a matrix from a file and returns it as a Matrix struct.
 * The file should contain the matrix data in row-major order.
 *
 * @param matrixFileName The name of the file containing the matrix data.
 *
 * @return Matrix The matrix read from the file.
 */
Matrix readMatrixFromFile(const std::string &matrixFileName);

/**
 * @brief Reads a vector from a file and returns it as a Vector struct.
 * The file should contain the vector data in a single column.
 *
 * @param filename The name of the file containing the vector data.
 *
 * @return Vector The vector read from the file.
 */
Vector readVectorFromFile(const std::string &filename);

/**
 * @brief Displays the matrix data to the console.
 *
 * @param matrix The matrix to display.
 *
 * @return void
 */
void displayMatrix(Matrix matrix);

/**
 * @brief Displays the vector data to the console.
 *
 * @param vector The vector to display.
 *
 * @return void
 */
void displayVector(Vector vector);

/**
 * @brief Deallocates the memory used by the matrix data. Since the memory of
 * the matrix data is dynamically allocated, it needs to be deallocated
 * manually. This function takes an array of pointers to Matrix structs and
 * deallocates the memory for each matrix.
 *
 * @param matrixPointers An array of pointers to Matrix structs.
 * @param size The size of a Matrix pointer.
 *
 * @return void
 */
void deallocateMatrixMemory(Matrix **matrixPointers, int size);

/**
 * @brief Deallocates the memory used by the vector data. Since the memory of
 * the vector data is dynamically allocated, it needs to be deallocated
 * manually. This function takes an array of pointers to Vector structs and
 * deallocates the memory for each vector.
 *
 * @param vectorPointers An array of pointers to Vector structs.
 * @param size The size of a Vector pointer.
 *
 * @return void
 */
void deallocateVectorMemory(Vector **vectorPointers, int size);


int main(int argc, char* argv[]) {
  string matrixFileName;
  string vectorFileName;

  // Define the matrix, vector, and true result
  Matrix matrixA;
  Matrix mergedMatrix;
  Vector vectorB;
  Vector vectorBPrime;
  Vector trueResult;
  Vector result;

  // Define the file names
  if(argc > 2) {
    matrixFileName = argv[1];
    vectorFileName = argv[2];
  } else {
    std::cerr << "Matrix and vector file names not provided." << std::endl;
    return 1;
  }

  // string matrixFileName = "./test-files/A11.txt";
  // string vectorFileName = "./test-files/b1.txt";
  string trueResultFileName = "./test-files/x1.txt";
  // Define the pointers to the matrixs and vectors, for deallocation
  Vector *vectorPointers[] = {&vectorB, &vectorBPrime, &trueResult, &result};
  Matrix *matrixPointers[] = {&matrixA, &mergedMatrix};

  int matrixPointerSize = sizeof(matrixPointers) / sizeof(matrixPointers[0]);
  int vectorPointerSize = sizeof(vectorPointers) / sizeof(vectorPointers[0]);

  // Read the matrix and vector from the files
  matrixA = readMatrixFromFile(matrixFileName);
  vectorB = readVectorFromFile(vectorFileName);
  trueResult = readVectorFromFile(trueResultFileName);

  // Check if the matrix and vector are valid, if not return an error
  // using the || or operator to check if either is invalid
  if (!matrixIsValid(matrixA) || !vectorIsValid(vectorB)) {
    std::cerr << "Matrix or vector is invalid." << std::endl;
    deallocateMatrixMemory(matrixPointers, matrixPointerSize);
    deallocateVectorMemory(vectorPointers, vectorPointerSize);
    return 1;
  }

  // Check if the matrix A is 2x2
  // If it is, calculate and print the condition numbers
  // using the one and infinity norms
  if (is2x2Matrix(matrixA)) {
    std::cout << "Matrix is 2x2" << std::endl;
    calculatePrintConditionNumbers(matrixA);
  } else {
    std::cout << "Matrix is not 2x2" << std::endl;
  }
  
  // Merge the matrix and vector for Gaussian elimination and ease of
  // computation
  mergedMatrix = mergeMatrixAndVector(matrixA, vectorB);

  // Perform Gaussian elimination
  gaussianElimination(mergedMatrix);

  // Get the last column as a vector, and delete the last column from the
  // matrix if the second argument is true
  vectorBPrime = getLastColumnAsVector(mergedMatrix, true);

  // Back substitute to find the result
  result = backSubstitute(mergedMatrix, vectorBPrime);

  // Display the calculated result
  std::cout << "Displaying the calculated results:" << endl;
  displayVector(result);

  // Display the true result
  std::cout << "Displaying the true result:" << endl;
  displayVector(trueResult);

  deallocateMatrixMemory(matrixPointers, matrixPointerSize);
  deallocateVectorMemory(vectorPointers, vectorPointerSize);
  return 0;
}

void gaussianElimination(Matrix &mergedMatrix)
// Gaussian elimination
{
  for (int currentRowIdx = 0; currentRowIdx < mergedMatrix.rows;
       ++currentRowIdx) {
    int maxIdx = currentRowIdx;
    double max = abs(mergedMatrix.data[currentRowIdx][currentRowIdx]);

    // Find the row with the maximum value in the current column
    for (int i = currentRowIdx + 1; i < mergedMatrix.rows; ++i) {
      double value = abs(mergedMatrix.data[i][currentRowIdx]);
      if (value > max) {
        max = value;
        maxIdx = i;
      }
    }

    // Swap rows
    double *temp = mergedMatrix.data[currentRowIdx];
    mergedMatrix.data[currentRowIdx] = mergedMatrix.data[maxIdx];
    mergedMatrix.data[maxIdx] = temp;

    // Zero out below pivot
    for (int i = currentRowIdx + 1; i < mergedMatrix.rows; ++i) {
      double cellRatio = mergedMatrix.data[i][currentRowIdx] /
                         mergedMatrix.data[currentRowIdx][currentRowIdx];
      for (int j = currentRowIdx; j < mergedMatrix.cols; ++j) {
        mergedMatrix.data[i][j] -=
            cellRatio * mergedMatrix.data[currentRowIdx][j];
      }
    }
  }
};

Vector backSubstitute(Matrix matrix, Vector vector) {
  // Allocate memory for the result vector
  double *resultData = new double[matrix.rows];

  // Implement the back substitution algorithm
  for (int i = matrix.rows - 1; i >= 0; --i) {
    double sum = 0;
    for (int j = i + 1; j < matrix.cols; ++j) {
      sum += matrix.data[i][j] * resultData[j];
    }
    resultData[i] = (vector.data[i] - sum) / matrix.data[i][i];
  }

  // Create a Vector struct and return it
  Vector result = {resultData, matrix.rows};
  return result;
}

Matrix mergeMatrixAndVector(const Matrix &matrix, const Vector &vector) {
  if (matrix.rows != vector.size) {
    std::cerr << "Matrix rows and vector size must be the same." << std::endl;
    return {nullptr, 0, 0};
  }

  // Allocate memory for the new matrix
  double **newData = new double *[matrix.rows];
  for (int i = 0; i < matrix.rows; ++i) {
    newData[i] = new double[matrix.cols + 1]; // One extra column for the vector
  }

  // Copy the original matrix data
  for (int i = 0; i < matrix.rows; ++i) {
    for (int j = 0; j < matrix.cols; ++j) {
      newData[i][j] = matrix.data[i][j];
    }
  }

  // Add the vector data as the last column
  for (int i = 0; i < vector.size; ++i) {
    newData[i][matrix.cols] = vector.data[i];
  }

  // Create a new Matrix struct and return it
  Matrix newMatrix = {newData, matrix.rows, matrix.cols + 1};
  return newMatrix;
}

Vector getLastColumnAsVector(Matrix &matrix, bool delete_last_column) {
  double *vectorData = new double[matrix.rows];

  // Get the last column from the matrix
  for (int i = 0; i < matrix.rows; ++i) {
    vectorData[i] = matrix.data[i][matrix.cols - 1];
  }

  // Create a Vector struct
  Vector vector = {vectorData, matrix.rows};

  // If delete_last_column is true, delete the last column from the matrix
  if (delete_last_column) {
    // Allocate memory for the new matrix
    double **newData = new double *[matrix.rows];
    for (int i = 0; i < matrix.rows; ++i) {
      newData[i] = new double[matrix.cols - 1];
    }

    // Copy the original matrix data, excluding the last column
    for (int i = 0; i < matrix.rows; ++i) {
      for (int j = 0; j < matrix.cols - 1; ++j) {
        newData[i][j] = matrix.data[i][j];
      }
    }

    // Deallocate the memory for the original matrix
    for (int i = 0; i < matrix.rows; ++i) {
      delete[] matrix.data[i];
    }
    delete[] matrix.data;

    // Update the matrix data and cols
    matrix.data = newData;
    matrix.cols -= 1;
  }

  return vector;
}

bool is2x2Matrix(Matrix matrix) { return matrix.rows == 2 && matrix.cols == 2; }

bool matrixIsValid(Matrix matrix) { return matrix.data != nullptr; }

bool vectorIsValid(Vector vector) { return vector.data != nullptr; }

Matrix inverse2x2Matrix(Matrix matrix) {
  double determinant = matrix.data[0][0] * matrix.data[1][1] -
                       matrix.data[0][1] * matrix.data[1][0];
  if (determinant == 0) {
    std::cerr << "Determinant is zero. Cannot find inverse." << std::endl;
    return {nullptr, 0, 0};
  }

  double **inverseData = new double *[2];
  for (int i = 0; i < 2; ++i) {
    inverseData[i] = new double[2];
  }

  inverseData[0][0] = matrix.data[1][1] / determinant;
  inverseData[0][1] = -matrix.data[0][1] / determinant;
  inverseData[1][0] = -matrix.data[1][0] / determinant;
  inverseData[1][1] = matrix.data[0][0] / determinant;

  Matrix inverseMatrix = {inverseData, 2, 2};
  return inverseMatrix;
}

double findInfNorm(Matrix matrix) {
  double max = 0;
  for (int i = 0; i < matrix.rows; ++i) {
    double sum = 0;
    for (int j = 0; j < matrix.cols; ++j) {
      sum += abs(matrix.data[i][j]);
    }
    if (sum > max) {
      max = sum;
    }
  }
  return max;
}

double findOneNorm(Matrix matrix) {
  double max = 0;
  for (int j = 0; j < matrix.cols; ++j) {
    double sum = 0;
    for (int i = 0; i < matrix.rows; ++i) {
      sum += abs(matrix.data[i][j]);
    }
    if (sum > max) {
      max = sum;
    }
  }
  return max;
}

void calculatePrintConditionNumbers(Matrix matrixA) {
  Matrix inverseMatrix = inverse2x2Matrix(matrixA);
  // Check if the inverse matrix is valid
  if (inverseMatrix.data != nullptr) {
    std::cout << "Inverse matrix:" << std::endl;
    displayMatrix(inverseMatrix);
  }
  // Calculate the infinity norm of the original and inverse matrices
  double infNormMatrixA = findInfNorm(matrixA);
  double infNormInverseMatrix = findInfNorm(inverseMatrix);
  std::cout << "Infinity norm of matrix A: " << infNormMatrixA << std::endl;
  std::cout << "Infinity norm of inverse matrix: " << infNormInverseMatrix
            << std::endl;

  // Calculate the one norm of the original and inverse matrices
  double oneNormMatrixA = findOneNorm(matrixA);
  double oneNormInverseMatrix = findOneNorm(inverseMatrix);
  std::cout << "One norm of matrix A: " << oneNormMatrixA << std::endl;
  std::cout << "One norm of inverse matrix: " << oneNormInverseMatrix
            << std::endl;

  // Calculate the one and inf condition numbers
  double conditionNumberOne = oneNormMatrixA * oneNormInverseMatrix;
  double conditionNumberInf = infNormMatrixA * infNormInverseMatrix;

  std::cout << "One condition number: " << conditionNumberOne << std::endl;
  std::cout << "Infinity condition number: " << conditionNumberInf << std::endl;

  // Deallocate the memory used by the inverse matrix
  for (int i = 0; i < 2; ++i) {
    delete[] inverseMatrix.data[i];
  }
}

Matrix readMatrixFromFile(const std::string &matrixFileName) {
  std::ifstream infile(matrixFileName);
  // Check if the file was opened successfully
  // if not create an error matrix with data = nullptr
  if (!infile) {
    std::cerr << "Failed to open the file." << std::endl;
    Matrix errorMatrix = {nullptr, 0, 0};
    return errorMatrix;
  }

  // Determine the dimensions of the matrix
  int rows = 0, cols = 0;
  std::string line;
  while (std::getline(infile, line)) {
    ++rows;
    std::istringstream iss(line);
    double value;
    while (iss >> value) {
      ++cols;
    }
  }
  cols /= rows;

  // Allocate memory for the matrix
  double **matrixData = new double *[rows];
  for (int i = 0; i < rows; ++i) {
    matrixData[i] = new double[cols];
  }

  // Reset file pointer to beginning of the file
  infile.clear();
  infile.seekg(0, std::ios::beg);

  // Read the matrix values
  // Loop over each row of the matrix
  for (int i = 0; i < rows; ++i) {
    // Read a line from the file
    std::getline(infile, line); 

    // Create a stream from the line, this allows us to extract values from the line
    std::istringstream iss(line);
    for (int j = 0; j < cols; ++j) {
      // Extract a value from the line and store it in the matrix at row i col j
      iss >> matrixData[i][j];
    }
  }

  // Create a Matrix struct and return it
  Matrix matrix = {matrixData, rows, cols};
  return matrix;
}

Vector readVectorFromFile(const std::string &filename) {
  std::ifstream infile(filename);
  if (!infile) {
    std::cerr << "Failed to open the file." << std::endl;
    return {nullptr, 0};
  }

  // Determine the size of the vector
  int vectorSize = 0;
  std::string line;
  while (std::getline(infile, line)) {
    ++vectorSize;
  }

  // Allocate memory for the vector
  double *vectorData = new double[vectorSize];

  // Reset file pointer to beginning of the file
  infile.clear();
  infile.seekg(0, std::ios::beg);

  // Read the vector values
  int index = 0;
  while (std::getline(infile, line)) {
    std::istringstream iss(line);
    double value;
    if (iss >> value) {
      vectorData[index++] = value;
    }
  }

  // Create a Vector struct and return it
  Vector vector = {vectorData, vectorSize};
  return vector;
}

void displayMatrix(Matrix matrix) {
  int numRows = matrix.rows;
  int numCols = matrix.cols;
  double **matrixData = matrix.data;
  // Display the dynamically allocated matrix
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      std::cout << matrixData[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void displayVector(Vector vector) {
  // Display the dynamically allocated vector
  for (int i = 0; i < vector.size; ++i) {
    std::cout << vector.data[i] << " ";
  }
  std::cout << std::endl;
}

void deallocateMatrixMemory(Matrix **matrixPointers, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < matrixPointers[i]->rows; ++j) {
      delete[] matrixPointers[i]->data[j];
    }
    delete[] matrixPointers[i]->data;
  }
}

void deallocateVectorMemory(Vector **vectorPointers, int size) {
  for (int i = 0; i < size; ++i) {
    delete[] vectorPointers[i]->data;
    vectorPointers[i]->data = nullptr;
  }
}
