#include <iostream>

template <class T> class Vector3D {
  T x, y, z;
public:
  Vector3D() : x(0), y(0), z(0){};
  Vector3D(T x, T y, T z) : x(x), y(y), z(z){};
  void print();
  Vector3D operator+(const Vector3D &vec2) {
    return Vector3D(x + vec2.x, y + vec2.y, z + vec2.z);
  }
};

template <class T> void Vector3D<T>::print() {
  std::cout << x << " " << y << " " << z << std::endl;
};

int main() {
  Vector3D<double> v1(1.1, 2.2, 3.3);
  v1.print();

  Vector3D<double> v2(1.2, 2.2, 3.3);
  v2.print();

  Vector3D<double> v3 = v1 + v2;
  v3.print();
  return 0;
}