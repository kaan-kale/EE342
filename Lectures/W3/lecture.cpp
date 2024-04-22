#include <iostream>

using namespace std;

int sum(int a, int b) { return a + b; }

int sum(double a, double b) { return a + b; }

template <class SomeType> SomeType sum(SomeType a, SomeType b) { return a + b; }

template <class T, class U> bool are_equal(T a, U b) { return (a == b); }

template <class T, int N> T fixed_multiply(T val) { return val * N; }

int foo;

int some_function() {
  int bar;
  bar = 0;
  return bar;
}

int other_function() {
  foo = 1;
  int bar = 2;
  return bar;
}

namespace myNameSpace {
int a, b;
}

namespace fooNameSpace {
int value() { return 5; }
} // namespace fooNameSpace

namespace bar {
const double pi = 3.1416;
double value() { return 2 * pi; }
} // namespace bar

namespace first {
int x = 5;
int y = 10;
} // namespace first

namespace second {
double x = 3.1416;
double y = 2.7183;
} // namespace second

int main() {
  //   using first::x;
  //   using second::y;

  std::cout << "Hello, World!" << std::endl;
  // int x = sum<int>(10, 20);

  cout << first::y << endl;
  cout << first::x << endl;
  cout << second::x << endl;
  cout << are_equal(10, 10.0) << endl;

  cout << fixed_multiply<int, 2>(9) << endl;

  {
    using namespace first;
    cout << "First" << endl;
    cout << x << '\n';
  }

  {
    using namespace second;
    cout << "Second" << endl;
    cout << x << '\n';
  }
  return 0;
}
