#ifndef GEO_OBJ_H
#define GEO_OBJ_H

#include "ray.h"
#include "color.h"
#include "intersect.h"
#include "illumination.h"
#include <iostream>

class GeoObj {
 public:
  GeoObj(Illumination* material);
  virtual ~GeoObj();
  GeoObj(const GeoObj&);
  GeoObj& operator=(const GeoObj&);
  virtual Intersect* intersect(Ray ray) = 0;
  Illumination* material() const;
  friend std::ostream& operator<<(std::ostream& os, const GeoObj& geoobj);
 private:
  Illumination* material_;
};

#endif
