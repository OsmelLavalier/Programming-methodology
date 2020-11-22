#include "p_queue.h"

using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;

void add_order_to_queue(p_queue<orders, cmp>& sell_orders, p_queue<orders, cmp>& buy_orders)
{
    random_device device{};
    mt19937 engine{ device() };

    std::map<std::string, int> persons;
    std::map<std::string, int>::iterator it;

    std::map<char, std::string> traders;
    traders['0'] = "Erik Pendel";
    traders['1'] = "Jarl Wallenberg";
    traders['2'] = "Joakim von Anka";

    std::string index = "";
    uniform_int_distribution<int> rand_price(15, 30);
    uniform_int_distribution<int> dist(0, 41);

    for (int i = 1; i < 42; i++)
    {

        while (true)
        {

            int random = dist(engine);
            index = std::to_string(random % 2) + "_" + std::to_string(random % 3);
            it = persons.find(index);

            if (it == persons.end())
            {
                persons.insert(std::pair<std::string, int>(index, 1));
                break;
            }
            else if (persons[index] == 7)
            {
                continue;
            }
            else
            {
                persons[index] += 1;
                break;
            }
        }

        if (index[0] == '0')
        {
            orders buyers(traders[index[2]], rand_price(engine));
            buy_orders.push(buyers);
        }
        else if (index[0] == '1')
        {
            orders sellers(traders[index[2]], rand_price(engine));
            sell_orders.push(sellers);
        }
    }
}

void transactions(p_queue<orders, cmp> sales, p_queue<orders, cmp> buys)
{
    std::cout << "Transactions output:\n";

    while (!sales.empty())
    {
        auto sellers = sales.pop();
        auto buyers = buys.pop();

        if (sellers->price__ < buyers->price__ && sellers->name__ != buyers->name__)
        {
            std::cout << "Seller's name" << "\t\t" << "Buyer's name:" << "\t\t" << "Price:\n";
            std::cout << sellers->name__ << "\t\t" << buyers->name__ << "\t\t" << sellers->price__ << std::endl;
            std::cout << "\n";
        }
        else buys.pop();
    }
}

int main()
{
    
    p_queue<orders, cmp> sell_orders;
    p_queue<orders, cmp> buy_orders;

    add_order_to_queue(sell_orders, buy_orders);
    transactions(sell_orders, buy_orders);
}