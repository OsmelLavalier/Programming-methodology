#include "Round_Rectangle.h"

Round_Rectangle::Round_Rectangle(string n_, string c_, double w_, double h_, double r_, double p_)
    : Rectangle(n_, c_, w_, h_)
{
    radius__ = r_;
    pi__ = p_;
}

double Round_Rectangle::getArea() const 
{
    using std::pow;
 
    return getWidth() * getHeight() - (4 * pow(radius__, 2) - pi__ * pow(radius__, 2));
}
