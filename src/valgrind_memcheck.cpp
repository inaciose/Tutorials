/*

valgrind --tool=memcheck --leak-check=yes   ./valgrind_memcheck

There will be times when the --leak-check=yes option will not result in showing you all memory leaks.
To find absolutely every unpaired call to free or new, you'll need to use the --show-reachable=yes option.


http://www.cprogramming.com/debugging/valgrind.html
*/
#include <stdlib.h>
#include <iostream>
int main()
{
    char *x = new char[10]; /* or, in C, char *x = malloc(100) */
//    delete[] x;
    return 0;
}
