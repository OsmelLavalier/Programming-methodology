#include "int_sorted.h"

 int_buffer bar(int_buffer&& buff) {
     return buff;
}

int_buffer foo(const int_buffer& buff) {
    return buff;
}

void f(int_buffer buf) {
    for (int* i = buf.begin(); i != buf.end(); i++)
        buf[*i] = ++buf[*i];
    for (int* i = buf.begin(); i != buf.end(); i++)
        std::cout << *i << std::endl;
}

void generate_value(int_buffer& buffer)
{
    using std::mt19937;
    using std::random_device;
    using std::uniform_int_distribution;

    random_device device{};
    mt19937 engine{ device() };

    uniform_int_distribution<int> dist(1, 1000);

    long long mod = 10e9 + 7;

    for (int* i = buffer.begin(); i != buffer.end(); i++)
        *i = dist(engine) % mod;
}

void print_buffer(int_buffer const buffer)
{
    for (const int* i = buffer.begin(); i != buffer.end(); i++)
        std::cout << *i << std::endl;
}


int main() 
{
    //1
    f(int_buffer(10));

    //2
    int_buffer buffer(10);
    generate_value(buffer);
    int_sorted is_(buffer.begin(), buffer.size());
    int_sorted is_2(buffer.begin(), buffer.size());

    is_2 = is_2.merge(is_);
    print_buffer(is_2.get_buffer());
   
   std::sort(buffer.begin(), buffer.end());
   


    return 0;
}
