//
//  shape.h
//  Laboratory 2
//
//  Created by Osmel Lavalier Martin on 2020-11-10.
//

#ifndef shape_hpp
#define shape_hpp

#include<bits/stdc++.h>

//Interface class (Abstract base class)
class Shape
{
public:
   Shape(string colour, string name) : colour__(colour), name__(name) {}

	void setColour(string colour) { colour__ = colour; }
	void setName(string name) { name__ = name; }
	
	//pure virtual function, shape does not implement both functions
	virtual string getColour() const = 0; 
	string getName() const { return name__; }
	virtual double getArea() const = 0;

private:
   string colour__;
	string name__;
   
};

#endif /* shape_hpp */
