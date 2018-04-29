/*
 * realloc.cpp
 *
 *  Created on: May 17, 2012
 *      Author: behnam
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int reallocmain()
{
	int * x=(int *)malloc(4 * sizeof(int));
	if(x==NULL)
	{
		exit(1);
	}
	x[0]=12;
	x[1]=2;
	x[2]=4;
	x[3]=6;
	x=(int *)realloc(x,2 * sizeof(int));
	x[4]=14;
	x[5]=61;
	for(int i=0;i<100;i++)
	{
		cout<<x[i] <<endl;
	}
	free(x);
	return 0;
}



