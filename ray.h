#ifndef RAY_H
#define RAY_H

#include "point.h"
#include "vector.h"

class Ray {
 public:
  Ray();
  Ray(Point origin, Vector direction);
  Point origin();
  Vector direction();
  void set_origin(Point origin);
  void set_direction(Vector direction);

 private:
  Point origin_;
  Vector direction_;
};

#endif
