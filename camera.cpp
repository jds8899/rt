#include "camera.h"
#include <iostream>

const float FOCAL_LENGTH = 1.0;

Camera::Camera(Point position, Point lookat, Vector up,
               int screen_height, int screen_width,
               float world_height,  float world_width) :
  position_{position},
  lookat_ {lookat},
  up_{up},
  screen_height_{screen_height},
  screen_width_{screen_width},
  world_height_{world_height},
  world_width_ {world_width},
  n_{0,0,0},
  u_{0,0,0},
  v_{0,0,0},
  center_{0,0,0},
  pix_dx_{0},
  pix_dy_{0},
  start_{0,0,0} {
    float nx = lookat.x() - position.x();
    float ny = lookat.y() - position.y();
    float nz = lookat.z() - position.z();
    n_ = Vector{nx, ny, nz};
    n_.normalize();
    u_ = n_ * up;
    u_.normalize();
    v_ = u_ * n_;
    v_.normalize();
    //std::cout << v_.x() << " " << v_.y() << " " << v_.z() << "\n";
    float center_x = position.x() + FOCAL_LENGTH * n_.x();
    float center_y = position.y() + FOCAL_LENGTH * n_.y();
    float center_z = position.z() + FOCAL_LENGTH * n_.z();
    center_ = Point{center_x, center_y, center_z};
    pix_dx_ = (float)world_width / (float)screen_width;
    pix_dy_ = (float)world_height / (float)screen_height;
    float start_x = center_.x() - ((world_width * u_.x()) + (world_height * v_.x())) / 2.0;
    float start_y = center_.y() - ((world_width * u_.y()) + (world_height * v_.y())) / 2.0;
    float start_z = center_.z() - ((world_width * u_.z()) + (world_height * v_.z())) / 2.0;
    start_ = Point{start_x, start_y, start_z};
  }

Color** Camera::tone_repro(Color** img) {
  Color rmax{};
  Color gmax{};
  Color bmax{};
  Color** ret = new Color*[screen_height_];
  for(int i = 0; i < screen_height_; ++i) {
    ret[i] = new Color[screen_width_];
  }
  for(int i = 0; i < screen_height_; ++i) {
    for(int j = 0; j < screen_width_; ++j) {
      Color curr = img[i][j];
      if(curr.r() > rmax.r()) rmax = curr;
      if(curr.g() > gmax.g()) gmax = curr;
      if(curr.b() > bmax.b()) bmax = curr;
    }
  }
  for(int i = 0; i < screen_height_; ++i) {
    for(int j = 0; j < screen_width_; ++j) {
      Color curr = img[i][j];
      float r,g,b;
      r = curr.r() / rmax.r();
      g = curr.g() / gmax.g();
      b = curr.b() / bmax.b();
      ret[i][j] = Color{r,g,b};
    }
  }
  return ret;
}

Color** Camera::render(World world) {
  Color** img = new Color*[screen_height_];
  for(int i = 0; i < screen_height_; ++i) {
    img[i] = new Color[screen_width_];
  }
  float x, y, z;
  for(int i = 0; i < screen_height_; ++i) {
    for(int j = 0; j < screen_width_; ++j) {
      x = start_.x() + (i + .5) * v_.x() * pix_dy_ + (j + .5) * u_.x() * pix_dx_;
      y = start_.y() + (i + .5) * v_.y() * pix_dy_ + (j + .5) * u_.y() * pix_dx_;
      z = start_.z() + (i + .5) * v_.z() * pix_dy_ + (j + .5) * u_.z() * pix_dx_;
      //std::cout << x << " " << y << " " << z << "\n";
      Vector view{x - position_.x(), y - position_.y(), z - position_.z()};
      view.normalize();
      Ray r{position_, view};
      Color col = world.spawn(r);
      img[i][j] = col;
    }
  }
  Color** ret = tone_repro(img);
  return ret;
}
