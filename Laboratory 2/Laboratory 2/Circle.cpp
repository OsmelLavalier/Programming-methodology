#include "Circle.h"

Circle::Circle(string n_, string c_, double r_): Shape(n_, c_)
{
    radius__ = r_;
}

void Circle::setRadius(double r_)
{
    radius__ = r_;
}

double Circle::getArea() const
{
    using std::pow;

    return pi___ * pow(radius__, 2);
}

double Circle::getRadius() const
{
    return radius__;
}

double Circle::getPI() const
{
    return pi___;
}
