#include "zpkutils.h"

namespace zpk {

static int  vert, X, Y, Z;


/*
 * @brief local function
 *
 */
void zpk(std::vector<zpk::Point3D> & ZPK, unsigned m, unsigned ban, int xsign, int ysign, int zsign)
{
  switch(ban)
  {
   case 1:
    if (m>2) zpk(ZPK, m/2,6, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z+=zsign;
    if (m>2) zpk(ZPK, m/2,3, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X+=xsign;
    if (m>2) zpk(ZPK, m/2,3, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z-=zsign;
    if (m>2) zpk(ZPK, m/2,5, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y+=ysign;
    if (m>2) zpk(ZPK, m/2,5, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z+=zsign;
    if (m>2) zpk(ZPK, m/2,3, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X-=xsign;
    if (m>2) zpk(ZPK, m/2,3, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z-=zsign;
    if (m>2) zpk(ZPK, m/2,6, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert].z = float(Z);
    break;

   case 2:
    if (m>2) zpk(ZPK, m/2,5, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y+=ysign;
    if (m>2) zpk(ZPK, m/2,4, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X+=xsign;
    if (m>2) zpk(ZPK, m/2,4, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y-=ysign;
    if (m>2) zpk(ZPK, m/2,6, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z+=zsign;
    if (m>2) zpk(ZPK, m/2,6, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y+=ysign;
    if (m>2) zpk(ZPK, m/2,4, xsign, -ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X-=xsign;
    if (m>2) zpk(ZPK, m/2,4, xsign, -ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y-=ysign;
    if (m>2) zpk(ZPK, m/2,5, xsign, -ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert].z = float(Z);
    break;

   case 3:
    if (m>2) zpk(ZPK, m/2,1, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y+=ysign;
    if (m>2) zpk(ZPK, m/2,6, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z+=zsign;
    if (m>2) zpk(ZPK, m/2,6, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y-=ysign;
    if (m>2) zpk(ZPK, m/2,4, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X+=xsign;
    if (m>2) zpk(ZPK, m/2,4, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y+=ysign;
    if (m>2) zpk(ZPK, m/2,6, xsign, -ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z-=zsign;
    if (m>2) zpk(ZPK, m/2,6, xsign, -ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y-=ysign;
    if (m>2) zpk(ZPK, m/2,1, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert].z = float(Z);
    break;

   case 4:
    if (m>2) zpk(ZPK, m/2,2, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z+=zsign;
    if (m>2) zpk(ZPK, m/2,5, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y-=ysign;
    if (m>2) zpk(ZPK, m/2,5, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z-=zsign;
    if (m>2) zpk(ZPK, m/2,3, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X-=xsign;
    if (m>2) zpk(ZPK, m/2,3, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z+=zsign;
    if (m>2) zpk(ZPK, m/2,5, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y+=ysign;
    if (m>2) zpk(ZPK, m/2,5, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z-=zsign;
    if (m>2) zpk(ZPK, m/2,2, xsign, -ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert].z = float(Z);
    break;

   case 5:
    if (m>2) zpk(ZPK, m/2,4, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X+=xsign;
    if (m>2) zpk(ZPK, m/2,2, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z+=zsign;
    if (m>2) zpk(ZPK, m/2,2, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X-=xsign;
    if (m>2) zpk(ZPK, m/2,1, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y+=ysign;
    if (m>2) zpk(ZPK, m/2,1, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X+=xsign;
    if (m>2) zpk(ZPK, m/2,2, xsign, -ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z-=zsign;
    if (m>2) zpk(ZPK, m/2,2, xsign, -ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X-=xsign;
    if (m>2) zpk(ZPK, m/2,4, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert].z = float(Z);
    break;

   case 6:
    if (m>2) zpk(ZPK, m/2,3, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X-=xsign;
    if (m>2) zpk(ZPK, m/2,1, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y-=ysign;
    if (m>2) zpk(ZPK, m/2,1, -xsign, -ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X+=xsign;
    if (m>2) zpk(ZPK, m/2,2, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Z+=zsign;
    if (m>2) zpk(ZPK, m/2,2, xsign, ysign, zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X-=xsign;
    if (m>2) zpk(ZPK, m/2,1, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    Y+=ysign;
    if (m>2) zpk(ZPK, m/2,1, -xsign, ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert++].z = float(Z);
    X+=xsign;
    if (m>2) zpk(ZPK, m/2,3, xsign, -ysign, -zsign);
    ZPK[vert].x = float(X); ZPK[vert].y = float(Y); ZPK[vert].z = float(Z);
    break;

   default: break;
  }
}

int getNumberOfPointsForIteration(int iteration)
{
  return (1<<(3*iteration));
}

std::auto_ptr<std::vector<Point3D> > getUnityCube(int iteration)
{
  if (iteration<=0)
    return std::auto_ptr<std::vector<Point3D> >(0);

  unsigned N = 1<<iteration;
  unsigned N3 = N*N*N;

  std::vector<Point3D> *points = new std::vector<Point3D>(N3);
  if (0==points)
    return std::auto_ptr<std::vector<Point3D> >(0);

  vert = 0; X=Y=Z=0;
  zpk(*points, N, 1, 1,1,1);

  for (std::vector<Point3D>::iterator it=points->begin(),itend=points->end(); it!=itend; ++it)
  {
    it->x/= (N-1);
    it->y/= (N-1);
    it->z/= (N-1);
  }


  return std::auto_ptr<std::vector<Point3D> >(points);
}

}
