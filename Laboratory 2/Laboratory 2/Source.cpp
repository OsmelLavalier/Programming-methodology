#include "Round_Rectangle.h"
#include "Parallelepiped.h"
#include "Circle.h"
#include "Cylinder.h"

using std::cout;
using std::endl;

#define PI 3.141592653589793238463

int main()
{
    Rectangle r("rectangle", "purple", 2, 4);
    cout << r.getName() << ", " << r.getColour() << ", " << r.getArea() << endl;

    Round_Rectangle rr("rounded rectangle", "green", 6, 4, 1, PI);
    cout << rr.getName() << ", " << rr.getColour() << ", " << rr.getArea() << endl;

    Parallelepiped pp("parallelepiped", "grey", 1, 2, 2);
    cout << pp.getName() << ", " << pp.getColour() << ", " << pp.getArea() << endl;

    Circle c("circle", "cyan", 2, PI);
    cout << c.getName() << ", " << c.getColour() << ", " << c.getArea() << endl;

    Cylinder cc("cylinder", "yellow", 2, PI, 5);
    cout << cc.getName() << ", " << cc.getColour() << ", " << cc.getArea() << endl;
}
