#ifndef POINT_H
#define POINT_H

class Point {
 public:
  Point();
  Point(float x, float y, float z);
  Point(const Point& other);
  float x() const;
  float y() const;
  float z() const;
  float distance(const Point& other);
  Point transform(float** tran);

 private:
  float x_, y_, z_;
};

#endif
