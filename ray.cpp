#include "ray.h"

Ray::Ray() :
  origin_{},
  direction_{} {}

Ray::Ray(Point origin, Vector direction) :
  origin_{origin},
  direction_{direction} {
    direction.normalize();
  }

Point Ray::origin() {
  return origin_;
}

Vector Ray::direction() {
  return direction_;
}

void Ray::set_origin(Point origin) {
  origin_ = origin;
}

void Ray::set_direction(Vector direction) {
  direction_ = direction;
}
