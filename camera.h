#ifndef CAMERA_H
#define CAMERA_H

#include "point.h"
#include "vector.h"
#include "world.h"

class Camera {
 public:
  Camera(Point position, Point lookat, Vector up,
         int screen_height, int screen_width,
         float world_height, float world_width);
  Color** render(World world);

 private:
  Color** tone_repro(Color** img);
  Point position_, lookat_;
  Vector up_;
  int screen_height_, screen_width_;
  float world_height_, world_width_;
  Vector n_, u_, v_;
  Point center_;
  float pix_dx_, pix_dy_;
  Point start_;
};

#endif
