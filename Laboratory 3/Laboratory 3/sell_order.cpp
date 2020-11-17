//
//  sell_order.cpp
//  Laboratory 3
//
//  Created by Osmel Lavalier Martin on 2020-11-16.
//

#include "sell_order.h"

sell_order::sell_order() {}


int sell_order::return_random_price()
{
   uniform_int_distribution<int> dist(15, 35);
   return dist(engine);
}

void sell_order::generate_sell_orders()
{
   
}
