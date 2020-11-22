#ifndef MyBinOp_h
#define MyBinOp_h

#include "Person.h"


class MyBinOp
{
	public:
	double operator()(double i, Person& curr_person)
	{
		return i + curr_person.get_age();
	}
	
};

#endif
