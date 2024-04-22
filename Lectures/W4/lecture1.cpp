#include <iostream>
#include <string>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    char myword[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char myword2[] = "Hello";

    char question1[] = "What is your name? ";
    string question2 = "Where do you live? ";
    char answer1 [80];
    string answer2;
    cout << question1;
    cin >> answer1;
    cout << question2;
    cin >> answer2;

    char myntcs[] = "some text";
    string mystring = myntcs;

    cout << mystring;
    cout << mystring.c_str() << endl;

    int a = 1000;
    int* foo = &a;
    cout << foo << endl;

    int * number;
    char * character;
    double * decimals;
    
    return 0;
}
