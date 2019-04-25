#include <iostream>


/*

A pure virtual function or pure virtual method is a virtual function that is required to be implemented by a derived class,
if that class is not abstract.
 
Here BaseAbstract is an abstract class, meaning it contains at least one pure virtual function.
You can't amke an object from it and you can only derive from it.
*/

///////////////////////////////////////Pure Virtual and Abstract Classes///////////////////////////////////

namespace  PureVirtual
{

class Base
{
public:
    void getname()
    {
        std::cout <<"Base" <<std::endl;
    }
    virtual void print() // a normal virtual
    {
        std::cout <<"Base print" <<std::endl;
    }
    //a pure virtual function
    virtual int GetValue() const  = 0; //   =0; is pure virtual in C++ which means that you have to implement those function in the child classes of
    virtual int GetValue(int i) = 0;
};

class Derived : public Base
{
public :
    void getname()
    {
        std::cout <<"Derived" <<std::endl;
    }

    void print()
    {
        std::cout <<"Derived print" <<std::endl;
    }

    int  GetValue() const
    {
        int  j=5;
        return j;
    }

    int GetValue(int i)
    {
        return 5;
    }

};

}
/*
Virtual functions will make the derived class to implement their own version of the virtual function.
So, in the following, derived class hasn't implemented the info() so you will get an error for this:

    derivedObject.info();

The only way to access the info() is assign a pointer from base class.
*/

namespace VirtualFunction
{
class base
{
public:
    virtual void info()
    {
        std::cout<<"info from base" <<std::endl;
    }
    void print()
    {
        std::cout<<"I'm a base object." <<std::endl;
    }


};


class derived:public base
{
public:

    void print()
    {
        std::cout<<"I'm a derived object." <<std::endl;
    }

};

}
int main()
{
    {
        //this will failed because Base has at least one pure virtual function
        //PureVirtual::Base baseObject;
        PureVirtual::Derived  derivedObject;
        derivedObject.GetValue();
    }


    {
        VirtualFunction::base baseObject;
        baseObject.info();


        VirtualFunction::derived derivedObject;
        /*since derived class hasn't implemented the info, we will get an error here*/
        //derivedObject.info();

        VirtualFunction::base *baseObject2;
        baseObject2=&derivedObject;

        //binded at runtime
        baseObject2->info();
        //print from derived class will be called , binded at compile time
        baseObject2->print();




    }

    return 0;
}
