/*
 * Arrays.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */
#include <iostream>
using namespace std;

//Sending Arrays to functions

//void SendingArray(int *ArrayToPrint,int size)
void SendingArray(int ArrayToPrint[],int size)
{
	cout<<"Print Array, in this function we send the size of the array as well"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<ArrayToPrint[i]<<endl;
	}
}

void SendingArray(int ArrayToPrint[5])
{
	cout<<"Print Array, in This function we have defined the size of the passed array in function definition"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<ArrayToPrint[i]<<endl;
	}
}

void SendingMultidimensionalArray( int x, int y, int z ,int  ArrayToPrint[][3][2])
{
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			for(int k=0;k<z;k++)
			{
				cout<<"Row # "<<i <<endl;
				cout<<"Column # "<<j <<endl;
				cout<<"Vertex # "<<k <<endl;
				cout<<ArrayToPrint[i][j][k] <<endl;
			}
		}
	}
}

//Arraysmain
int Arraysmain()
{

	int FirstArray[] = { 1, 2, 3, 4, 5 };
	cout << "sizeof(FirstArray)="<<sizeof(FirstArray)<<endl; // prints 20 (5 elements * 4 bytes each)
	const int ArraySize = 5;


	cout<<"*FirstArray"<< *FirstArray<<endl;
	cout<<"*(FirstArray+2)"<< *(FirstArray+2)<<endl;

	//Iterators are similar to pointers
	cout<<"Iterators are similar to pointers"<<endl;
	for (int* p = FirstArray; p != FirstArray+ArraySize; p++)
	{
		//These are equal:
		//FirstArray=&FirstArray[0]
		//FirstArray+ArraySize=&FirstArray[ArraySize]
		cout << *p << endl;
	}


	int First2DArray[3][5] ={
	{ 1, 2, 3, 4, 5, }, // row 0
	{ 6, 7, 8, 9, 10, }, // row 1
	{ 11, 12, 13, 14, 15 } // row 2
	};

//	Two-dimensional arrays with initializer lists can omit (only) the first size dimension(the most left one):
//C does not have true multidimensional arrays. you can have arrays of arrays, so like
// FirstArray[] = { 1, 2, 3, 4, 5 }  which we didn't declare the dimension, we could have:
	int Second2DArray[][5] ={{ 1, 2, 3, 4, 5, },{ 6, 7, 8, 9, 10, },{ 11, 12, 13, 14, 15 }};


	SendingArray(FirstArray);
	SendingArray(FirstArray,5);
//	It can also be called:
//	SendingArray(&FirstArray[0],5);

	int Second3DArray[2][3][2] ={
			{{1, 2},{3, 4},{5, 6}},
			{{7, 8}, {9, 10}, {11, 12}}
	};
	//If you want to pass a multi-dimensional array to a function, the simplest way is to specify all of the array sizes
	//except the leftmost; e.g.,

	SendingMultidimensionalArray(2,3,2,Second3DArray);

	return 0;
}

/*differences between arrays and pointers
what you declare in a parameter list is treated special. There are such situations where things don't make sense as a function parameter in C. These are

1)Functions as parameters
2)Arrays as parameters

size of an array dimension is part of the type in C (and an array whose dimension size isn't given has an incomplete type).

*/




