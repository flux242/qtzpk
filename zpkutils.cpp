#include "zpkutils.h"

namespace zpk {

/*
 * @brief local function
 *
 */
void zpk2D(zpk::Point3D*& zpkarr, unsigned m, unsigned ban, Point3D& p, int xsign, int ysign)
{
  switch(ban)
  {
  case 1:
    if (m>2) zpk2D(zpkarr, m/2,2, p, xsign, ysign);
    zpkarr->x = p.x; zpkarr->y = p.y; ++zpkarr;
    p.y+=ysign; 
    if (m>2) zpk2D(zpkarr, m/2,1, p, xsign, ysign);
    zpkarr->x = p.x; zpkarr->y = p.y; ++zpkarr;
    p.x+=xsign; 
    if (m>2) zpk2D(zpkarr, m/2,1, p, xsign, ysign);
    zpkarr->x = p.x; zpkarr->y = p.y; ++zpkarr;
    p.y-=ysign; 
    if (m>2) zpk2D(zpkarr, m/2,2, p, -xsign, -ysign);
    zpkarr->x = p.x; zpkarr->y = p.y;
    break;
  case 2:
    if (m>2) zpk2D(zpkarr, m/2,1, p, xsign, ysign);
    zpkarr->x = p.x; zpkarr->y = p.y; ++zpkarr;
    p.x+=xsign; 
    if (m>2) zpk2D(zpkarr, m/2,2, p, xsign, ysign);
    zpkarr->x = p.x; zpkarr->y = p.y; ++zpkarr;
    p.y+=ysign; 
    if (m>2) zpk2D(zpkarr, m/2,2, p, xsign, ysign);
    zpkarr->x = p.x; zpkarr->y = p.y; ++zpkarr;
    p.x-=xsign; 
    if (m>2) zpk2D(zpkarr, m/2,1, p, -xsign, -ysign);
    zpkarr->x = p.x; zpkarr->y = p.y;
    break;
  }
}

void zpk3D(zpk::Point3D*& zpkarr, unsigned m, unsigned ban, Point3D& p, int xsign, int ysign, int zsign)
{
  switch(ban)
  {
   case 1:
    if (m>2) zpk3D(zpkarr, m/2,6, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z+=zsign;
    if (m>2) zpk3D(zpkarr, m/2,3, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x+=xsign;
    if (m>2) zpk3D(zpkarr, m/2,3, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z-=zsign;
    if (m>2) zpk3D(zpkarr, m/2,5, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y+=ysign;
    if (m>2) zpk3D(zpkarr, m/2,5, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z+=zsign;
    if (m>2) zpk3D(zpkarr, m/2,3, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x-=xsign;
    if (m>2) zpk3D(zpkarr, m/2,3, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z-=zsign;
    if (m>2) zpk3D(zpkarr, m/2,6, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z;
    break;

   case 2:
    if (m>2) zpk3D(zpkarr, m/2,5, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y+=ysign;
    if (m>2) zpk3D(zpkarr, m/2,4, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x+=xsign;
    if (m>2) zpk3D(zpkarr, m/2,4, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y-=ysign;
    if (m>2) zpk3D(zpkarr, m/2,6, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z+=zsign;
    if (m>2) zpk3D(zpkarr, m/2,6, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y+=ysign;
    if (m>2) zpk3D(zpkarr, m/2,4, p, xsign, -ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x-=xsign;
    if (m>2) zpk3D(zpkarr, m/2,4, p, xsign, -ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y-=ysign;
    if (m>2) zpk3D(zpkarr, m/2,5, p, xsign, -ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z;
    break;

   case 3:
    if (m>2) zpk3D(zpkarr, m/2,1, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y+=ysign;
    if (m>2) zpk3D(zpkarr, m/2,6, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z+=zsign;
    if (m>2) zpk3D(zpkarr, m/2,6, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y-=ysign;
    if (m>2) zpk3D(zpkarr, m/2,4, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x+=xsign;
    if (m>2) zpk3D(zpkarr, m/2,4, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y+=ysign;
    if (m>2) zpk3D(zpkarr, m/2,6, p, xsign, -ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z-=zsign;
    if (m>2) zpk3D(zpkarr, m/2,6, p, xsign, -ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y-=ysign;
    if (m>2) zpk3D(zpkarr, m/2,1, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z;
    break;

   case 4:
    if (m>2) zpk3D(zpkarr, m/2,2, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z+=zsign;
    if (m>2) zpk3D(zpkarr, m/2,5, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y-=ysign;
    if (m>2) zpk3D(zpkarr, m/2,5, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z-=zsign;
    if (m>2) zpk3D(zpkarr, m/2,3, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x-=xsign;
    if (m>2) zpk3D(zpkarr, m/2,3, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z+=zsign;
    if (m>2) zpk3D(zpkarr, m/2,5, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y+=ysign;
    if (m>2) zpk3D(zpkarr, m/2,5, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z-=zsign;
    if (m>2) zpk3D(zpkarr, m/2,2, p, xsign, -ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z;
    break;

   case 5:
    if (m>2) zpk3D(zpkarr, m/2,4, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x+=xsign;
    if (m>2) zpk3D(zpkarr, m/2,2, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z+=zsign;
    if (m>2) zpk3D(zpkarr, m/2,2, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x-=xsign;
    if (m>2) zpk3D(zpkarr, m/2,1, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y+=ysign;
    if (m>2) zpk3D(zpkarr, m/2,1, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x+=xsign;
    if (m>2) zpk3D(zpkarr, m/2,2, p, xsign, -ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z-=zsign;
    if (m>2) zpk3D(zpkarr, m/2,2, p, xsign, -ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x-=xsign;
    if (m>2) zpk3D(zpkarr, m/2,4, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z;
    break;

   case 6:
    if (m>2) zpk3D(zpkarr, m/2,3, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x-=xsign;
    if (m>2) zpk3D(zpkarr, m/2,1, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y-=ysign;
    if (m>2) zpk3D(zpkarr, m/2,1, p, -xsign, -ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x+=xsign;
    if (m>2) zpk3D(zpkarr, m/2,2, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.z+=zsign;
    if (m>2) zpk3D(zpkarr, m/2,2, p, xsign, ysign, zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x-=xsign;
    if (m>2) zpk3D(zpkarr, m/2,1, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.y+=ysign;
    if (m>2) zpk3D(zpkarr, m/2,1, p, -xsign, ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z; ++zpkarr;
    p.x+=xsign;
    if (m>2) zpk3D(zpkarr, m/2,3, p, xsign, -ysign, -zsign);
    zpkarr->x = p.x; zpkarr->y = p.y; zpkarr->z = p.z;
    break;

   default: break;
  }
}

void zpk(std::vector<zpk::Point3D> & zpk, Dim d, unsigned m, unsigned ban, int xsign, int ysign, int zsign)
{
  Point3D p(0.0, 0.0, 0.0);
  Point3D* zpkarr = &zpk[0];
  if (zpk::D2D==d)
    zpk2D(zpkarr, m, ban, p, xsign, ysign);
  else
    zpk3D(zpkarr, m, ban, p, xsign, ysign, zsign);
}

// interface functions
int getNumberOfPointsForIteration(int iteration, Dim d)
{
  if (D2D==d)
    return (1<<(2*iteration));
 
  return (1<<(3*iteration));
}

std::auto_ptr<std::vector<Point3D> > getUnityCube(int iteration, Dim d)
{
  if (iteration<=0)
    return std::auto_ptr<std::vector<Point3D> >(0);

  unsigned N = 1<<iteration;
  unsigned ND = d==D3D?N*N*N:N*N;

  std::vector<Point3D> *points = new std::vector<Point3D>(ND);
  if (0==points)
    return std::auto_ptr<std::vector<Point3D> >(0);

  zpk(*points, d, N, 1, 1,1,1);

  for (std::vector<Point3D>::iterator it=points->begin(),itend=points->end(); it!=itend; ++it)
  {
    it->x/= (N-1);
    it->y/= (N-1);
    if (d==zpk::D3D)
      it->z/= (N-1);
    else
      it->z = 0.5;
  }

  return std::auto_ptr<std::vector<Point3D> >(points);
}

}
