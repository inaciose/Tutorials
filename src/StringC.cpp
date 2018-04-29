/*
 * StringC.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */


#include <iostream>
#include <cstring>
using namespace std;




// Set the employee information
void SetName(char *strName)
{
	char m_strName[25];
	strncpy(m_strName, strName, 25);
	cout<<m_strName<<endl;
}



int StringC()
//int main()
{
// A string is a sequence of chars, strings are typically represented as char arrays that have a null terminator.
//	'\0' character (which has ASCII code 0).

//Since C-style strings are arrays, you can use the [] operator to change individual characters in the string:
	char szString[] = "string";
	szString[1] = 'p';
	cout << szString<<endl;

//but the fowllowing code is wrong
//	szString = "rope";

	char szSource[] = "Copy this!";
	char szDest[50];
	strcpy(szDest, szSource);
//	strcat() — Appends one string to another (dangerous)
//	strncat() — Appends one string to another (with buffer length check)
//	strcmp() — Compare two strings (returns 0 if equal)
//	strncmp() — Compare two strings up to a specific number of characters (returns 0 if equal)
//	strlen() — Returns the length of a string (excluding the null terminator)
//	strncpy()



//	http://stackoverflow.com/questions/890535/what-is-the-difference-between-char-const-and-const-char
//	const char * MyFixedString="Fixed";
	const char * MyFixedString="Fixed";
//	this will cause an error because we have const char *
//	*MyFixedString='M';
	cout<<MyFixedString<<endl;





//	if we have sting which is defined as char EmployeeName[length_of_string] and we also have char* Name
//	and we want to copy it we have to use strncpy(EmployeeName, Name,length_of_string)
	SetName("Ali Baba");
	return 0;


//	char const* p2 = "Mary";
//	*p2 = 'C'; // not allowed.
//	p2 = "Margareth";  // allowed
//
//	char * const p1 = "John";
//	*p1 = 'C'; // allowed
//	p1 = "Margarth"; // not allowed



}


