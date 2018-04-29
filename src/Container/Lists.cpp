//http://www.cprogramming.com/tutorial/stl/stllist.html


#include <iostream>
#include <list>


/*
The Standard Template Library's list container is implemented as a doubly linked list. 
You might wonder why there are both list and vector containers in the STL -- the reason is that the underlying representations are different, 
and each representation has its own costs and benefits. The vector has relatively costly insertions into the middle of the vector, 
but fast random access, whereas the list allows cheap insertions, but slow access (because the list has to be traversed to reach any item)
*/

int main ()
{
    std::list<int> list_of_numbers;
    list_of_numbers.push_back(1);
    list_of_numbers.push_back(2);
    list_of_numbers.push_back(3);
    
}