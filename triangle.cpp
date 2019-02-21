#include "triangle.h"
#include <math.h>
#include <iostream>

using std::vector;

const float EPS = 1e-6;

Triangle::Triangle(Illumination* material, Point p0, Point p1, Point p2) :
  GeoObj::GeoObj(material),
  p0_{p0},
  p1_{p1},
  p2_{p2} {}

Triangle::~Triangle() {}

Intersect* Triangle::intersect(Ray ray) {
  Vector e1{p0_, p1_};
  Vector e2{p0_, p2_};
  Vector P = e2 * ray.direction();
  float det = e1.dot(P);
  //std::cout << e1.x() << " " << e1.y() << " " << e1.z() << "\n";
  //std::cout << e2.x() << " " << e2.y() << " " << e2.z() << "\n";
  //std::cout << P.x() << " " << P.y() << " " << P.z() << "\n";
  //std::cout << det << "\n";

  if(fabs(det) < EPS)
    return nullptr;

  float inverse_det = 1.0 / det;

  Vector T{p0_, ray.origin()};
  float u = P.dot(T) * inverse_det;
  if(u < 0 || u > 1)
    return nullptr;

  Vector Q = e1 * T;
  float v = Q.dot(ray.direction()) * inverse_det;

  if(v < 0 || u + v > 1)
    return nullptr;

  float omega = e2.dot(Q) * inverse_det;
  float x,y,z;
  x = ray.origin().x() + ray.direction().x() * omega;
  y = ray.origin().y() + ray.direction().y() * omega;
  z = ray.origin().y() + ray.direction().z() * omega;
  Point p{x,y,z};
  Vector n = e1 * e2;
  n.normalize();
  Intersect* ret = new Intersect{omega, p, n, ray};
  //std::cout << omega << "\n";
  return ret;
}

vector<Point> Triangle::vertices() {
  vector<Point> verts{};
  verts.push_back(p0_);
  verts.push_back(p1_);
  verts.push_back(p2_);
  return verts;
}

