#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(string n_, string c_, double w_, double h_, double d_)
    : Rectangle(n_, c_, w_, h_)
{
    depth__ = d_;
}

double Parallelepiped::getArea() const
{
    return 2 * (getWidth() * getHeight() + getWidth() * depth__ + getHeight() * depth__);
}
