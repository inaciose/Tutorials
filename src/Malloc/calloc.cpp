/*
 * calloc.cpp
 *
 *  Created on: May 17, 2012
 *      Author: behnam
 */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int callocmain()
{
	//Allocates memory for an array of num objects of size size and zero-initializes it.
	int NumberofElementofArray=10;
	int * x=(int *)calloc(NumberofElementofArray,4 * sizeof(int));
	if(x==NULL)
	{
		exit(1);
	}
	free(x);
	return 0;
}


