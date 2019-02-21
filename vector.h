#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"

class Vector {
 public:
  Vector();
  Vector(float x, float y, float z);
  Vector(Point p0, Point p1);
  Vector(const Vector& other);
  float x() const;
  float y() const;
  float z() const;
  Vector operator+(const Vector& other);
  Vector operator-(const Vector& other);
  Vector& operator=(const Vector& other);
  float dot(const Vector& other);
  Vector operator*(const Vector& other);
  Vector operator*(float other);
  Vector transform(float** trans);
  float length();
  float length_sq();
  void normalize();

 private:
  float x_, y_, z_;
};

#endif
