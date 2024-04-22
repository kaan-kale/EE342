#include <iostream>
# include <fstream>
# include <string>

using namespace std;

int main(int argc, char *argv[])
{   
    cout << "You have entered " << argc 
         << " arguments:" << endl; 
  

    if (argc != 4)
    {
        cout << "Expected number of arguments is 4!" << endl;
        return 1;
    }

    string matrixAFile;
    string vectorBFile;
    string outputFile;

    matrixAFile = argv[1];
    vectorBFile = argv[2];
    outputFile = argv[3];

    // cout << matrixAFile << endl;
    // cout << vectorBFile << endl;
    // cout << outputFile << endl;

    fstream readA (matrixAFile);
    string line;
    int numRowsA = 0;
    if (readA.is_open())
    {   
        cout << "Printing A" << endl;
        while ( getline (readA,line) )
        {
        cout << line << '\n';
        numRowsA++;
        }
        readA.close();
    }

    else cout << "Unable to open file"; 
    cout << "Number of rows in A: " << numRowsA << endl;


    fstream readB (vectorBFile);
    int numRowsB = 0;
    if (readB.is_open())
    {        
        cout << "Printing b" << endl;
        while ( getline (readB,line) )
        {
        cout << line << '\n';
        numRowsB++;
        }
        readB.close();
    }

    else cout << "Unable to open file";

    cout << "Number of rows in B: " << numRowsB << endl;
    
    ofstream writeOutput;
    writeOutput.open(outputFile);
    if (writeOutput.is_open())
    {        
        if (numRowsA != numRowsB)
        {   
            writeOutput << "Dimensions do not match.\n";
            cout << "The number of rows in A and B do not match" << endl;
            // cout << "The number of rows in A and B do not match" << endl;
        }

        else  {
            writeOutput << "Dimensions match.\n";
            cout << "The number of rows in A and B match" << endl;
            // cout << "The number of rows in A and B match" << endl;
        }
        writeOutput.close();
    }

    else cout << "Unable to open file";
    return 0;
}

