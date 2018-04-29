/*
 * CommandLineArguments.cpp
 *
 *  Created on: Jan 9, 2012
 *      Author: behnam
 */
//argc = argument count
//argv, argument vector,
//argc will always be at least 1, because the first argument is always the name of the program itself
//Argument 0 is always the name of the current program being run.

//argv is where the actual arguments themselves are stored.argv is really just an array of C-style strings.
//The length of this array is argc.

#include <iostream>

//CommandLineArgumentsmain(
int CommandLineArgumentsmain(int argc, char *argv[])
//int main(int argc, char** argv) is equal
{
    using namespace std;

    if(argc<=1)
    {

    	cout<<"Usage: "<<argv[0]<<" <Filename> "<<endl;
    }
    else
    {
		cout << "There are " << argc << " arguments:" << endl;
		// Loop through each argument and print its number and value
		for (int nArg=0; nArg < argc; nArg++)
			cout << nArg << " " << argv[nArg] << endl;
    }
    return 0;
}



