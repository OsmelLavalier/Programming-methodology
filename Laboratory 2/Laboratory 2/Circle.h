#ifndef Circle_h
#define Circle_h

#include "shape.h"

class Circle : public Shape
{
private:
    double radius__;
    double pi___;
public:
    Circle(string n_, string c_, double r_, double p_);

    void setRadius(double r_);
    void setPI(double p_);

    double getArea() const override;
    double getRadius() const;
    double getPI() const;
};

#endif