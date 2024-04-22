#include <iostream>

using namespace std;

// q: How to run a cpp program from terminal?
// a: g++ -o outputfile inputfile.cpp; ./outputfile

int main(int argc, char *argv[]) {
    std::cout << "There are " << argc << " arguments:\n";
    return 0;
}