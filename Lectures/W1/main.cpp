#include <iostream>

#define PI 3.14159

using namespace std;

int main()
{   
    const float pi = 3.14159;
    float r;

    cout << "Please enter the radius: ";
    cin >> r;

    // Take input as stringstream
    float area = pi * r * r;
    cout << "Area: "; 
    cout << area << endl;

    return 0;
}