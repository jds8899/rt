#include "color.h"

Color::Color(float r, float g, float b) :
  r_{r},
  g_{g},
  b_{b} {}

Color::Color() :
  r_{0},
  g_{0},
  b_{0}{}

Color Color::operator+(const Color& other) {
  float r,g,b;
  r = r_ + other.r();
  g = g_ + other.g();
  b = b_ + other.b();
  Color ret{r,g,b};
  return ret;
}

Color Color::operator*(float coeff) {
  float r,g,b;
  r = r_ * coeff;
  g = g_ * coeff;
  b = b_ * coeff;
  Color ret{r,g,b};
  return ret;
}

Color Color::operator*(const Color& other) {
  float r,g,b;
  r = r_ * other.r();
  g = g_ * other.g();
  b = b_ * other.b();
  Color ret{r,g,b};
  return ret;
}

float Color::r() const {
  return r_;
}

float Color::g() const {
  return g_;
}

float Color::b() const {
  return b_;
}

void Color::set_r(float r) {
  r_ = r;
}

void Color::set_g(float g) {
  g_ = g;
}

void Color::set_b(float b) {
  b_ = b;
}
