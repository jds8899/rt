#ifndef ILLUMINATION_H
#define ILLUMINATION_H

#include "intersect.h"
#include "color.h"
#include "light.h"

class Illumination {
 public:
  Illumination(Color c);
  virtual ~Illumination();
  virtual Color illuminate(Intersect* i, Light* l) = 0;
  Color c();
  virtual float ka() = 0;
  virtual float kd() = 0;
  virtual float ks() = 0;
 protected:
  Color c_;
};

#endif
