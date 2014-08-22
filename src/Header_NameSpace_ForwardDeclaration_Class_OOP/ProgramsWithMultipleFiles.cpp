/*
 * ProgramsWithMultipleFiles.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */
#include <iostream>
int add(int x, int y); // forward declaration using function prototype
/*
 the function add could be in any file, anywhere in the project, in this case it is in the file add.cpp

However, as programs grow larger and larger, it becomes tedious to have to forward declare every function
you use that lives in a different file.
To solve that problem, the concept of header files was introduced.
 */
int main3()
{
    using namespace std;
    cout << "The sum of 3 and 4 is: " << add(3, 4) << endl;
    return 0;
}



