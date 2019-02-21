#include "illumination.h"

Illumination::Illumination(Color c) : c_{c} {}

Illumination::~Illumination() {}

Color Illumination::c() {
  return c_;
}
