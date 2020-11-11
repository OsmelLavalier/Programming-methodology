#ifndef Parallelepiped_h
#define Parallelepiped_h

#include "Rectangle.h"


class Parallelepiped : public Rectangle
{
private:
    double depth__;
public:
    Parallelepiped(string n_, string c_, double w_, double h_, double d_);

    double getArea() const override;
};

#endif

