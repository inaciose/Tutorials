/*
 * Pointers.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */

#include <iostream>

struct Employee
{
    int nID;
    int nAge;
    float fWage;
};


using namespace std;

void SendParamToFunctionByPointerByRef(int * &x)
{
//	here x is pointing to somewhere random
	int y=10;
	x=&y;
	cout<<"x in the function, x has been updated to address of y" << x <<endl;

}

void SendParamToFunctionByPointer(int *x)
{
	/*
		When we use "pass by pointer" to pass a pointer to a function, only a copy of the pointer is passed
		to the function. We can say "pass by pointer" is passing a pointer by value.
		In most cases, this does not present a problem.
		But problem comes when you modify the pointer inside the function. Instead of modifying the variable,
		you are only modifying a copy of the pointer and the original pointer remains unmodified, that is,
		it still points to the old variable.
	*/
//	here x is pointing to somewhere random
	int y=10;
	x=&y;
	cout<<"x in the function, a copy of x has been updated to address of y" << x <<endl;


}

//int main()
int Pointersmain()
{


//	here we define a pointer variable, it is located somewhere in the memory that we don't know the value of that
	int *pnPtr;
//	it has some random value
	cout<<pnPtr<<endl;
//	it is pointing to somewhere in the memmory that we don't know where is that
	cout<<*pnPtr<<endl;
//	Sometimes it is useful to make our pointers point to nothing.
//	This is called a null pointer. We assign a pointer a null value by setting it to address 0:
//	pnPtr = 0; // assign address 0 to pnPtr

	int nValue = 5;
//	here during compliation time, nValue get address and we assign  that address to our pointer variable
	pnPtr = &nValue;
	cout<<pnPtr<<endl;
	cout<<*pnPtr<<endl;



	char *pchValue; // chars are 1 byte
	int *pnValue; // ints are usually 4 bytes

	/*
	The size of a pointer
	The size of a pointer is dependent upon the architecture of the computer — a 32-bit computer uses 32-bit memory
	addresses — consequently, a pointer on a 32-bit machine is 32 bits (4 bytes). On a 64-bit machine, a pointer
	would be 64 bits (8 bytes).this is true regardless of what is being pointed to
	*/

	cout<<"sizeof(pchValue)= " << sizeof(pchValue)<<endl;
	cout<<"sizeof(pnValue)= " <<sizeof(pnValue)<<endl;

	int *x;
//	here x is pointing to somewhere random
	cout<<"x is:" <<x <<endl;
//	because a copy of x would be send to function, we can't get teh address of y
	SendParamToFunctionByPointer(x);
	cout<<"x is still:" <<x <<endl;



	SendParamToFunctionByPointerByRef(x);
	cout<<"x after call, has new value:" <<x <<endl;


	return 0;
}





