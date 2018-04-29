/*
http://www.cprogramming.com/tutorial/const_correctness.html

1) Const Variables

Example:

When declaring a const variable, it is possible to put const either before or after the type: that is, both
int const x = 5;
and
const int x = 4;
result in x's being a constant integer.


================================================================================================================================

2) Documentation and Safety

Example:

bool verifyObjectCorrectness (const myObj& obj);

Here, a myObj object is passed by reference into verifyObjectCorrectness. For safety's sake, const is used to ensure that verifyObjectCorrectness cannot change the object-

================================================================================================================================


3) Const Pointers



Declares a pointer whose data cannot be changed through the pointer:

const int *p = &someInt;
Declares a pointer who cannot be changed to point to something else:

int * const p = &someInt;


to make it easy toread remove the variable type,  then read it like:

const int *p;  ==> const  *p ; ==> *p is which is data is fixed;

int * const p ==>  * const p ==> p is fixed which is an address;


================================================================================================================================


4) Const Functions

<return-value> <class>::<member-function>(<args>) const
{
        // ...
}

Example:
int Loan::calcInterest() const
{
        return loan_value * interest_rate; 
}

================================================================================================================================

5)Const iterators

std::vector<int> vec;
vec.push_back( 3 );
vec.push_back( 4 );
vec.push_back( 8 );

for ( std::vector&lt;int>::const_iterator itr = vec.begin(), end = vec.end(); itr != end; ++itr )
{
        // just print out the values...
        std::cout<< *itr <<std::endl;
}

================================================================================================================================
6)Const cast



*/
