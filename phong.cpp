#include "phong.h"
#include <cmath>

Phong::Phong(Color c, float ka, float kd, float ks, float gloss) :
  Illumination::Illumination(c),
  ka_{ka},
  kd_{kd},
  ks_{ks},
  gloss_{gloss} {}

Phong::~Phong() {}

Color Phong::illuminate(Intersect* i, Light* l) {
  Point p = i->p();
  Vector L{p, l->position()};
  L.normalize();
  Vector N = i->n();
  float LN = L.dot(N);
  if(LN < 0) LN = 0;
  Color diffuse = l->color() * c_ * kd_ * LN;
  if(LN > 0) {
    Vector R{};
    R = N * (2 * LN) - L;
    R.normalize();
    Vector V{p, i->r().origin()};
    V.normalize();
    float RV = R.dot(V);
    if(RV < 0) RV = 0;
    Color spec = l->color() * l->color() * ks_ * std::pow(RV, gloss_);
    diffuse = diffuse + spec;
  }
  return diffuse;
}

float Phong::ka() {
  return ka_;
}

float Phong::kd() {
  return kd_;
}

float Phong::ks() {
  return ks_;
}
