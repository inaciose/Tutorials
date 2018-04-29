#include <iostream>


/*


func2()
{
    a,b;
}


func1()
{
    a,b;
}

sum;
main()
{
    x,y;
    int *z=new int[10];
    func1()
    func2()
}

---------------------------------
|                               |  <-heap
|                               |
|               z               |
|                               |
|                               |
|                               |
|                               |
|-------------------------------|
|                               |  <-stack
|                               |
|-------------------------------|
|            func2()            |  <-stack frame3
|             a,b               |
|-------------------------------|
|            func1()            |  <-stack frame2
|            a,b                |
|--------------------------------
|            main()             |  <-stack frame1
|             x,y               |
|                               |
|-------------------------------|
|             sum               | <- static/global vaiables
|-------------------------------|
|          code(Text)           |
|            main               |
|            func1              |
|            func2              |
---------------------------------




heap:
    grow downward

The memory size for these three section is fixed and it is not growing
code:
    code of application

static/global vaiables:
    are avaiable during whole life cycle of application

stack:
    local variables/ function calls



*/

/*

The memory a program uses is typically divided into four different areas:

1)The code area, where the compiled program sits in memory.
2)The globals area, where global variables are stored.
3)The heap, where dynamically allocated variables are allocated from.
4)The stack, where parameters and local variables are allocated from.
	Stack has the structure of LIFO (Last In First Out), our application is a series of function calling
	each other so they should be stored in stack
*/

using namespace std;
//int HeapStackmain ()
//int main()
//{

/*
	The heap

	The heap  is a large pool of memory used for dynamic allocation. In C++,
	when you use the new operator to allocate memory, this memory is assigned from the heap.

	Because the precise location of the memory allocated is not known in advance( when you are developing your code),
	the memory allocated has to be accessed indirectly — which is why new returns a pointer!
*/
//	int *pValue = new int; // pValue is assigned 4 bytes from the heap
//	int *pArray = new int[10]; // pArray is assigned 40 bytes from the heap


//	pValue1 and pValue2 may not have sequential addresses!


/*
	Advantages and disadvantages:
	1) Allocated memory stays allocated until it is specifically deallocated (beware memory leaks).
	2) Dynamically allocated memory must be accessed through a pointer.
	3) Because the heap is a big pool of memory, large arrays, structures, or classes should be allocated here.
*/



/*
	The Stack
	Stack has the structure of LIFO (Last In First Out), our application is a series of function calling
	each other so they should be stored in stack.

	The call stack is a limited fixed-size chunk of sequential memory addresses and can only hold a limited amount of information!


	Advantages and disadvantages:

	1)Memory allocated on the stack stays in scope as long as it is on the stack. It is destroyed when it is popped off the stack.
	2)All memory allocated on the stack is known at compile time. Consequently, this memory can be accessed directly through a variable.
	3)Because the stack is relatively small, it is generally not a good idea to do anything that eats up lots of stack space.
	This includes allocating large arrays, structures, and classes, as well as heavy recursion.
*/


/*
	Stack overflow
	happens when all the memory in the stack has been allocated — in that case, further allocations begin overflowing
	into other sections of memory.

	It happens in cases of
		I)too many variables on the stack.
		II)making too many nested function calls.

	Here is an example program that causes a stack overflow:

	int nStack[100000000];


*/


//	cout<<" "<<endl;
//	return 0;
//}
int main()
{
	return 0;
}
