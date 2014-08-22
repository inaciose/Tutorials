/*
 * FloatPrecision.cpp
 *
 *  Created on: Mar 6, 2012
 *      Author: behnam
 */
#include <iostream>
#include <limits> 



using namespace std;
int FloatPrecisionmain()
//int main()
{

    double a,b,c;
    a = 3.1415926534;
    b = 2006.0;
    c = 1.0e-10;

    cout       <<         a << '\t' << b << '\t' << c << endl;
    cout <<   fixed    << a << '\t' << b << '\t' << c << endl;
    cout << scientific << a << '\t' << b << '\t' << c << endl;
    return 0;

    cout << "The difference between 1 and the smallest "   << "value greater than 1\n for float objects is: "   << numeric_limits<float>::epsilon( )     << endl;
    cout << "The difference between 1 and the smallest "     << "value greater than 1\n for double objects is: "   << numeric_limits<double>::epsilon()  << endl;
    cout << "The difference between 1 and the smallest "   << "value greater than 1\n for long double objects is: "  << numeric_limits<long double>::epsilon( ) << endl;
}

