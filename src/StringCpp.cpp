/*
 * StringCpp.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;



// int Stringsmain()
int main()
{

	//string::string()
	string FirstString;
	FirstString="First String here";
	cout<<FirstString <<endl;

	//string::string(const string& strString)
	string SecondString("second String here.");
	string ThirdString(SecondString);
	SecondString="Second String changes here.";
	cout<<SecondString <<endl;
	cout<<ThirdString <<endl;

	string FourthString("Fourth String here",2,5);

	cout<<FourthString <<endl;

//	c_str()
//	Get C string equivalent
//	Generates a null-terminated sequence of characters (c-string) with the same content as the string object and returns it as a pointer to an array of characters.

	char * cstr, *p;
	string str ("Please split this phrase into tokens");

	cstr = new char [str.size()+1];
	strcpy (cstr, str.c_str());

	// cstr now contains a c-string copy of str

	p=strtok (cstr," ");
	while (p!=NULL)
	{
		cout << p << endl;
		p=strtok(NULL," ");
	}

	delete[] cstr;

	return 0;
}




