#ifndef Circle_h
#define Circle_h

#include "Shape.h"

class Circle : public Shape
{
private:
    double radius__;
    const double pi___ = M_PI;
public:
    Circle(string n_, string c_, double r_);

    void setRadius(double r_);

    double getArea() const override;
    double getRadius() const;
    double getPI() const;
};

#endif