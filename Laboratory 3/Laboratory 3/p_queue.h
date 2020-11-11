#ifndef p_queue_h
#define p_queue_h

#include "linked_list.h"

template<typename T>
class p_queue
{
private:

public:
    p_queue(T size, );

    T pop();
    void push(T v_);

    bool empty();


};

#endif

