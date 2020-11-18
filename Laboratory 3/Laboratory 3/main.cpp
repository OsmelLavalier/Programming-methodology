#include "p_queue.h"



void transactions(p_queue<orders, cmp> sales, p_queue<orders, cmp> buys)
{
    std::cout << "Transactions output:\n";
    for (int i = 0; i < sales.size(); i++)
    {
        if (sales[i]->price__ < buys[i]->price__ && sales[i]->name__ != buys[i]->name__)
        {
            std::cout << "Sale done:\n";
            std::cout << "Seller's name" << "\t\t" << "Buyer's name:" << "\t\t" << "Price:\n";
            std::cout << sales[i]->name__ << "\t\t" << buys[i]->name__ << "\t\t" << sales[i]->price__ << std::endl;
            std::cout << "\n";
        }
        else buys.pop();
    } 
}

using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;


int main()
{
    random_device device{};
    mt19937 engine{ device() };
   

    p_queue<orders, cmp> sell_orders;
    p_queue<orders, cmp> buy_orders;

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
            buy_orders.push(traders[index[2]], rand_price(engine));
        }
        else if (index[0] == '1')
        {
            sell_orders.push(traders[index[2]], rand_price(engine));
        }
    }

    //sell_orders.display_queue();

    //transactions(sell_orders, buy_orders);


    cmp comp;

    std::cout << comp(5, 3) << std::endl;

}