#include "Rectangle.h"

Rectangle::Rectangle(string n_, string c_, double w_, double h_): Shape(n_, c_)
{
    width__ = w_;
    height__ = h_;
}

void Rectangle::setWidth(double w_)
{
    width__ = w_;
}

void Rectangle::setHeight(double h_)
{
    height__ = h_;
}

double Rectangle::getWidth() const
{
    return width__;
}

double Rectangle::getHeight() const
{
    return height__;
}

double Rectangle::getArea() const
{
    return width__ * height__;
}

