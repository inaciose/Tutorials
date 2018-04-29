/*
 * malloc.cpp
 *
 *  Created on: May 17, 2012
 *      Author: behnam
 */
//void * malloc ( size_t size );
//allocates the specified number of bytes, returning a pointer to the beginning of the block.

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int mallocmain()
{
	int * x=(int *)malloc(10 * sizeof(int));
	if(x==NULL)
	{
		exit(1);
	}
	x[0]=12;
	x[1]=2;
	x[2]=4;
	x[3]=6;
	x[4]=27;
	x[5]=9;
	x[6]=11;
	cout<<x[6] <<endl;
	free(x);
	return 0;
}


