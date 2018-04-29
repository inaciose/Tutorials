/*
 * PassingArguments.cpp
 *
 *  Created on: Jan 5, 2012
 *      Author: behnam
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Student
{
public:
	int x;
	int y;

};


void AddOneByRef(int &y) // y is a reference variable
{
    y = y + 1;
}

void AddOneByAddress(int *y) // y is a address variable
{
    *y = *y + 1;
}

void PassinString(string s)
{
	s=s+" something";
	cout<<s<<endl;
}

void PassinStringByRef(string &s)
{
	s=s+" something";
	cout<<s<<endl;
}

void PassinStringByRefKeepingOrigianlValue(const string &s)
{
	//s=s+" something"; this will raise an error. The reason we use <const string &s> is to avoid copying values
	//and occupying less space and by putting const make sure that our function wouldn't change the original value

	cout<<s<<endl;
}

void PrintArray(int *pnArray, int nLength)//Note that the length of the array must be passed in as a parameter
{
    for (int i=0; i < nLength; i++)
        cout << pnArray[i] << endl;
}

void PassingObjects(Student std)
{
	std.x=-10;
	std.y=-20;
}

void PassingObjectsByRef(Student &std)
{
	std.x=-10;
	std.y=-20;
}


void PassingVectors(vector<double> x)
{
	for(int i=0;i<x.size();i++)
	{
		x.at(i)=-x.at(i);
	}
}

void PassingVectorsByRef(vector<double> &x)
{
	for(int i=0;i<x.size();i++)
	{
		x.at(i)=-x.at(i);
	}
}



int PassingArgumentsInFunctions()
//int main()
{
//when we want to call by ref we just need to put & in function definition, thats all
	int x=10;
	AddOneByRef(x);
	cout<< "AddOneByRef:"<<endl;
	cout<< x<<endl;

//one way of calling by address is like this:
	int y=20;
	AddOneByAddress(&y);

	cout<< "AddOneByAddress:"<<endl;
	cout<< y<<endl;

//an other way of calling by address is like this:
	int *m=&y;
	AddOneByAddress(m);
	cout<< "AddOneByAddress:"<<endl;
	cout<< y<<endl;

	int anArray[6] = { 6, 5, 4, 3, 2, 1 };
	PrintArray(anArray, 6);


	PassinString("this is");

	string str="this is";
	PassinStringByRef(str);

	string Mystr="this is ";
	PassinStringByRefKeepingOrigianlValue(Mystr);



	//if we pass a vector to a function, the function will work with the copy of that function.
	vector<double> X;
	X.push_back(1);
	X.push_back(2);
	X.push_back(3);

	PassingVectors(X);
	for(int i=0;i<X.size();i++)
	{
		cout<< X.at(i)<<endl;
	}

	PassingVectorsByRef(X);

	for(int i=0;i<X.size();i++)
	{
		cout<< X.at(i)<<endl;
	}


	// if we pass a object of class to a function, a copy of that will be send to that function
	Student std;
	std.x=2;
	std.y=3;

	PassingObjects(std);
	cout<<std.x <<endl;


	PassingObjectsByRef(std);
	cout<<std.x <<endl;

}


