#include <iostream>

using namespace std;

void increment_all (int* start, int* stop)
{
  int * current = start;
  while (current != stop) {
    ++(*current);  // increment value pointed
    ++current;     // increment pointer
  }
}

void print_all (const int* start, const int* stop)
{
  const int * current = start;
  while (current != stop) {
    cout << *current << '\n';
    ++current;     // increment pointer
  }
}

int main()
{
    int firstvalue, secondvalue;
    int* mypointer;

    mypointer = &firstvalue;
    *mypointer = 10;

    mypointer = &secondvalue;
    *mypointer = 20;

    cout << "First value is " << firstvalue << endl;
    cout << "Second value is " << secondvalue << endl; 

    int myarray [20];
    int * mypointer2;

    // This would be valid.
    mypointer2 = myarray;

    // This would not be valid
    // myarray = mypointer2
    int numbers[] = {10,20,30};
    increment_all (numbers,numbers+3);
    print_all (numbers,numbers+3);

    char a;
    char *b;

    char **c;
    a = 'z';
    b = &a;
    c = &b;

    return 0;
}

