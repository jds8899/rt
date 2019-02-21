#ifndef PHONG_H
#define PHONG_H

#include "intersect.h"
#include "illumination.h"
#include "color.h"
#include "light.h"

class Phong : public Illumination {
 public:
  Phong(Color c, float ka, float kd, float ks, float gloss);
  ~Phong();
  Color illuminate(Intersect* i, Light* l) override;
  float ka() override;
  float kd() override;
  float ks() override;
 private:
  float ka_, kd_, ks_, gloss_;
};

#endif
