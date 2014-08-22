/*
 * DynamicallyAllocatiopn.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */
#include <iostream>
using namespace std;

int DynamicallyAllocatiopnmain()
{
//	To allocate a single variable dynamically, we use the scalar (non-array) form of the new operator:
//	The new operator returns the address of the variable that has been allocated.
	int *pnValue = new int;
//	When we are done with a dynamically allocated variable, we need to explicitly tell C++ to free the memory for reuse.
	delete pnValue;
//	Note that the delete operator does not delete the pointer — it deletes the memory that the pointer points to!
	pnValue = 0;


//	int nSize = 12;
	int nSize;
	cin>>nSize;
	int *pnArray = new int[nSize]; // note: nSize does not need to be constant!
	pnArray[4] = 7;
	cout<<pnArray[4]<<endl;
//	delete[] pnArray;



}



