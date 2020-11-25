#include "MyClass.h"
#include "FirstOf.h"
#include "MyBinOp.h"
#include "MyUnOp.h"


#define size_of_array 9

int main()
{
	//  initialize an array of fixed size of our design Person class
	Person arr_persons[size_of_array] = {
		Person("Timmy Nord", 20),
		Person("Jens Johansson", 22),
		Person("Dan Sjöström", 29),
		Person("Viktor Ericsson", 24),
		Person("Joakim Söderlund", 25),
		Person("Joakim Söderlund", 25),

		/* Predefined subsequence */
		Person("Simon Nalin", 28),
		Person("Tom Fire", 22),
		Person("Jerry Ball", 22)

	};

	//  copy the contents of our array of Persons with the help of vector parameterized constructor
	std::vector<Person> vec_persons(arr_persons, arr_persons + size_of_array); 

	/* Further, implement the following steps */

	//  1
	std::for_each(vec_persons.begin(), vec_persons.end(), MyClass()); //  calling our functor

	//  2
	std::cout << "\nFind object grater than prediscribed person instans\n";
	auto it = std::find_if(vec_persons.begin(), vec_persons.end(), FirstOfObject("Adam Karlsson", 25));
	if(it == vec_persons.end()) 
		std::cout << "No such person exists..\n";
	else
		std::cout << "Person object found: " << *it;

	//  3
	std::cout << "\nAdjacent equal person object: \n";
	auto p_obj = std::adjacent_find(vec_persons.begin(), vec_persons.end());
	if(p_obj != vec_persons.end())
	{
		std::cout << "the first adjacent pair of equal elements at: " << std::distance(vec_persons.begin(), p_obj) << '\n';
		std::cout << *p_obj << std::endl;
	}
	else 
		std::cout << "No such object found.." << std::endl;
	
	//  4
	bool is_equal = std::equal(vec_persons.begin(), vec_persons.end(), arr_persons);
	if(is_equal) puts("Array and vector are equals");
	else puts("Not equal");

	//  5
	std::cout << "\nSubsequence found: \n";
	auto subcequence_found = std::search(vec_persons.begin(), vec_persons.end(), arr_persons+6, arr_persons+size_of_array);
	if(subcequence_found == vec_persons.end())
		std::cout << "No such predefined subsequence was found!!\n";
	else
	{
		while(subcequence_found != vec_persons.end())
		{

			std::cout << *subcequence_found;
			subcequence_found++;
		}
	}

	//  6
	std::cout << "\nThe avarage of vector using std::accumulate is: \n";
	double sum = std::accumulate(vec_persons.begin(), vec_persons.end(), 0.0, MyBinOp());
	double mean = sum / vec_persons.size();
	std::cout << mean << std::endl;

	//  7
	std::cout << "\nUsing std::transform to get the ages from our original vector to v2 vector\n";
	std::vector<double> v2(vec_persons.size());
	std::transform(vec_persons.begin(), vec_persons.end(), v2.begin(), MyUnOp());
	for(int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}

	//  8
	std::cout << "\nReplace all old values xi of the vector v2 with the new ones yi = xi - m, where m is the mean value calculated at the step 6.\n";
	
	std::transform(v2.begin(), v2.end(), v2.begin(), MyUnOp(mean));
	for(int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}
	
	//  9
	std::cout << "\nSorting our new values of v2 with std::sort()\n";
	std::sort(v2.begin(), v2.end());
	for(auto value : v2)
		std::cout << value << std::endl;
}
