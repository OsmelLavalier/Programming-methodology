#ifndef Person_h
#define Person_h

/* Necessary Headers */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>

class Person
{
    private:
    std::string name__;
    double age__;
	
    public:
    Person(std::string name, double age);

    friend bool operator==(const Person& lhs, const Person& rhs); 
	friend std::ostream& operator<<(std::ostream& out, const Person& person);

	 /* Getters */
	 std::string get_name();
	 double get_age();

     friend class FirstOfObject;
};


#endif
