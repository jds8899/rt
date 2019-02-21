#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "geo_obj.h"
#include "light.h"
#include "ray.h"

class World {
 public:
  World();
  World(std::vector<GeoObj*> obj_list, std::vector<Light*> light_list);
  void add(GeoObj* obj);
  void add_light(Light* obj);
  void transform(GeoObj* obj);
  void transform_all();
  Color spawn(Ray ray);

 private:
  bool light_vis_(Ray r, Light* l, GeoObj* obj);
  std::vector<GeoObj*> obj_list_;
  std::vector<Light*> light_list_;
};

#endif
