/*
 * MaxMinValues.cpp
 *
 *  Created on: Jul 22, 2012
 *      Author: behnam
 */
//The maximum finite value is INT_MAX for type int and FLT_MAX for type float.

// numeric_limits_max.cpp
// compile with: /EHsc
#include <iostream>
#include <limits>

using namespace std;

int SizeofOperator()
//int main( )
{
   cout << "The maximum value for type float is:  "
        << numeric_limits<float>::max( )
        << endl;
   cout << "The maximum value for type double is:  "
        << numeric_limits<double>::max( )
        << endl;
   cout << "The maximum value for type float is:  "
        << numeric_limits<int>::max( )
        << endl;
   cout << "The maximum value for type short int is:  "
        << numeric_limits<short int>::max( )
        << endl;
}

