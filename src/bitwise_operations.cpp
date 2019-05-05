/*
 * bitwiseshift.cpp
 *
 *  Created on: Sep 7, 2012
 *      Author: behnam
 */

#include <iostream>




int bitwiseshiftPOW2(int number=2,int power=5)
{
//	[variable]<<[number of places to shift]
    
    int result=number<<(power-1);
	std::cout <<result<<std::endl;
}

void evenOdd(int num=6)
{
    int result=num&1;
    std::cout<<num << (result ? " is odd":" is even")<<std::endl;
}

int main()
{
     //bitwiseshiftPOW2();
     //evenOdd(8);
    int a,b, result;
    a=13;//1101
    b=2;
    result=(a>>b);//11
    std::cout <<result<<std::endl;
    
    
}

