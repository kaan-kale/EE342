#include <iostream>

using namespace std;

class Dummy {
public:
  static int n;
  Dummy() { n++; };
};

template <class T> class mypair {
  T values[2];

public:
  mypair(T first, T second) {
    values[0] = first;
    values[1] = second;
  };
  T getMax();
};

template <class T> T mypair<T>::getMax() {
  T retval;
  retval = values[0] > values[1] ? values[0] : values[1];
  return retval;
};

int main() {

  mypair<int> myobject(100, 75);
  cout << myobject.getMax() << endl;
  return 0;
};
