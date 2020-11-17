//
//  sell_order.h
//  Laboratory 3
//
//  Created by Osmel Lavalier Martin on 2020-11-16.
//

#ifndef sell_order_h
#define sell_order_h

#include<random>


using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;

class sell_order
{
private:
   random_device device{};
   mt19937 engine{ device() };

public:
   sell_order();
   
   int return_random_price();
   void generate_sell_orders();
   
};

#endif /* sell_order_h */
