#ifndef int_buffer_h
#define int_buffer_h

#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<algorithm>
#include<cassert>
#include<random>
#include<fstream>


class int_buffer
{
public:
   
    explicit int_buffer(size_t size); // size_t is defined in cstdlib
    int_buffer(const int* source, size_t size);
    int_buffer(const int_buffer& rhs); // copy construct
    int_buffer(int_buffer&& rhs) noexcept; // move construct

    friend void swap(int_buffer& this_, int_buffer& other_); // copy and swap idom
    
    int_buffer& operator =(const int_buffer& rhs); // copy assign
    int_buffer& operator =(int_buffer&& rhs) noexcept; // move assign
    int& operator [](size_t index);
    const int& operator [](size_t index) const;
   
    size_t size() const;
    
    int* begin() noexcept;
    int* end() noexcept;
    
    const int* begin() const;
    const int* end() const;
    
    ~int_buffer();
private:
    int* data_;
    size_t size_;

    friend class int_sorted;
};


#endif // !int_buffer_h