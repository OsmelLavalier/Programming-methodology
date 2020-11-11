#include "Circle.h"

Circle::Circle(string n_, string c_, double r_, double p_): Shape(n_, c_)
{
    radius__ = r_;
    pi___ = p_;
}

void Circle::setRadius(double r_)
{
    radius__ = r_;
}

void Circle::setPI(double p_)
{
    pi___ = p_;
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