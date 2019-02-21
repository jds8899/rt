#ifndef COLOR_H
#define COLOR_H

class Color {
public:
  Color(float r, float g, float b);
  Color();
  float r() const;
  float g() const;
  float b() const;
  Color operator+(const Color& other);
  Color operator*(const Color& other);
  Color operator*(float coeff);
  void set_r(float r);
  void set_g(float g);
  void set_b(float b);

private:
  float r_, g_, b_;
};

#endif
