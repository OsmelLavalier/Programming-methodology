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

    int_sorted obj(nullptr, 0);
    obj.buffer = dummy;
    return obj;
}

int_buffer int_sorted::get_buffer() const
{
    return buffer;
}

void int_sorted::generate_value()
{
    using std::mt19937;
    using std::random_device;
    using std::uniform_int_distribution;

    random_device device{};
    mt19937 engine{ device() };

    uniform_int_distribution<int> dist(1, 5);

    for (int i = 0; i < buffer.size_; i++)
        buffer.data_[i] = dist(engine);
}

void int_sorted::print_buffer()
{
    for (const int* i = buffer.begin(); i != buffer.end(); i++)
        std::cout << *i << std::endl;
}





