//
//  rectangle.hpp
//  Laboratory 2
//
//  Created by Osmel Lavalier Martin on 2020-11-10.
//

#ifndef rectangle_hpp
#define rectangle_hpp

#include "shape.hpp"

class Rectangle : public Shape
{
	public:
		Rectangle(string colour, string name, double width, double height)
			: Shape(colour, name)
		{
			width__  = width;
			height__ = height;
		}

		void setWidth(double width) 	{ width__  = width;  }
		void setHeight(double height) { height__ = height; }

		/* Overriding virtual functions from abstract base class */
		string getColour() const override { return colour__; }
		string getName() const { return name__; }
		double getArea() const override { return width__ * height__; }

		double getWidth() const  { return width__;  }
		double getHeight() const { return height__; }

	private:
		double width__;
		double height__;


   
};

#endif /* rectangle_hpp */
