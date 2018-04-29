/*
 * ~VectorsExample.cpp
 *
 *  Created on: Jan 6, 2012
 *      Author: behnam
 */
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//Standard Template Library (STL) algorithms, containers, functors, and iterators.

void SendVectorByRef(vector<int> &v)
{
	for(unsigned i=0;i<v.size();i++)
	{
		v.at(i)=v.at(i)+1;
	}
}


void InceamentVectorElements(vector<int>& v)
{
	for(unsigned i=0;i<v.size();i++)
	{
		v.at(i)=v.at(i)+1;
	}

}




//int Vectormain()
int main_temp()
{
	vector<int> first;

	first.push_back(0);
	first.push_back(1);
	first.push_back(2);
//	SendVectorByRef(first);
//	for(unsigned i=0;i<first.size();i++)
//	{
//		cout<< first.at(i)<<endl;
//	}
	InceamentVectorElements(first);
	for(unsigned i=0;i<first.size();i++)
	{
		cout<< first.at(i)<<endl;
	}

	cout<<"first.size()="<<first.size()<<endl;
	cout<<"first.capacity()="<<first.capacity()<<endl;

// push_back will copy the input parameter so if you destroy the input parameter it is still available in the vector
	std::vector<int  > RowVector;
	std::vector< std::vector<int  > > MatrixVector;

	RowVector.push_back(1);
	RowVector.push_back(2);
	RowVector.push_back(3);

	MatrixVector.push_back(RowVector);
	RowVector.clear();

	RowVector.push_back(4);
	RowVector.push_back(5);
	RowVector.push_back(6);

	MatrixVector.push_back(RowVector);

	RowVector.clear();
	cout<<"MatrixVector[0,1]=" <<MatrixVector.at(0).at(1)<<endl;
	cout<<"MatrixVector[1,1]=" <<MatrixVector.at(1).at(1)<<endl;




//	Iterating over a vector with subscripts
	for(unsigned int i=0;i<first.size();i++)
	{
//		cout<<first.[i]<<endl;
//		can be used as well but no checking on the range will be done
		cout<<first.at(i)<<endl;
	}

//Iterating over a vector with an iterator
	for (vector<int>::iterator it = first.begin(); it!=first.end(); ++it) {
		cout << *it << endl;
	}
/*	Why use iterators when subscripts work so well
There are several reasons to use iterators.

1)Not always possible. Subscripts can not be used on most of the containers
(eg, list and map), so you must use iterators in many cases.
2)Flexible. It is easily to change underlying container types. For example,
you might decide later that the number of insertions and deletions is so high that a
list would be more efficient than a vector.
3)Member functiuons. Many of the member functions for vector use iterators,
for example, assign, insert, or erase.
4)Algorithms. The <algorithm> functions use iterators.
*/

	vector<int> second;
	second.push_back(1);
	second.push_back(2);
	second.push_back(3);
	second.push_back(4);
	second.push_back(5);
while(!second.empty())
{
	cout<<second.back()<<endl;
	second.pop_back();
}

vector<int> myvector;
for (int i=1; i<=10; i++) myvector.push_back(i);

// erase the 6th element
myvector.erase (myvector.begin()+5);

// erase the first 3 elements:
myvector.erase (myvector.begin(),myvector.begin()+3);


//testvector has a 3 element, all of them are 100
vector<int> testvector (3,100);

//the 0th element would be 200
testvector.insert ( testvector.begin() , 200 );

//it will add two element
testvector.insert (testvector.begin(),2,300);

//or we can add an other vector to testvector
testvector.insert (testvector.begin(),first.begin(),first.end());

cout<< "testvector.size()"<<testvector.size() <<endl;

for(vector<int>::iterator it=testvector.begin();it != testvector.end();++it)
{
	cout<< *it <<endl;
}
//Returns a reference to the first element in the vector container.
cout<<testvector.front()<<endl;
//Returns a reference to the last element in the vector container.
cout<<testvector.back()<<endl;


    

    


	return 0;
}

int main()
{
    vector<int> first;

    first.push_back(0);
    first.push_back(1);
    first.push_back(2);

    vector<int> second;
    second=first;
    first.clear();
    std::cout<<second.size() <<std::endl;

}
