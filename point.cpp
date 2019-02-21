#include "point.h"
#include <math.h>
#include <iostream>

Point::Point() :
  x_{},
  y_{},
  z_{} {}

Point::Point(float x, float y, float z) :
  x_{x},
  y_{y},
  z_{z} {
    //std::cout << "making point " << x << " " << y << " " << z << "\n";
  }

Point::Point(const Point& other) :
  x_{0},
  y_{0},
  z_{0} {
    x_ = other.x();
    y_ = other.y();
    z_ = other.z();
}

float Point::x() const {
  return x_;
}

float Point::y() const {
  return y_;
}

float Point::z() const {
  return z_;
}

float Point::distance(const Point& other) {
  float dx = x_ - other.x();
  float dy = y_ - other.y();
  float dz = z_ - other.z();

  float sum_sq = (dx * dx) + (dy * dy) + (dz * dz);
  return sqrt(sum_sq);
}

Point Point::transform(float** trans) {
  Point old(*this);
  float x = (x_ * trans[0][0]) + (y_ * trans[0][1]) + (z_ * trans[0][2]) + (1.0 * trans[0][3]);
  float y = (x_ * trans[1][0]) + (y_ * trans[1][1]) + (z_ * trans[1][2]) + (1.0 * trans[1][3]);
  float z = (x_ * trans[2][0]) + (y_ * trans[2][1]) + (z_ * trans[2][2]) + (1.0 * trans[2][3]);
  float w = (x_ * trans[3][0]) + (y_ * trans[3][1]) + (z_ * trans[3][2]) + (1.0 * trans[3][3]);
  x_ = x / w;
  y_ = y / w;
  z_ = z / w;
  return old;
}
