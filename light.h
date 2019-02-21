#ifndef LIGHT_H
#define LIGHT_H

#include "color.h"
#include "point.h"

class Light {
 public:
  Light(Point position, Color color);
  Point position();
  Color color();
 private:
  Point position_;
  Color color_;
};

#endif
