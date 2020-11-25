#include "Round_Rectangle.h"

Round_Rectangle::Round_Rectangle(string n_, string c_, double w_, double h_, double r_)
    : Rectangle(n_, c_, w_, h_)
{
    radius__ = r_;
}

double Round_Rectangle::getArea() const 
{
    using std::pow;
    double circle_area = circle.getArea();

    return getWidth() * getHeight() * circle_area.getArea();
}
