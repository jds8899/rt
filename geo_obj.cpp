#include "geo_obj.h"

using std::cout;

GeoObj::GeoObj(Illumination* material) :
  material_{material} {}

GeoObj::~GeoObj() {
  delete material_;
}

GeoObj::GeoObj(const GeoObj& other) :
  material_{other.material()} {}

GeoObj& GeoObj::operator=(const GeoObj& other) {
  material_ = other.material();
  return *this;
}

Illumination* GeoObj::material() const {
  return material_;
}

std::ostream& operator<<(std::ostream& os, const GeoObj& geoobj) {
  os << geoobj.material()->c().r() << " " <<
    geoobj.material()->c().g() << " " << geoobj.material()->c().b() << "\n";
  return os;
}
