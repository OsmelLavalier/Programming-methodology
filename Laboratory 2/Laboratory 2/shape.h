//
//  shape.h
//  Laboratory 2
//
//  Created by Osmel Lavalier Martin on 2020-11-10.
//

#ifndef shape_h
#define shape_h

#include<iostream>

using std::string;

/* Abstract base class */
class Shape
{
private:
    string name__;
    string colour__;

public:
    Shape(string n_, string c_);

    void setName(string n_);
    void setColour(string c_);

    /* Functions to be overriden in our derived classes */
    virtual double getArea() const = 0;
    virtual string getName() const;
    virtual string getColour() const;
};

#endif /* shape_h */
