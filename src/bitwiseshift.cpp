/*
 * bitwiseshift.cpp
 *
 *  Created on: Sep 7, 2012
 *      Author: behnam
 */

#include <iostream>

using namespace std;


int MultiplyByPowerof2(int number, int power)
{
//	[variable]<<[number of places]
	return number<<power;
}

//int main (int arcg, const char ** argv)
int bitwiseshiftmain (int arcg, const char ** argv)

{

	int number=3;
	int power=3;
	cout <<MultiplyByPowerof2( number, power)<<endl;
	return 0;
}


