#ifndef POLYGON_H
#define POLYGON_H

#include "color.h"
#include "point.h"
#include "vector.h"
#include "geo_obj.h"
#include "illumination.h"
#include "intersect.h"
#include <vector>

/**
 * CLOCKWISE
 */
class Triangle : public GeoObj {
 public:
  Triangle(Illumination* Material, Point p0, Point p1, Point p2);
  ~Triangle();
  Intersect* intersect(Ray ray) override;
  std::vector<Point> vertices();

 private:
  Point p0_, p1_, p2_;
};

#endif
