#include "Shape.h"

Shape::Shape(string n_, string c_): name__(n_), colour__(c_) {}

void Shape::setName(string n_)      { name__ = n_;     }

void Shape::setColour(string c_)    { colour__ = c_;   }

string Shape::getName() const       { return name__;   }

string Shape::getColour() const     { return colour__; }
