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
#include <cmath>
#include <bitset>
#include <vector>
#include <stdexcept>
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


struct Foo { virtual ~Foo() {} };
struct Bar { virtual ~Bar() {} };

/*
exception handling

try
{
    ...
}
catch (Exception e)
{
    throw e;
}
catch (...)//... will catch any exception
{
    throw;
}

====================================C++ Standard Exceptions============================================

std::exception

    1)std::bad_alloc
    2)std::bad_cast
    3)std::bad_exception
    4)std::bad_typeid
    5)std::logic_error
        5-1)std::domain_error: exception thrown when a mathematically invalid domain is used.
        5-2)std::invalid_argument
        5-3)std::length_error
        5-4)std::out_of_range
    6)std::runtime_error: An exception that theoretically cannot be detected by reading the code.
        6-1)std::overflow_error :
            The only standard library components that
            throw std::overflow_error are std::bitset::to_ulong and std::bitset::to_ullong.
        6-2)std::underflow_error
        6-3)std::range_error

*/

double division(int a, int b)
{
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}

struct S { // The type has to be polymorphic
    virtual void f();
};


void exceptionHandlingExample()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try
    {
        z = division(x, y);
        std::cout << z << std::endl;
    } catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }
}


void bad_allocExample()
{
    try
    {
        while (true)
    {
        new int[100000000ul];
    }
    } catch (const std::bad_alloc& e) {
        std::cout << "Allocation failed: " << e.what() << '\n';
    }
}


void bad_castExample()
{
    Bar b;
    try
    {
        Foo& f = dynamic_cast<Foo&>(b);
    } catch(const std::bad_cast& e)
    {
        std::cout << e.what() << '\n';
    }
}


void bad_typeidExample()
{
    Foo* p = nullptr;
    try
    {
        std::cout << typeid(*p).name() << '\n';
    } catch(const std::bad_typeid& e) {
        std::cout << e.what() << '\n';
    }
}


void logical_ErrorExample()
{
    int amount, available;
    amount=10;
    available=9;
    if(amount>available)
    {
        throw std::logic_error("Error");
    }

    //second exmple
    try
    {
      if(amount>available)
        throw std::logic_error( "logic error" );
    }
    catch ( std::exception &e )
    {
      std::cerr << "Caught: " << e.what( ) << std::endl;
      std::cerr << "Type: " << typeid( e ).name( ) << std::endl;
    };
}

void domain_errorExample()
{
    try
    {
        const double x = std::acos(2.0);
        std::cout << x << '\n';
    }
    catch (std::domain_error& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (...)
    {
        std::cout << "Something unexpected happened" << '\n';
    }

}

void invalid_argumentExample()
{
    try
    {
    // binary wrongly represented by char X
        std::bitset<32> bitset(std::string("0101001X01010110000"));
    }
    catch (std::exception &err)
    {
        std::cerr<<"Caught "<<err.what()<<std::endl;
        std::cerr<<"Type "<<typeid(err).name()<<std::endl;
    }
}

void length_errorExample()
{
    try
    {
        // vector throws a length_error if resized above max_size
        std::vector<int> myvector;
        myvector.resize(myvector.max_size()+1);
    }
    catch (const std::length_error& le)
    {
        std::cerr << "Length error: " << le.what() << '\n';
    }
}

void out_of_rangeExample()
{
    std::vector<int> myvector(10);
    try
    {
        myvector.at(20)=100;      // vector::at throws an out-of-range
    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
}

void overflow_errorExample()
{
    try
    {
        std::bitset<100> bitset;
        bitset[99] = 1;
        bitset[0] = 1;
        // to_ulong(), converts a bitset object to the integer that would generate the sequence of bits
        unsigned long Test = bitset.to_ulong();
    }
    catch(std::exception &err)
    {
        std::cerr<<"Caught "<<err.what()<<std::endl;
        std::cerr<<"Type "<<typeid(err).name()<<std::endl;
    }
}


void range_errorExample()
{
    try
    {
       throw std::range_error( "The range is in error!" );
    }
    catch (std::range_error &e)
    {
       std::cerr << "Caught: " << e.what( ) << std::endl;
       std::cerr << "Type: " << typeid( e ).name( ) << std::endl;
    }
}


//Defining your exceptions

struct CustomException : public std::exception
{
   const char * what () const throw ()
   {
      return "CustomException happened";
   }
};

void customExceptionExample()
{
    try
    {
        throw CustomException();
    } catch(CustomException& e)
    {
        std::cout << "CustomException caught" << std::endl;
        std::cout << e.what() << std::endl;
    } catch(std::exception& e)
    {
    //Other errors
    }
}


int main( int argc, char *argv[] )
{
    //assertExample();
    //stackBufferOverflow();
    //heapBufferOverflow();
    //exceptionHandlingExample();
    customExceptionExample();
}
