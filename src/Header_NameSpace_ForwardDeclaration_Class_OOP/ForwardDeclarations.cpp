/*
 * ForwardDeclarations.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */
//In a forward declaration, we declare (but do not define) our function in advance of where we use it,
//typically at the top of the file.
//A function prototype is a declaration of a function that includes the function’s
//name, parameters, and return type, but does not implement the function.

/*very important:
the function definition should not necessarily be in the same file, for instance the function adder() could be in this file
or in an other file, here we put it in the same file but generally it could be anywhere and we just need to add the
following line where we want to use it:

int adder(int x, int y);

*/


#include <iostream>


int adder(int x, int y);

int main2()
{
    using namespace std;
    cout << "The sum of 3 and 4 is: " << adder(3, 4) << endl;
    return 0;
}

int adder(int x, int y)
{
    return x + y;
}



