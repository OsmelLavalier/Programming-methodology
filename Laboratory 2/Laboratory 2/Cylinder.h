#ifndef Cylinder_h
#define Cylinder_h

#include "Circle.h"


class Cylinder : public Circle
{
private:
    double height__;

public:
    Cylinder(string n_, string c_, double r_, double p_, double h_);

    double getArea() const override;
};

#endif