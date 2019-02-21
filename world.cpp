#include "world.h"
#include "intersect.h"
#include <iostream>

Color ambient{.2,.8,.8};

World::World() :
  obj_list_{},
  light_list_{}{}

World::World(std::vector<GeoObj*> obj_list, std::vector<Light*> light_list) :
  obj_list_{obj_list},
  light_list_{light_list} {}

void World::add(GeoObj* obj) {
  obj_list_.push_back(obj);
}

void World::add_light(Light* obj) {
  light_list_.push_back(obj);
}

void World::transform(GeoObj* obj) {}

void World::transform_all() {}

bool World::light_vis_(Ray r, Light* l, GeoObj* obj) {
  bool ret = true;
  GeoObj* winner = nullptr;
  Intersect* iwin = nullptr;
  //std::cout << "obj: " << *obj << "\n";
  for(auto prim : obj_list_) {
    if(prim != obj) {
      Intersect* i = prim->intersect(r);
      if(i != nullptr) {
        ret = false;
        winner = prim;
        iwin = i;
      }
    }
  }
  //if(winner != nullptr) std::cout << "winner: " << *winner << " " << iwin->d() << "\n";
  if(winner != nullptr && iwin->d() < 0) ret = true;
  return ret;
}

Color World::spawn(Ray ray) {
  float omega_small = 999999;
  GeoObj* winner = nullptr;
  float d;
  Point p;
  Vector n;
  Ray r;
  for(auto obj : obj_list_) {
    Intersect* i = obj->intersect(ray);
    if(i != nullptr) {
      float omega = i->d();
      //std::cout << omega << "\n";
      if(omega > 0.0 && omega < omega_small) {
        omega_small = omega;
        winner = obj;
        d = i->d();
        p = i->p();
        n = i->n();
        r = i->r();
      }
      delete i;
    }
  }
  if(winner == nullptr) {
    return Color(0.5,0.5,0.5);
  }
  Intersect* i = new Intersect{d,p,n,r};
  Color ret = ambient * winner->material()->ka() * winner->material()->c();
  for(auto l : light_list_) {
    Vector v{i->p(), l->position()};
    v.normalize();
    Ray light_ray{i->p(), v};
    if(light_vis_(light_ray, l, winner)) {
      ret = ret + winner->material()->illuminate(i, l);
    }
  }
  return ret;
}
