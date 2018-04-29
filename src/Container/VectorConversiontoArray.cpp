/*
 * VectorConversiontoArray.cpp
 *
 *  Created on: May 12, 2012
 *      Author: behnam
 */



#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <string.h>// memcpy
#include <stdlib.h>//realloc
using namespace std;

int main()
{
	//vectors store their elements contiguously:
	//vector to array
	std::vector<double> v;
	double* a = &v[0];
	
	
	//array to vector
	int x[] = { 1, 2, 3, 4, 5 };
	std::vector<int> vec1(std::begin(x), std::end(x));
	std::vector<int> vec2(x, x + sizeof x / sizeof x[0]);
	std::cout<<vec1.size()<<std::endl;
	std::cout<<vec2.size()<<std::endl;
	
	
// 	int *x = new int [5];	
	vector<int> myVector;
	int myArray[5];
	memcpy( myArray, &myVector[0], sizeof( int ) * myVector.size() );
	//std::copy<>()
}



