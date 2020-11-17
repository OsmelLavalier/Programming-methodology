//
//  node_.h
//  Laboratory 3
//
//  Created by Osmel Lavalier Martin on 2020-11-15.
//

#ifndef node__h
#define node__h


class node_
{
public:
   std::string name__;
   int price__; // this will serve as the priority for each node. low price = HIGH PRIORITY, high price = LOW PRIORITY
   
   node_* next__;
   
   node_() {}
};

#endif /* node__h */
