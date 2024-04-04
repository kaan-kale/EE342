#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Matrix Struct
struct Matrix {
    double** data;
    int rows;
    int cols;
};

struct Vector {
    double* data;
    int size;
};

void readVectorFromFile(const std::string& filename, double*& vector, int& size);

void displayMatrix(Matrix matrix);

void displayVector(double* vector, int length);

void subtractVectors(double* a, double* b, double* result, int length);

void subtractVector(double* x, double* y, int length);

void elementwiseMultiplyVector(double* vector, double scalar, int length);

void copyVector(double* source, double* destination, int length);

void swapVectors(double* a, double* b, int length);

void copyMatrixRow(Matrix matrix, double* destination, int rowIdx);

void copyMatrix(Matrix source, Matrix destination, int numRows, int numCols);

void backSubstitute(Matrix matrix, double* vector, double* result);

Matrix readMatrixFromFile(const std::string& matrixFileName);

int main() {
    string matrixFileName = "./Project1 test files-20240404/A1.txt";    
    string vectorFileName = "./Project1 test files-20240404/b.txt";
    string trueResultFileName = "./Project1 test files-20240404/x1.txt";

    Matrix matrixA;

    double* vectorB = nullptr;
    int vectorBSize;
    
    double* trueResult = nullptr;
    int trueResultSize;

    matrixA = readMatrixFromFile(matrixFileName);
    readVectorFromFile(vectorFileName, vectorB, vectorBSize);
    readVectorFromFile(trueResultFileName, trueResult, trueResultSize);

    displayMatrix(matrixA);
    displayVector(vectorB, vectorBSize);

    // Add vector B as a column to the matrix
    for (int i = 0; i < matrixA.rows; ++i)
    {
        matrixA.data[i] = (double*)realloc(matrixA.data[i], (matrixA.cols + 1) * sizeof(double));
        matrixA.data[i][matrixA.cols] = vectorB[i];
    }

    displayMatrix(matrixA);

    // Gaussian elimination
    for (int columnIdx = 0; columnIdx < matrixA.cols; ++columnIdx)
    {       
        int maxIdx = 0; 
        double max = 0, value = 0;

        // Find the max
        for (int i = columnIdx; i < matrixA.rows; ++i)
        {   
            // Check the value
            value = matrixA.data[i][columnIdx];
            if (value > max) 
            { 
                max = value;
                maxIdx = i;
            }
        }

        double* temp = matrixA.data[columnIdx];

        matrixA.data[columnIdx] = matrixA.data[maxIdx];
        matrixA.data[maxIdx] = temp;

        std::cout << "Displaying Matrix A:" << endl;
        displayMatrix(matrixA);

        double cellRatio;
        for (int i = columnIdx + 1; i < matrixA.rows; ++i)
        {   
            // Check the value
            value = matrixA.data[i][columnIdx];
            cellRatio = value / max;

            // Multiply the vector by a scalar
            double vectorToSubtract[matrixA.cols + 1];
            copyMatrixRow(matrixA, vectorToSubtract, columnIdx);
            elementwiseMultiplyVector(vectorToSubtract, cellRatio, matrixA.cols + 1);

            // Subtract vectors
            subtractVector(matrixA.data[i], vectorToSubtract, matrixA.cols + 1);
        }  

        std::cout << "Displaying Matrix A:" << endl;
        displayMatrix(matrixA);
    }


    // Back substitution
    double* result = new double[matrixA.rows];

    // Get vector b from the last column of the matrix
    for (int i = 0; i < matrixA.rows; ++i)
    {
        vectorB[i] = matrixA.data[i][matrixA.cols];
    }

    std::cout << "Displaying Vector B:" << endl;
    displayVector(vectorB, matrixA.rows);

    backSubstitute(matrixA, vectorB, result);
    
    std::cout << "Displaying Result:" << endl;
    displayVector(result, matrixA.rows);

    std::cout << "Displaying the true result:" << endl;
    displayVector(trueResult, trueResultSize);

    // Deallocate memory which is important for dynamic allocation
    for (int i = 0; i < matrixA.rows; ++i) {
        delete[] matrixA.data[i];
    }

    delete[] matrixA.data;
    delete [] vectorB;
    delete [] result;
    return 0;
}

