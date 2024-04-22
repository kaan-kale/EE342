#include <iostream>
#include <string>

using namespace std;

int addition ( int a, int b)
{
    int r;
    r = a + b;
    return r;
}

void printmessage ()
{
    cout << "I'm  a function!";
}

void printmessage2 (void)
{
    cout << "2";
}

void duplicate ( int& a, int& b, int& c)
{
    a *= 2;
    b *= 2;
    c *= 2;
}

int main() 
{
    // Initialize x
    int x = 100;
    if (x == 100)
    {
        cout << "x is 100" << endl;
        cout << x << endl;
    }

    int n = 10;
    while (n>0)
    {
        cout << n << ", ";
        --n;
    }

    string str;
    do 
    {
        cout << "\nEnter text: ";
        getline (cin, str);
        cout << "You entered: " << str << '\n';
    }   while (str != "goodbye");

    for (int n=10; n>0; n--)
    {
        cout << n << ", ";
    }

    // string str2 {"Hello!"};

    for (char c : str)
    {
        cout << c;
    }

    switch (n)
    {
        case 0:
            cout << "0000" << endl;
            break;
        case 1:
            cout << "11111" << endl;
            break;

        default:
            cout << "22222" << endl;
            break;
    }
    int a = 2, b = 3, c = 4;
    duplicate(a, b, c);
    cout << a << b << c << endl;

    int z;
    cout << z << endl;
    return 0;
}