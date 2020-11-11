#include "Round_Rectangle.h"
#include "Parallelepiped.h"

using std::cout;
using std::endl;


int main()
{
    Rectangle r("rectangle", "purple", 2, 4);
    cout << r.getName() << ", " << r.getColour() << ", " << r.getArea() << endl;

    Round_Rectangle rr("rounded rectangle", "green", 6, 4, 1, 3.14);
    cout << rr.getName() << ", " << rr.getColour() << ", " << rr.getArea() << endl;

    Parallelepiped pp("parallelepiped", "grey", 1, 2, 2);
    cout << pp.getName() << ", " << pp.getColour() << ", " << pp.getArea() << endl;

}
