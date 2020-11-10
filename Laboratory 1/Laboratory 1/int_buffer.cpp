#include "int_buffer.h"


int_buffer::int_buffer(size_t size) : data_(size ? new int[size]() : nullptr), size_(size)
{
    std::cout << "Default constructor" << std::endl;
}

int_buffer::int_buffer(const int* source, size_t size)
    : data_(size ? new int[size]() : nullptr), size_(size)
{
    std::cout << "Deep copy" << std::endl;

    using std::copy;
    copy(source, source + size, this->data_);
}

int_buffer::int_buffer(const int_buffer& rhs) : int_buffer(rhs.data_, rhs.size())
{
}

int_buffer::int_buffer(int_buffer&& rhs) noexcept 
    : data_(nullptr), size_(0)
{
    std::cout << "Move constructor" << std::endl;
    swap(rhs, *this); // swap copy idiom!
}

void swap(int_buffer& this_, int_buffer& other_)
{
    using std::swap;
    swap(this_.data_, other_.data_);
    swap(this_.size_, other_.size_);
}

int_buffer& int_buffer::operator=(const int_buffer& rhs)
{
    std::cout << "Equals Assign operator" << std::endl;
    
    int_buffer dummy(rhs);
    swap(*this, dummy);

    return *this;
}

int_buffer& int_buffer::operator=(int_buffer&& rhs) noexcept
{
    std::cout << "Move Assign Operator" << std::endl;
    
    swap(*this, rhs);

    return *this;
}

int& int_buffer::operator[](size_t index) 
{
   return data_[index];
}

const int& int_buffer::operator[](size_t index) const
{
   return data_[index];
}

size_t int_buffer::size() const { return size_; }
int* int_buffer::begin() noexcept { return data_; }
int* int_buffer::end() noexcept { return data_ + size_; }
const int* int_buffer::begin() const { return data_; }
const int* int_buffer::end() const { return data_ + size_; }


int_buffer::~int_buffer()
{
    delete []data_; 
}
    





