#include "int_buffer.h"


int_buffer::int_buffer(size_t size)
    : data_(size ? new int[size]() : nullptr), size_(size) 
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

int_buffer::int_buffer(const int_buffer& rhs) 
{
    this->data_ = rhs.size_ ? new int[rhs.size_]() : nullptr;
    this->size_ = rhs.size_;   

    using std::copy;
    copy(rhs.data_, rhs.data_ + rhs.size_, this->data_);

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
    this->data_ = rhs.size_ ? new int[rhs.size_]() : nullptr;
    this->size_ = rhs.size_;
    
    int_buffer dummy(rhs);
    swap(*this, dummy);

    return *this;
}

int_buffer& int_buffer::operator=(int_buffer&& rhs) noexcept
{
    std::cout << "Move Assign Operator" << std::endl;
    
    this->data_ = rhs.data_;
    this->size_ = rhs.size_;

    rhs.data_ = nullptr;
    rhs.size_ = 0;

    return *this;
}

int& int_buffer::operator[](size_t index) 
{
    static int outBounds = -1;
    if(index >= 0 && index < size_) 
        return data_[index];
    else
        std::clog << "Index out of bounds." << std::endl;
    return outBounds;
}

const int& int_buffer::operator[](size_t index) const
{
    static int outBounds = -1;
    if (index >= 0 && index < size_)
        return data_[index];
    else
        std::clog << "Index out of bounds." << std::endl;
    return outBounds;
}

size_t int_buffer::size() const { return size_; }
int* int_buffer::begin() noexcept { return data_; }
int* int_buffer::end() noexcept { return data_ + size_; }
const int* int_buffer::begin() const { return data_; }
const int* int_buffer::end() const { return data_ + size_; }


int_buffer::~int_buffer()
{
    size_ = 0;
    delete []data_; 
}
    





