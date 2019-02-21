#include "intersect.h"
#include <cmath>

Intersect::Intersect(float d, Point p, Vector n, Ray r) :
  d_{d},
  p_{p},
  n_{n},
  r_{r} {}

Point Intersect::p() const {
  return p_;
}

Vector Intersect::n() const {
  return n_;
}

float Intersect::d() const {
  return d_;
}

Ray Intersect::r() const {
  return r_;
}

float EPS = .0001;

bool Intersect::operator==(const Intersect& other) {
  float a = fabs(n_.x() - other.n().x());
  float b = fabs(n_.y() - other.n().y());
  float c = fabs(n_.z() - other.n().z());
  return a < EPS && b < EPS && c < EPS;
}
