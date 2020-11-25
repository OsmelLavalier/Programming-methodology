#ifndef int_sorted_h
#define int_sorted_h

#include "int_buffer.h"

class int_sorted
{
public:
    int_sorted(const int* source, size_t size);

    size_t size() const;

    int* insert(int value); //returns the insertion point
    const int* begin() const;
    const int* end() const;

    int_sorted sort(const int* begin, const int* end);
    int_sorted merge(const int_sorted& merge_with) const;

    int_buffer get_buffer() const;

    void generate_value();
    void print_buffer();
   
   int_buffer get_simon()
   {
      return simon;
   }

private:
    int_buffer buffer;
   int_buffer simon;
};

#endif
