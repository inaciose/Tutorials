/*
 * Typedef.cpp
 *
 *  Created on: Jan 7, 2012
 *      Author: behnam
 */

/*
typedef int km_per_hour ;
typedef int points ;

km_per_hour current_speed ;
points high_score ;


void congratulate(points your_score) {
    if (your_score > high_score)

The declaration in congratulate() of your_score indicates to the programmer that current_speed
(or any other variable not declared as a points) should not be passed as an argument.
This would not be as apparent if both were declared as ints.

*/




#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int Typedefmain()
{

//	vector<pair<string, int> > values;
//	for (vector<pair<string, int> >::const_iterator i = values.begin(); i != values.end(); ++i)
//	{
//	   pair<std::string, int> const & t = *i;
//	   // do something
//	}

	typedef pair<string, int> value_t;
	typedef vector<value_t> values_t;

	values_t values;
	for (values_t::const_iterator i = values.begin(); i != values.end(); ++i)
	{
	   value_t const & t = *i;
	   // do something
	}



	return 0;
}



