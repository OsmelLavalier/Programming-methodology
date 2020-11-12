#ifndef Rectangle_h
#define Rectangle_h

#include "Shape.h"

class Rectangle : public Shape
{
private:
    double width__;
    double height__;

public:
    Rectangle(string n_, string c_, double w_, double h_);

    void setWidth(double w_);
    void setHeight(double h_);

    double getWidth() const;
    double getHeight() const;

    double getArea() const override;
};

#endif // !Rectangle_h


