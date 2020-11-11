#ifndef linked_list
#define linked_list

template<typename T>
class node_
{
private:
    T value__;
    T* head__;
    T* tail__;
public:
    node_(T v_, T* h_ = nullptr, T* t_ = nullptr);
};

template<class T>
class linked_list
{
public:
    linked_list(T& node_);
};

#endif

template<class T>
inline linked_list<T>::linked_list(T& node_)
{
}
