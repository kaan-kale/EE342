#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

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

void displayMatrix(double** matrix, int rows, int cols)
{    
    // Display the dynamically allocated matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

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

void multiplyVector(double* vector, double scalar, int length)
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

void copyMatrixRow(double** source, double* destination, int row, int length)
{
    for (int i = 0; i < length; ++i) {
        destination[i] = source[row][i];
    }
}

void copyMatrix(double** source, double** destination, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            destination[i][j] = source[i][j];
        }
    }
}

void backSubstitute(double** matrix, double* vector, double* result, int rows, int cols)
{   
    // Understand and implement the back substitution algorithm
    for (int i = rows - 1; i >= 0; --i)
    {
        double sum = 0;
        for (int j = i + 1; j < cols; ++j)
        {
            sum += matrix[i][j] * result[j];
        }
        result[i] = (vector[i] - sum) / matrix[i][i];
    }
}

int main() {
    string matrixFileName = "A.txt";
    string vectorFileName = "b.txt";
    
    // Make the above part a function
    // TODO: Read the vector from a file

    // Open the text file
    std::ifstream infile(matrixFileName);
    if (!infile) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    // Read the matrix dimensions
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
    double** matrixA = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrixA[i] = new double[cols];
    }

    // Reset file pointer to beginning of the file
    infile.clear();
    infile.seekg(0, std::ios::beg);

    // Read the matrix values
    for (int i = 0; i < rows; ++i) {
        std::getline(infile, line);
        std::istringstream iss(line);
        for (int j = 0; j < cols; ++j) {
            iss >> matrixA[i][j];
        }
    }

    displayMatrix(matrixA, rows, cols);


    double* vectorB = nullptr;
    int vectorBSize;

    readVectorFromFile(vectorFileName, vectorB, vectorBSize);

    displayVector(vectorB, vectorBSize);

    // Add vector B as a column to the matrix
    for (int i = 0; i < rows; ++i)
    {
        matrixA[i] = (double*)realloc(matrixA[i], (cols + 1) * sizeof(double));
        matrixA[i][cols] = vectorB[i];
    }

    displayMatrix(matrixA, rows, cols + 1);

    // Gaussian elimination
    for (int columnIdx = 0; columnIdx < cols; ++columnIdx)
    {       
        int maxIdx = 0; 
        double max = 0, value = 0;

        // Find the max
        for (int i = columnIdx; i < rows; ++i)
        {   
            // Check the value
            value = matrixA[i][columnIdx];
            if (value > max) 
            { 
                max = value;
                maxIdx = i;
            }
        }

        double* temp = matrixA[columnIdx];

        matrixA[columnIdx] = matrixA[maxIdx];
        matrixA[maxIdx] = temp;

        std::cout << "Displaying Matrix A:" << endl;
        displayMatrix(matrixA, rows, cols + 1);

        double cellRatio;
        for (int i = columnIdx + 1; i < rows; ++i)
        {   
            // Check the value
            value = matrixA[i][columnIdx];
            cellRatio = value / max;

            // Multiply the vector by a scalar
            double vectorToSubtract[cols + 1];
            copyMatrixRow(matrixA, vectorToSubtract, columnIdx, cols + 1);
            multiplyVector(vectorToSubtract, cellRatio, cols + 1);

            // Subtract vectors
            subtractVector(matrixA[i], vectorToSubtract, cols + 1);
        }  

        std::cout << "Displaying Matrix A:" << endl;
        displayMatrix(matrixA, rows, cols + 1);
    }


    // Back substitution
    double* result = new double[rows];

    // Get vector b from the last column of the matrix
    for (int i = 0; i < rows; ++i)
    {
        vectorB[i] = matrixA[i][cols];
    }

    std::cout << "Displaying Vector B:" << endl;
    displayVector(vectorB, rows);

    backSubstitute(matrixA, vectorB, result, rows, cols);
    
    std::cout << "Displaying Result:" << endl;
    displayVector(result, rows);

    // Deallocate memory which is important for dynamic allocation
    for (int i = 0; i < rows; ++i) {
        delete[] matrixA[i];
    }

    delete[] matrixA;
    delete [] vectorB;
    delete [] result;
    return 0;
}
