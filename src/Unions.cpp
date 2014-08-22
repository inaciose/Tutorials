/*
 * Unions.cpp
 *
 *  Created on: Feb 8, 2012
 *      Author: behnam
 *      ref: http://www.cplusplus.com/doc/tutorial/other_data_types/
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

union mix_t {
  long l;
  struct {
    short hi;
    short lo;
    } s;
  char c[4];
} mix;

/*
 * Unions allow one same portion of memory to be accessed as different data types, since all of them are in fact the same location in memory.
 * each one with a different data type. Since all of them are referring to the same location in memory, the modification of one of the elements
 *  will affect the value of all of them. We cannot store different values in them independent of each other.
 *  One of the uses a union may have is to unite an elementary type with an array or structures of smaller elements. For example:
 *
 * union mix_t
 *
 * defines three names that allow us to access the same group of 4 bytes: mix.l, mix.s and mix.c and which we can use according to
 * how we want to access these bytes, as if they were a single long-type data, as if they were two short elements or as an array
 * of char elements, respectively. I have mixed types, arrays and structures in the union so that you can see the different ways
 * that we can access the data. For a little-endian system (most PC platforms), this union could be represented as:
 *
 *
 *
 *
 * */
int Unionsmain()
//int main()
{

	return 0;
}


