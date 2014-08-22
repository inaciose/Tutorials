/*
 * HandlingErrors_Assert_Cerr_Exit_Exceptions.cpp
 *
 *  Created on: Jan 6, 2012
 *      Author: behnam
 */

//1)Syntax errors:
//
//A syntax error occurs when you write a statement that is not valid according to the grammar of the C++ language.
//For example:
//if 5 > 6 then write "not equal";

//if (5 > 6)
//    std::cout << "not equal";


//2)Semantic errors:
//
//A semantic error occurs when a statement is syntactically valid, but does not do what the programmer intended. For example:
//
//for (int nCount=0; nCount<=3; nCount++)
//    std::cout << nCount << " ";

//The programmer may have intended this statement to print 0 1 2, but it actually prints 0 1 2 3.




#include <iostream>
#include <cstdlib>// for  exit()
using namespace std;

void ExitExample()
{
	// Delcare an array of 10 integers
	int *panData = new int[10];
	// If the user runs out of memory. If that happens, panData will be set to NULL, and !!panData will be true,
	if (!panData)
	    exit(2); // exit the program with error code 2
	panData[5] = 3;
}


//	An assert statement is a preprocessor macro that evaluates a conditional expression.
//	If the conditional expression is true, the assert statement does nothing.
//	If the conditional expression evaluates to false, an error message is displayed and the program is terminated

//AssertExample

#include <cassert> // for assert()
int GetArrayValue(int nIndex)
{
	int g_anArray[10];
    // we're asserting that nIndex is between 0 and 9
    assert(nIndex >= 0 && nIndex <= 9); // this is line 7 in Test.cpp
    return g_anArray[nIndex];
}
