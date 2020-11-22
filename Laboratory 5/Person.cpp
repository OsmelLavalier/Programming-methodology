#include "Person.h"

Person::Person(std::string name, double age): name__(name), age__(age) {}

bool operator==(const Person& lhs, const Person& rhs)
{
    return lhs.name__ == rhs.name__;
}

std::ostream& operator<<(std::ostream& out, const Person& person)
{
    out << person.name__ << " " << person.age__ << "\n";
    return out;
}

std::string Person::get_name() { return name__; }
double Person::get_age() { return age__; }
