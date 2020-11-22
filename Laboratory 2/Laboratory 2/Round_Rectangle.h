#ifndef Round_Rectangle_h
#define Round_Rectangle_h

#include "Rectangle.h"
#include "Circle.h"

class Round_Rectangle : public Rectangle
{
private:
    double radius__;
    Circle circle;

public:
    Round_Rectangle(string n_, string c_, double w_, double h_, double r_);

    double getArea() const override;
};

#endif 

