#include "Cylinder.h"

Cylinder::Cylinder(string n_, string c_, double r_, double p_, double h_) : Circle(n_, c_, r_, p_)
{
    height__ = h_;
}

double Cylinder::getArea() const
{
    return 2 * getPI() * getRadius() * (height__ + getRadius());
}
