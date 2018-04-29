/*
 * HeaderTutorial.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */

/*
 Header files typically only contain declarations. They do not define how something is implemented.
For instance "cout" is only defined in the “iostream” header file  while It is implemented in the runtime support library

A library is a package of code that is meant to be reused in many programs. Typically, a library includes
a header file that contains declarations for everything the library wishes to expose (make public) to users
and a precompiled object that contains all of the implementation code.
These libraries typically have a .lib or .dll extension on Windows, and a .a or .so extension on Unix.


Header files consist of two parts.
1)The first part is called a header guard,
2)The second part is the actual content of the .h file, which should be the declarations for all of the functions we want other files to be able to see.


In order to use this header file in main.cpp, we have to include it. Here is the new main.cpp:
#include "HeaderTutorial.h" // this brings in the declaration for sub()

 */
int sub(int x, int y)
{
	return x-y;
}

