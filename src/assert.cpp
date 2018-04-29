#include <stdio.h>
#include <assert.h>

//#define NDEBUG

void analyze (char *, int);

int main(void)
{
   char *string = "ABC";
   int length = 3;

   analyze(string, length);
   printf("The string %s is not null or empty, "
          "and has length %d \n", string, length);
}

void analyze(char *string, int length)
{
   assert(string != NULL);     /* cannot be NULL */
   assert(*string != '\0');    /* cannot be empty */
   assert(length > 0);         /* must be positive */
   assert(length == 3);
}

/*

When you're doing a release (non-debug) build, you can also remove the overhead of evaluating assert
statements by defining the NDEBUG macro, usually with a compiler switch. The corollary of this is that
your program  should never rely on the assert macro running.

*/
