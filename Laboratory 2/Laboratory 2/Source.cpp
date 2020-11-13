#include "Round_Rectangle.h"
#include "Parallelepiped.h"
#include "Cylinder.h"

using std::cout;
using std::endl;
using std::vector;


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
        new Round_Rectangle("Rounded Rectangle", "green", 6, 4, 1),
        new Parallelepiped("Parallelepiped", "grey", 1, 2, 2),
        new Circle("Circle", "cyan", 2),
        new Cylinder("Cylinder", "yellow", 2, 5)
    };

    GetData(shapes, 5);

    return 0;
}
