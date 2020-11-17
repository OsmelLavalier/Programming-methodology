//
//  p_queue.h
//  Laboratory 3
//
//  Created by Osmel Lavalier Martin on 2020-11-16.
//

#ifndef p_queue_h
#define p_queue_h

#include<bits/stdc++.h>

#include "node_.h"

template<typename T, typename T2>
class p_queue
{
private:
   node_* front__, *rear__;
   
public:
   p_queue(): front__(nullptr), rear__(nullptr) {}
   
   void push(std::string name_, int price_)
   {
      node_* temp_node, * new_node = new node_;
      
      new_node->name__ = name_;
      new_node->price__ = price_;
      
      if(front__ == nullptr || price_ < front__->price__)
      {
         new_node->next__ = front__;
         front__ = new_node;
      }
      else
      {
         temp_node = front__;
         while(temp_node->next__ != nullptr && temp_node->price__ <= price_)
         {
            temp_node = temp_node->next__;
            
         }
         new_node->next__ = temp_node->next__;
         temp_node->next__ = new_node;
      }
   }
   
   node_* pop()
   {
      node_* node_to_delete;
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
      size_t sz = 1;
      node_* t_front = front__;
      while(t_front->next__ != nullptr)
      {
         sz++;
         t_front = t_front->next__;
      }
      return sz;
   }

   
   void display_queue()
   {
      if(empty())
      {
         puts("Queue is empty.");
         exit(0);
      }
      
      else
      {
         node_* t_front = front__;
         
         while(t_front != nullptr)
         {
            std::cout << t_front->name__ << " " << t_front->price__ << "\n";
            t_front = t_front->next__;
         }
      }
   }
   
   
   ~p_queue()
   {
      free(front__);
   }
   
};

#endif /* p_queue_h */
