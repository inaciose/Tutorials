/*
 * Namespaces.cpp
 *
 *  Created on: Jan 5, 2012
 *      Author: behnam
 */
#include <iostream>
#include "foo.h"
#include "goo.h"

/*
All the files in the C++ standard library declare all of its entities within the std namespace.
That is why we have generally included the using namespace std; statement in all programs that
used any entity defined in iostream.
 */

namespace first
{
  int var = 5;
}

namespace second
{
  double var = 3.1416;
}

using namespace std;

//Namespacesmain()
int Namespacesmain()
{
	cout << first::var << endl;
	cout << second::var << endl;

	cout<< foo::DoSomething(10,12)<<endl;
	cout<< goo::DoSomething(10,12)<<endl;
	return 0;

}



