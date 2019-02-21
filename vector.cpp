#include "vector.h"
#include <math.h>
#include <iostream>

Vector::Vector() :
  x_{},
  y_{},
  z_{} {}

Vector::Vector(float x, float y, float z) :
  x_{x},
  y_{y},
  z_{z} {
    //this->normalize();
    //std::cout << x_ << " " << y_ << " " << z_ << "\n";
}

Vector::Vector(Point p0, Point p1) :
  x_{0},
  y_{0},
  z_{0} {
    x_ = p1.x() - p0.x();
    y_ = p1.y() - p0.y();
    z_ = p1.z() - p0.z();
    //this->normalize();
  }

Vector::Vector(const Vector& other) :
  x_{0},
  y_{0},
  z_{0} {
    x_ = other.x();
    y_ = other.y();
    z_ = other.z();
    //this->normalize();
}

float Vector::x() const {
  return x_;
}

float Vector::y() const {
  return y_;
}

float Vector::z() const {
  return z_;
}

Vector& Vector::operator=(const Vector& other) {
  x_ = other.x();
  y_ = other.y();
  z_ = other.z();
  return *this;
}

Vector Vector::operator+(const Vector& other) {
  float sum_x = x_ + other.x();
  float sum_y = y_ + other.y();
  float sum_z = z_ + other.z();
  Vector ret{sum_x, sum_y, sum_z};
  //ret.normalize();
  return ret;
}

Vector Vector::operator-(const Vector& other) {
  float diff_x = x_ - other.x();
  float diff_y = y_ - other.y();
  float diff_z = z_ - other.z();
  Vector ret{diff_x, diff_y, diff_z};
  //ret.normalize();
  return ret;
}

float Vector::dot(const Vector& other) {
  return (x_ * other.x()) + (y_ * other.y()) + (z_ * other.z());
}

Vector Vector::operator*(const Vector& other) {
  float cx = (z_ * other.y()) - (y_ * other.z());
  float cy = (x_ * other.z()) - (z_ * other.x());
  float cz = (y_ * other.x()) - (x_ * other.y());
  Vector ret{cx, cy, cz};
  //ret.normalize();
  return ret;
}

Vector Vector::operator*(float other) {
  float prod_x = x_ * other;
  float prod_y = y_ * other;
  float prod_z = z_ * other;
  Vector ret{prod_x, prod_y, prod_z};
  //ret.normalize();
  return ret;
}

Vector Vector::transform(float** trans) {
  Vector old(*this);
  float x = (x_ * trans[0][0]) + (y_ * trans[0][1]) + (z_ * trans[0][2]) + (1.0 * trans[0][3]);
  float y = (x_ * trans[1][0]) + (y_ * trans[1][1]) + (z_ * trans[1][2]) + (1.0 * trans[1][3]);
  float z = (x_ * trans[2][0]) + (y_ * trans[2][1]) + (z_ * trans[2][2]) + (1.0 * trans[2][3]);
  float w = (x_ * trans[3][0]) + (y_ * trans[3][1]) + (z_ * trans[3][2]) + (1.0 * trans[3][3]);
  x_ = x / w;
  y_ = y / w;
  z_ = z / w;
  //this->normalize();
  return old;
}

float Vector::length() {
  float sum_squares = (x_ * x_) + (y_ * y_) + (z_ * z_);
  return sqrt(sum_squares);
}

float Vector::length_sq() {
  float sum_squares = (x_ * x_) + (y_ * y_) + (z_ * z_);
  return sum_squares;
}

void Vector::normalize() {
  float l = this->length();
  x_ /= l;
  y_ /= l;
  z_ /= l;
}
