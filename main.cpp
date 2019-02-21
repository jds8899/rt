#include "camera.h"
#include "world.h"
#include "sphere.h"
#include "triangle.h"
#include "renderer.h"
#include "phong.h"
#include <iostream>

using std::cout;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT  = 480;
const float WORLD_WIDTH  = 1.33;
const float WORLD_HEIGHT   = 1;

int main(int argc, char** argv) {
  Sphere* s1 = new Sphere{new Phong{Color{.75,0,0}, .3,.5,.5,5}, Point{0.0,7.0,-1.0}, 2.0};
  Sphere* s2 = new Sphere{new Phong{Color{0,0,.75},.3,.5,.5,5}, Point{4.0,5.0,3.5}, 2.0};
  Triangle* t1 = new Triangle{new Phong{Color{0,.75,0},.2,.5,.5,5},
                              Point{-5.9,0,-30}, Point{18,0,-30}, Point{17.9,0,50}};
  Triangle* t2 = new Triangle{new Phong{Color{0,.75,0},.2,.5,.5,5},
                              Point{-6,1,-30}, Point{18.1,0,50}, Point{-6,0,50}};
  //Triangle* t2 = new Triangle{Color{0,.75,0}, Point{4,5,3.5}, Point{4,6,3.5}, Point{5,5,3.5}};

  Light* l1 = new Light{Point{0,10,-5}, Color{.5,.5,.5}};
  World world{};
  world.add(s2);
  world.add(s1);
  world.add(t1);
  world.add(t2);
  world.add_light(l1);

  Point p1{0,7,-9};
  Point p2{0,5,2};
  Vector v1{0,1,0};
  Camera camera{p1, p2, v1,
         SCREEN_HEIGHT, SCREEN_WIDTH, WORLD_HEIGHT, WORLD_WIDTH};

  Color** img = camera.render(world);

  Renderer r{SCREEN_WIDTH, SCREEN_HEIGHT};
  r.render(img);

  for(int i = 0; i < SCREEN_HEIGHT; ++i) {
    delete [] img[i];
  }
  delete [] img;
  delete s1;
  delete s2;
  delete t1;
  delete t2;
  delete l1;
  return 0;
}
