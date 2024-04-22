#include <iostream>

using namespace std;

void procedure (int arg[])
{
  cout << 0 << endl;
}

void printarray ( int arg[], int length)
{
  for  (int n=0; n<length; ++n)
  {
    cout << arg[n] << ' ';
  }
  cout << '\n';
}
int main() {
  int x[5];
  cout << *(x + 2) << endl;

  printarray(x, 5);
  // char century [24][60][60];

  return 0;
}