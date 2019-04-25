#include <iostream>

/*
 If a method in the derived class has the same name as base, we have shdowed that method from base class.
 Here we have shadowed info()
 If we need to overload a function from base class we need to use scope resolution operator ::
 Here we have overloader print()
*/

class base
{
public:
    void info()
    {
        std::cout<<"info from base" <<std::endl;
    }
    void print()
    {
        std::cout<<"no id has been set" <<std::endl;
    }
};


class derived:public base
{
public:

    void info()
    {
        std::cout<<"info from derived" <<std::endl;

    }
    using base::print;
    void print(int id)
    {
        std::cout<<"the given id is: "<<id <<std::endl;
    }
};


int main()
{
    base baseObject;
    derived derivedObject;


    baseObject.info();
    baseObject.print();


    derivedObject.info();
    derivedObject.print();
    derivedObject.print(10);
}
