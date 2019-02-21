#ifndef INTERSECT_H
#define INTERSECT_H

#include "point.h"
#include "vector.h"
#include "light.h"
#include "ray.h"

class Intersect {
 public:
  Intersect(float d, Point p, Vector n, Ray r);
  Point p() const;
  Vector n() const;
  float d() const;
  Ray r() const;
  bool operator==(const Intersect& other);
 private:
  float d_;
  Point p_;
  Vector n_;
  Ray r_;
};

#endif
