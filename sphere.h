#ifndef SPHERE_H
#define SPHERE_H

#include "color.h"
#include "point.h"
#include "vector.h"
#include "intersect.h"
#include "geo_obj.h"
#include "illumination.h"

class Sphere : public GeoObj {
 public:
  Sphere(Illumination* material, Point center, float radius);
  ~Sphere();
  Intersect* intersect(Ray ray) override;
  Point center();
  float radius();

 private:
  Point center_;
  float radius_;
};

#endif
