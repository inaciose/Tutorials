/*
 * FunctionTemplateOverloading.cpp
 *
 *  Created on: Jun 14, 2012
 *      Author: behnam
 */
#include <iostream>

using namespace std;

template < class T >
void Print(const T t1)
{
	cout << t1 << endl;
}


template < class T >
void Print(const T t1, const T t2)
{
	cout << t1 << t2 << endl;
}

template < class T >
void Print(const T t1, const T t2, const T t3)
{
	cout << t1 << t2 << t3 << endl;
}


int FunctionTemplateOverloadingmain()
//int main ()
{
	//you can call the function with or without angle brackets or type specification:


	Print(4.f); // prints one float

	Print<>(23, 37); // prints two integers

	Print< char >('c', 'o', 'm'); // prints three chars


	return 0;
}


