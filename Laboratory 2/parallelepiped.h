//
//  parallelepiped.h
//  Laboratory 2
//
//  Created by Osmel Lavalier Martin on 2020-11-10.
//

#ifndef parallelepiped_h
#define parallelepiped_h

#include "rectangle.hpp"

class Parallelepiped : public Rectangle
{
public:
   
   Rectangle *getType() override
   {
      return 
   }
   
   
   int getArea() const override
   {
      return 2;
   }
   
   string getColour() override
   {
      return "grey";
   }
   
   
   
};


#endif /* parallelepiped_h */
