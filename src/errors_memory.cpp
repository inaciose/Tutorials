/*
 *
 *  Created on: Jan 6, 2012
 *      Author: behnam
 */

#include <iostream>
#include <cstdlib>// for  exit()
#include <cassert> // for assert()
#include <memory>
#include <string.h>

/*
1)Syntax errors:

A syntax error occurs when you write a statement that is not valid according to the grammar of the C++ language.
For example:
if 5 > 6 then write "not equal";

if (5 > 6)
    std::cout << "not equal";


2)Semantic errors:

A semantic error occurs when a statement is syntactically valid, but does not do what the programmer intended. For example:

for (int nCount=0; nCount<=3; nCount++)
    std::cout << nCount << " ";

The programmer may have intended this statement to print 0 1 2, but it actually prints 0 1 2 3.
*/

void exitExample()
{
	// Delcare an array of 10 integers
	int *panData = new int[10];
	// If the user runs out of memory. If that happens, panData will be set to NULL, and !!panData will be true,
	if (!panData)
	    exit(2); // exit the program with error code 2
	panData[5] = 3;
}

/*
    An assert statement is a preprocessor macro that evaluates a conditional expression.
    If the conditional expression is true, the assert statement does nothing.
    assert will terminate the program (usually with a message quoting the assert statement) if its argument turns out
    to be false. It's commonly used during debugging to make the program fail more obviously if an unexpected condition occurs.

    When you're doing a release (non-debug) build, you can also remove the overhead of evaluating assert
    statements by defining the NDEBUG macro, usually with a compiler switch. The corollary of this is that
    your program  should never rely on the assert macro running.
*/

int assertExample()
{
    int nIndex=12;
    int g_anArray[10];
    // we're asserting that nIndex is between 0 and 9
    assert(nIndex >= 0 && nIndex <= 9); // this is line 7 in Test.cpp
    return g_anArray[nIndex];
}
/*
---------------------------------
|                               |  <-heap
|                               |
|               z               |
|                               |
|                               |
|                               |
|                               |
|-------------------------------|
|                               |  <-stack
|                               |
|-------------------------------|
|            func2()            |  <-stack frame3
|             a,b               |
|-------------------------------|
|            func1()            |  <-stack frame2
|            a,b                |
|--------------------------------
|            main()             |  <-stack frame1
|             x,y               |
|                               |
|-------------------------------|
|             sum               | <- static/global vaiables
|-------------------------------|
|          code(Text)           |
|            main               |
|                               |
---------------------------------




heap:
    grow downward

The memory size for these three section is fixed and it is not growing
code:
    code of application

static/global vaiables:
    are avaiable during whole life cycle of application

stack:
    local variables/ function calls


*/


/*
When you access an array index, C and C++ don't do bound checking. Segmentation faults only happen when you try to
read or write to a page that was not allocated (or try to do something on a page which isn't permitted,
e.g. trying to write to a read-only page), but since pages are usually pretty big
(multiples of a few kilobytes), it often leaves you with lots of room to overflow.

If your array is on the stack, it can be even worse as the stack is usually pretty large (up to several megabytes).
 This is also the cause of security concerns: writing past the bounds of an array on the stack may overwrite the return address of the function
and lead to arbitrary code execution (the famous "buffer overflow" security breaches).

By setting the follwong flag you can find the issue:
set(CMAKE_CXX_FLAGS "-fsanitize=address ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-fno-omit-frame-pointer ${CMAKE_CXX_FLAGS}")


*/


void heapBufferOverflow()
{
    int *x=new int[3];
    for(int i=0;i<100000000;i++)
    {
        std::cout<<"i is: "<<i <<std::endl;
        std::cout<< x[i] <<std::endl;
    }
}

void stackBufferOverflow()
{
    char x[2];
    for(int i=0;i<100000000;i++)
    {
        std::cout<<"i is: "<<i <<std::endl;
        std::cout<< x[i] <<std::endl;
    }

//    Here is an example program that causes a stack overflow:
//    int nStack[100000000];

}

int main( int argc, char *argv[] )
{
    //assertExample();
    //stackBufferOverflow();
    //heapBufferOverflow();
}
