#include <iostream>

using namespace std;

template <class SomeType> SomeType findMax(SomeType a, SomeType b) {
  if (a > b) {
    return a;
  } else
    return b;
}

template <class SomeType> SomeType findMax(SomeType arr[], int length) {
  SomeType x = arr[0];
  for (int n = 1; n < length; ++n) {
    x = findMax(x, arr[n]);
  }
  return x;
}

int main() {

  int a[5] = {1, 2, 3, 4, 0};
  int intMax;

  double b[8] = {1.5, 2.6, 3.7, 2.1, 0.3, 9.5, 2.5, 7.4};
  double doubleMax;

  intMax = findMax<int>(a, 5);
  cout << intMax << endl;

  doubleMax = findMax<double>(b, 8);
  cout << doubleMax << endl;

  cout << findMax<int>(10, 8) << endl;
  cout << findMax<float>(10.8, 20.3);
  return 0;
}