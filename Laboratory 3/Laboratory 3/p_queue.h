//
//  p_queue.h
//  Laboratory 3
//
//  Created by Osmel Lavalier Martin on 2020-11-16.
//

#ifndef p_queue_h
#define p_queue_h

#include<iostream>
#include<random>
#include<chrono>
#include<string>
#include<map>
#include<utility>

#include "node_.h"

class cmp
{
public:
    bool operator()(int i, int j)
    {
        return i < j;
    }
};


template<typename T, class T2>
class p_queue
{
private:
    T* front__;
   
public:
   p_queue(): front__(nullptr) {}
   
   void push(T order)
   {
       T* temp_node = new T, *new_node = new T(order.name__, order.price__);

      temp_node->name__ = order.name__;
      temp_node->price__ = order.price__;

      T2 compare_orders;

      if(front__ == nullptr || compare_orders(order.price__, front__->price__))
      {
         new_node->next__ = front__;
         front__ = new_node;
      }
      else
      {
         temp_node = front__;
         while(temp_node->next__ != nullptr && compare_orders(temp_node->next__->price__, order.price__))
         {
            temp_node = temp_node->next__;
            
         }
         new_node->next__ = temp_node->next__;
         temp_node->next__ = new_node;
      }
   }
   
   T* pop()
   {
      T* node_to_delete;
      if(empty())
      {
         puts("Queue is empty, nothing to delete.");
         exit(0);
      }
      
      node_to_delete = front__;
      front__ = front__->next__; //  connect the top of the queue to the rest
      
      return node_to_delete;
   }
   
   bool empty() { return front__ == nullptr; }
   
   std::size_t size()
   {
      size_t sz = 0;
      T* t_front = front__;
      while(t_front->next__ != nullptr)
      {
         sz++;
         t_front = t_front->next__;
      }
      return sz;
   }

   
   void display_queue()
   {
       if (empty())
       {
           puts("Queue is empty.");
           exit(0);
       }

       else
       {
           T* t_front = front__;

           while (t_front != nullptr)
           {
               std::cout << t_front->name__ << " " << t_front->price__ << "\n";
               t_front = t_front->next__;
           }
       }
   }
   
   T* operator[](int index)
   {
       int counter = 0;
       T* tmp = front__;

       while (tmp->next__ != nullptr)
       {
           if (counter == index)
           {
               return tmp;
           }
           counter++;
           tmp = tmp->next__;
       }
       return tmp;
   }

};

#endif /* p_queue_h */
