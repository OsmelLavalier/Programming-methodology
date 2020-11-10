#include "int_sorted.h"

int_sorted::int_sorted(const int* source, size_t size): buffer(nullptr, 0) {
    if (size > 1)
        buffer = sort(source, source + size).buffer;
    else
        buffer = int_buffer(source, size);
}

size_t int_sorted::size() const { return buffer.size(); }

int* int_sorted::insert(int value)
{
    int_sorted obj(&value, 1);
    *this = merge(obj);

    using std::find;
    return find(buffer.begin(), buffer.end(), value);
}

const int* int_sorted::begin() const
{
    return this->buffer.data_;
}

const int* int_sorted::end() const
{
    return this->buffer.data_ + this->buffer.size_;
}

int_sorted int_sorted::sort(const int* begin, const int* end)
{
    if (begin == end)
        return int_sorted(nullptr, 0);
    if (begin == end - 1)
        return int_sorted(begin, 1);

    using std::ptrdiff_t;
    ptrdiff_t half = (end - begin) / 2;

    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
    // create a tmp buffer
    int_buffer dummy(size() + merge_with.size());

    const int* this_ = begin(); //set our pos
    const int* other_ = merge_with.begin(); //set the pos of object to merge with 

    int* dummy_ = dummy.begin();
    
    // loop as long as both buffers not reached the end
    while (this_ != buffer.end() && other_ != merge_with.end())
    {
        if (*this_ < *other_) 
        {
            *dummy_ = *this_;
            dummy_++;
            this_++;
        } 
        else
        {
            *dummy_ = *other_;
            dummy_++;
            other_++;
        }
    }

    while (this_ != buffer.end())
    {
        *dummy_ = *this_;
        dummy_++;
        this_++;
    }

    while (other_ != merge_with.end())
    {
        *dummy_ = *other_;
        dummy_++;
        other_++;
    }

    int_sorted result(nullptr, 0);
    result.buffer = dummy;
    return result;
}

int_buffer int_sorted::get_buffer() const
{
    return buffer;
}


