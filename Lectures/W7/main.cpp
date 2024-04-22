#include <iostream>

using namespace std;

class Coordinate {
  float x, y, z;

public:
  void set_values(float, float, float);
  float get_x() { return x; }
  float get_y() { return y; }
  float get_z() { return z; }
  float calculateLength();
} coord;

void Coordinate::set_values(float a, float b, float c) {
  x = a;
  y = b;
  z = c;
}

float Coordinate::calculateLength() { return sqrt(x * x + y * y + z * z); }

class Vec3d {
  Coordinate point;

public:
  Vec3d();
  Vec3d(float, float, float);
  void set_values(float, float, float);
  void unit_vec();
};

Vec3d::Vec3d() { point.set_values(0, 0, 0); }

Vec3d::Vec3d(float x, float y, float z) { point.set_values(x, y, z); }

void Vec3d::set_values(float x, float y, float z) {
  point.set_values(x, y, z);
}

void Vec3d::unit_vec() {
  float length = point.calculateLength();
  float x = point.get_x();
  float y = point.get_y();
  float z = point.get_z();

  point.set_values(x / length, y / length, z / length);
  cout << "Unit vector: (" << point.get_x() << ", " << point.get_y() << ", "
       << point.get_z() << ")" << endl;
}

int main() {
  Vec3d vec1(4, 8, 8);
  Vec3d vec2;

  vec2.set_values(4, 8, 8);
  vec1.unit_vec();
  vec2.unit_vec();
  return 0;
}