#include "sphere.h"
#include <cmath>

Sphere::Sphere(Illumination* material, Point center, float radius) :
  GeoObj::GeoObj(material),
  center_{center},
  radius_{radius} {}

Sphere::~Sphere() {}

Intersect* Sphere::intersect(Ray ray) {
  Intersect* ret = nullptr;
  float dist = -1;
  Vector diffV{center_, ray.origin()};
  float b = 2 * diffV.dot(ray.direction());
  float c = diffV.length_sq() - (radius_ * radius_);

  float radicand = (b * b) - (4 * c);
  if(radicand >= 0) {
    float plus = (-b + sqrt(radicand)) / 2.0;
    float min  = (-b - sqrt(radicand)) / 2.0;
    if(plus < min && plus > 0) {
      dist = plus;
      float x,y,z;
      x = ray.origin().x() + (ray.direction().x() * dist);
      y = ray.origin().y() + (ray.direction().y() * dist);
      z = ray.origin().z() + (ray.direction().z() * dist);
      Point p{x,y,z};
      Vector n{center_, p};
      n.normalize();
      ret = new Intersect{dist,p,n,ray};
    }
    else if(plus > min && min > 0) {
      dist = min;
      float x,y,z;
      x = ray.origin().x() + (ray.direction().x() * dist);
      y = ray.origin().y() + (ray.direction().y() * dist);
      z = ray.origin().z() + (ray.direction().z() * dist);
      Point p{x,y,z};
      Vector n{center_, p};
      n.normalize();
      ret = new Intersect{dist,p,n,ray};
    }
  }
  return ret;
}

Point Sphere::center() {
  return center_;
}

float Sphere::radius() {
  return radius_;
}
