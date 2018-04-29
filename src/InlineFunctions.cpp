/*
 * InlineFunctions.cpp
 *
 *  Created on: Jan 5, 2012
 *      Author: behnam
 */


#include <iostream>
using namespace std;

inline int min(int x,int y)
{
	return x<y ? x: y;
}
//InlineFunctions

int InlineFunctionsmain()
{
	cout<<min(10,12) <<endl;
}