// Function to read a vector of doubles from a text file
void readVectorFromFile(const std::string& filename, double*& vector, int& size) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Failed to open the file." << std::endl;
        size = 0;
        return;
    }

    // Determine the size of the vector
    int vectorSize = 0;
    std::string line;
    while (std::getline(infile, line)) {
        ++vectorSize;
    }

    // Allocate memory for the vector
    vector = new double[vectorSize];

    // Reset file pointer to beginning of the file
    infile.clear();
    infile.seekg(0, std::ios::beg);

    // Read the vector values
    int index = 0;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        double value;
        if (iss >> value) {
            vector[index++] = value;
        }
    }

    // Set the size
    size = vectorSize;
}

void displayMatrix(Matrix matrix)
{   
    int numRows = matrix.rows;
    int numCols = matrix.cols;
    double** matrixData = matrix.data;
    // Display the dynamically allocated matrix
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << matrixData[i][j] << " ";
        }
        std::cout << std::endl;
    }}

void displayVector(double* vector, int length)
{
    // Display the dynamically allocated vector
    for (int i = 0; i < length; ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

void subtractVectors(double* a, double* b, double* result, int length)
{
    for (int i = 0; i < length; ++i) {
        result[i] = a[i] - b[i];
    }
} 

void subtractVector(double* x, double* y, int length)
{
    for (int i = 0; i < length; ++i) {
        x[i] -= y[i];
    }
}

void elementwiseMultiplyVector(double* vector, double scalar, int length)
{
    // Multiply the vector by a scalar
    for (int i = 0; i < length; ++i) {
        vector[i] *= scalar;
    }
}

void copyVector(double* source, double* destination, int length)
{
    for (int i = 0; i < length; ++i) {
        destination[i] = source[i];
    }
}

void swapVectors(double* a, double* b, int length)
{
    double* temp = new double[length];
    copyVector(a, temp, length);
    copyVector(b, a, length);
    copyVector(temp, b, length);
    delete[] temp;
}

void copyMatrixRow(Matrix matrix, double* destination, int rowIdx)
{   
    for (int i = 0; i < matrix.cols; ++i) {
        destination[i] = matrix.data[rowIdx][i];
    }
}

void copyMatrix(Matrix source, Matrix destination, int numRows, int numCols)
{   
    // Use copyMatrixRow to copy all rows
    for (int i = 0; i < numRows; ++i) {
        copyMatrixRow(source, destination.data[i], i);
    }
}

void backSubstitute(Matrix matrix, double* vector, double* result)
{   
    // Understand and implement the back substitution algorithm
    for (int i = matrix.rows - 1; i >= 0; --i)
    {
        double sum = 0;
        for (int j = i + 1; j < matrix.cols; ++j)
        {
            sum += matrix.data[i][j] * result[j];
        }
        result[i] = (vector[i] - sum) / matrix.data[i][i];
    }
}

Matrix readMatrixFromFile(const std::string& matrixFileName) {
    std::ifstream infile(matrixFileName);
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
    double** matrixData = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrixData[i] = new double[cols];
    }

    // Reset file pointer to beginning of the file
    infile.clear();
    infile.seekg(0, std::ios::beg);

    // Read the matrix values
    for (int i = 0; i < rows; ++i) {
        std::getline(infile, line);
        std::istringstream iss(line);
        for (int j = 0; j < cols; ++j) {
            iss >> matrixData[i][j];
        }
    }

    // Create a Matrix struct and return it
    Matrix matrix = {matrixData, rows, cols};
    return matrix;
}
