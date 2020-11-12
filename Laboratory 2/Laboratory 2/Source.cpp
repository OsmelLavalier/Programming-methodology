#include "Round_Rectangle.h"
#include "Parallelepiped.h"
#include "Circle.h"
#include "Cylinder.h"

using std::cout;
using std::endl;
using std::vector;


#define PI 3.141592653589793238463

void GetData(vector<Shape*>& shapes, size_t size)
{
    for (auto* type : shapes)
    {
        cout << "Name: " << type->getName() << ", Colour: " << type->getColour() << ", Area: " << type->getArea() << endl;
    }

}

int main()
{
    vector<Shape*> shapes {
        new Rectangle("Rectangle", "purple", 2, 4),
        new Round_Rectangle("Rounded Rectangle", "green", 6, 4, 1, PI),
        new Parallelepiped("Parallelepiped", "grey", 1, 2, 2),
        new Circle("Circle", "cyan", 2, PI),
        new Cylinder("Cylinder", "yellow", 2, PI, 5)
    };

    GetData(shapes, 5);
}
