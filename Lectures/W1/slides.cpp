/*
My second program in C++
*/

#include <iostream>
#include <string>
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

const double pi = 3.14159;
const char newline = '\n';

int main() 
{   int a, b, result, c;
    string mystring;

    double r = 1.05;
    mystring = "This is a string";
    a = 5;
    b = 2;
    result = a + b;

    int i;
    float f = 3.14;
    i = (int) f;
    cout << i << endl;

    // If statement using ?
    c = (a > b) ? a : b;
    cout << c << endl;
    cout << mystring << endl;
    cout << "Hello World! \n";
    std::cout << "I'm a C++ program \n";

    std::cerr << "Trial";
    return 0;
}