#ifndef ZPKUTILS_H
#define ZPKUTILS_H

#include <vector>
#include <memory>

namespace zpk
{

class Point3D
{
public:
  Point3D() : x(0.0f), y(0.0f), z(0.0f) {}
  Point3D(const Point3D &that) : x(that.x), y(that.y), z(that.z) {}
  Point3D(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}
  Point3D(const float *xx) : x(*xx), y( *(xx+1) ), z(*(xx+2)) {}
  float x,y,z;
private:
  // Point3D& operator=(const Point3D &);
};

extern int getNumberOfPointsForIteration(int iteration);
extern std::auto_ptr<std::vector<zpk::Point3D> > getUnityCube(int iteration);

} // end of zpk namespace

#endif // ZPKUTILS_H
