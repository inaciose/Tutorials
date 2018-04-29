/*
Function Pointer
A function pointer is a variable that stores the address of a function that can later be called through that function pointer.


Function Pointer Syntax

simple example:
void (*foo)(int);  ==> foo is a function which takes an integer and returns void

void *(*foo)(int *);  ==> foo is a function which input parameter is pointer to int and returns a void pointer

man <function>
whereis <function name>

man atoi
whereis  atoi

*/
#include <cstdlib>
#include <iostream>
#include <stdio.h>

int int_sorter( const void *first_arg, const void *second_arg )
{
    int first = *(int*)first_arg;
    int second = *(int*)second_arg;
    if ( first < second )
    {
        return -1;
    }
    else if ( first == second )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



int adder(int a, int b)
{
    return a+b;
}






int main(int argc, char **argv)
{

///////////////////////////////////////////////////////adder function example  ///////////////////////////////////////////////////////
    //defining
    int (*adder_fn_ptr)(int, int);

    //binding
    adder_fn_ptr=adder; //or adder_fn_ptr=&adder

    //calling
    std::cout<<adder_fn_ptr(2,3) <<std::endl;

    //or
    std::cout<< (*adder_fn_ptr) (2,3) <<std::endl;


/////////////////////////////////////////////////////////////// qsort example /////////////////////////////////////////////////////////

// man qsort tells us:
//    void qsort(void *base, size_t nmemb, size_t size,  int(*compar)(const void *, const void *));


    int array[10];
    int i;
    /* fill array */
    for ( i = 0; i < 10; ++i )
    {
        array[ i ] = 10 - i;
    }

    qsort( array, 10 , sizeof( int ), int_sorter );
    for ( i = 0; i < 10; ++i )
    {
        printf ( "%d\n" ,array[ i ] );
    }


}
