//
//  sell_order.h
//  Laboratory 3
//
//  Created by Osmel Lavalier Martin on 2020-11-16.
//

#ifndef sell_order_h
#define sell_order_h

#include<string>

class orders
{
public:
    std::string name__;
    int price__;
    orders* next__;

    orders() {} 
    //orders(std::string name, int price): name__(name), price__(price) {}
};


#endif /* sell_order_h */
