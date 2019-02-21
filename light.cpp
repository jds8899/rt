#include "light.h"

Light::Light(Point position, Color color) :
  position_{position},
  color_{color} {}

Point Light::position() {
  return position_;
}

Color Light::color() {
  return color_;
}
