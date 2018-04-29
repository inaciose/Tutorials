/*
 * Variables.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */
#include <iostream>
#include <math.h>
#include <limits>
#include <cfloat>
#include <sys/resource.h>
#include <typeinfo>
#include <iomanip> //for using setprecision(n)

#include <type_name.hpp>



template <typename T>
void variable_type_info(T var_type)
{
    std::cout << "size of " <<type_name<decltype(var_type)>() << " is "<< sizeof(__typeof__(var_type) )<<" byte(s) " <<"and the value range is "<< std::numeric_limits<__typeof__(var_type) >::min() <<","<<   std::numeric_limits<__typeof__(var_type) >::max() << std::endl;
}



/*
Properties of integer types
CHAR_BIT - size of the char type in bits (it is not necessarily 8 bits)
SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN, LLONG_MIN(C99) - minimum possible value of signed integer types: signed char, signed short, signed int, signed long, signed long long
SCHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX(C99) - maximum possible value of signed integer types: signed char, signed short, signed int, signed long, signed long long
UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX(C99) - maximum possible value of unsigned integer types: unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long
CHAR_MIN - minimum possible value of char
CHAR_MAX - maximum possible value of char
MB_LEN_MAX - maximum number of bytes in a multibyte character
Properties of floating-point types
#include <cfloat>
FLT_MIN, DBL_MIN, LDBL_MIN - minimum value of float, double, long double respectively
FLT_MAX, DBL_MAX, LDBL_MAX - maximum value of float, double, long double respectively
FLT_ROUNDS - rounding mode for floating-point operations
FLT_EVAL_METHOD - evaluation method of expressions involving different floating-point types (only available in C99)
FLT_RADIX - radix of the exponent in the floating-point types
FLT_DIG, DBL_DIG, LDBL_DIG - number of decimal digits that can be represented without losing precision by float, double, long double respectively
FLT_EPSILON, DBL_EPSILON, LDBL_EPSILON - difference between 1.0 and the next representable value of float, double, long double respectively
FLT_MANT_DIG, DBL_MANT_DIG, LDBL_MANT_DIG - number of FLT_RADIX-base digits in the floating-point mantissa for types float, double, long double respectively
FLT_MIN_EXP, DBL_MIN_EXP, LDBL_MIN_EXP - minimum negative integer such that FLT_RADIX raised to a power one less than that number is a normalized float, double, long double respectively
FLT_MIN_10_EXP, DBL_MIN_10_EXP, LDBL_MIN_10_EXP - minimum negative integer such that 10 raised to a power one less than that number is a normalized float, double, long double respectively
FLT_MAX_EXP, DBL_MAX_EXP, LDBL_MAX_EXP - maximum positive integer such that FLT_RADIX raised to a power one more than that number is a normalized float, double, long double respectively
FLT_MAX_10_EXP, DBL_MAX_10_EXP, LDBL_MAX_10_EXP - maximum positive integer such that 10 raised to a power one more than that number is a normalized float, double, long double respectively
DECIMAL_DIG - minimum number of decimal digits needed to represent all the significant digits for long double.[4] The value is at least 10. (only available in C99)
*/


void typeid_example()
{
    short int short_int;
    std::cout <<typeid(short_int).name()<<std::endl;

    int integer;
    std::cout <<typeid(integer).name()<<std::endl;
}

/*There is no typeof operator in c++, it has always been a compiler specific language extension and it's pretty much obsolete.
 One should use decltype instead.
*/
int typeof_example()
{
    int a=10;
    __typeof__(a) b=a;//equal to int _a=a
    b=12;
    std::cout<<b<<std::endl;
}

void decltype_example()
{
    int i = 5;
    decltype(i) j = i * 2;
    std::cout<<j<<std::endl;
}

void numerical_limits_precision_example()
{
    std::cout << "The maximum value for type short int is:  " << std::numeric_limits<short int>::max( ) << std::endl;
    std::cout << "The minimum value for type short int is:  " << std::numeric_limits<short int>::min( ) << std::endl;
    std::cout << "The difference between 1 and the smallest "   << "value greater than 1\n for float objects is: "   << std::numeric_limits<float>::epsilon( )     << std::endl;
    std::cout << "The difference between 1 and the smallest "     << "value greater than 1\n for double objects is: "   << std::numeric_limits<double>::epsilon()  << std::endl;
    std::cout << "The difference between 1 and the smallest "   << "value greater than 1\n for long double objects is: "  << std::numeric_limits<long double>::epsilon( ) <<std:: endl;

    double a;
    a = 3.1415926534;

    std::cout.setf(std::ios::scientific,std::ios::floatfield);
    std::cout<<a<<std::endl;//3.140000e+00
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout<<a<<std::endl;//3.140000
    std::cout.precision(1);
    std::cout<<a<<std::endl;//3.1
}



void memory_size()
{
    //https://www.quora.com/How-can-I-estimate-stack-size-by-writing-a-program
    struct rlimit lim;
    getrlimit( RLIMIT_STACK, &lim );
    std::cout << lim.rlim_cur << "\n";
    std::cout << lim.rlim_max << "\n";


    //    static int frame_count = 0;
    //    printf("%d\n", frame_count++);
    //    main(argc, argv);


        //To get stack frame size: ulimit -s
}

template<class T> T min(T a, T b)
{
  return (a < b) ? a : b;
}

void suffix()
{
    //Suffix of “f” on float value
    25;     //int
    25l;    //long
    25u;   //unsigned
    25.0;  //double
    25.0f; //float
    float x = min(3.0f, 2.0f); // will compile
    /*
    x = min(3.0f, 2);   // compiler cannot deduce T type
    x = min(3.0f, 2.0); // compiler cannot deduce T type
    */
}


void scientific_notation()
{

}

void c_type_variable_size()
{
//Integers

    char c;
    variable_type_info(c);

    unsigned char uc;
    variable_type_info(uc);

    short int si;
    variable_type_info(si);

    unsigned short int usi;
    variable_type_info(usi);

    int i;
    variable_type_info(i);

    unsigned int ui;
    variable_type_info(ui);

    long int li;
    variable_type_info(li);

    unsigned long int uli;
    variable_type_info(uli);

//Float
    float f;
    variable_type_info(f);

    double d;
    variable_type_info(d);

    long double ld;
    variable_type_info(ld);
}

int main(int argc, char ** argv)
{
//    c_type_variable_size();
//    numerical_limits_precision_example();
//    typeid_example();
//    typeof_example();
    memory_size();




}

