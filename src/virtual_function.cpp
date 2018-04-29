#include <iostream>


/*
    A pure virtual function or pure virtual method is a virtual function that is required to be implemented by a derived class,
    if that class is not abstract.  
 
*/


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

int main()
{
    
    Derived  Derived_object;
    Derived_object.GetValue();

    
    return 0;
}