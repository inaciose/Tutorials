#include <iostream>
#include <vector>
#include "Sandbox.hpp"
#include <ctime>

#include <iostream>
#include <string.h>

/*
When you access an array index, C and C++ don't do bound checking. Segmentation faults only happen when you try to read or write to a page that was not allocated
(or try to do something on a page which isn't permitted, e.g. trying to write to a read-only page), but since pages are usually pretty big
(multiples of a few kilobytes; on Mac OS, multiples of 4 KB), it often leaves you with lots of room to overflow.

If your array is on the stack (like yours), it can be even worse as the stack is usually pretty large (up to several megabytes).
 This is also the cause of security concerns: writing past the bounds of an array on the stack may overwrite the return address of the function
and lead to arbitrary code execution (the famous "buffer overflow" security breaches).

*/
int main ( int argc, char *argv[] )
{
	
    char x[2];
    for(int i=0;i<100000000;i++)
    {
        std::cout<<"i is: "<<i <<std::endl;
        std::cout<< x[i] <<std::endl;
    }
    return 0;
    
}

