#include<iostream>
#include <limits>

#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <cstdlib>


template <class T> std::string type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}




template <typename T>
void variable_type_info(T var_type)
{
    std::cout << "size of " <<type_name<decltype(var_type)>()
                << " is "<< sizeof(__typeof__(var_type) )<<" byte(s) "
                <<"and the value range is "<< std::numeric_limits<__typeof__(var_type) >::min()
               <<","<<   std::numeric_limits<__typeof__(var_type) >::max() << std::endl;
}


void typeidExample()
{
    short int short_int;
    std::cout <<typeid(short_int).name()<<std::endl;

    int integer;
    std::cout <<typeid(integer).name()<<std::endl;
}

/*

How to create a variable nased on the type of an other variable:
1) __typeof__
2) decltype
There is no typeof operator in c++, it has always been a compiler specific language extension
and it's pretty much obsolete. One should use decltype instead.
*/
int typeofExample()
{
    int a=10;
    __typeof__(a) b=a;//equal to int _a=a
    b=12;
    std::cout<<b<<std::endl;
}

void decltypeExample()
{
    int i = 5;
    decltype(i) j = i * 2;
    std::cout<<j<<std::endl;
}


void cTypeVariableSize()
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


int main()
{
    cTypeVariableSize();
//    typeidExample();
//    typeofExample();
}
