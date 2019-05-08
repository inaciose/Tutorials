/*
 * Timers.cpp
 *
 *  Created on: Oct 31, 2012
 *      Author: behnam
 */


#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

//int main()
int main()
{
/*  get start time  */
    time_t  start_time = clock();
/*code to measure*/
	for(int i=0;i<1000000;i++)
	{
/*		i*i;
		i*i;
		i*i;
		i*i;
		i*i;*/
		cout<<i*i<<endl;
//		cout<<i*i<<endl;
	}
    float time1 = (float) (clock() - start_time) / CLOCKS_PER_SEC;
    printf("time for code was %f seconds\n", time1);
    return 0;
}

