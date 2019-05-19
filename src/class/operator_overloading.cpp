/*

In this example we gonna overload the following operators:
()
-
<<
>>
= deep copy (Copy constructor, Assignment operator)
*/
#include <iostream>
#include<cstring>
#include <istream>
#include <algorithm>
#include<cstring>
#include <ctime>

class money
{
private:
    int size=10;
    
void setValues()
{

}
    
public:
    int value;
    int *data;

money(int value=10)
{
    this->value=value;
    std::cout<< "Constructor money with value: "<< this->value<<std::endl;

    data=new int [size];
    
    int upperBound=20;
    int lowerBound=0;
    int numberOfRandomNumbers=size;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(lowerBound, upperBound);

    for (int n=0; n<numberOfRandomNumbers; ++n)
       data[n]= dis(gen);
}

/*
Copy constructor:
money m2 = m1; 
*/
money(const money &rhs)
{
    std::cout<<"Copy constructor called "<<std::endl; 
    //rhs is pointing to the object that we want to copy from
    data=new int [size];
    //memcpy(dst,src,size)
    memcpy(data,rhs.data,size*sizeof(rhs.data[0]) );
    value=rhs.value;
}

/*
second implementation
money(const money &rhs)
{
   //rhs is pointing to the object that we want to copy from
   data=new int [10];
   memcpy(this, &rhs,sizeof(rhs));
}


if we want disable copy constructor called
money(const money &other)= delete;
*/



//Assignment operator

money& operator = (const money &rhs) 
{ 
    std::cout<<"Assignment operator called "<<std::endl;
    memcpy(data,rhs.data,size*sizeof(rhs.data[0]) );
    value=rhs.value;
    return *this;
}

~money()
{
    std::cout<< "Destructor money with value: "<< this->value <<std::endl;
    delete []data;
}

double operator ()()
{
    return value;
}

friend money operator - (const money &t1,const money &t2);
friend money operator -(const money &t1, int value);
friend std::ostream& operator<<(std::ostream& os, const money& t);
friend std::istream& operator >> (std::istream &is,const money& t);
 
};


money operator - (const money &t1,const money &t2)
{
    return money(t1.value-t2.value);
}

std::ostream& operator<<(std::ostream& os, const money& t)
{
    for(int i=0;i<t.size;i++)
        os << t.data[i]<<" ";
    return os;
}

money operator -(const money &t1, int value)
{
    return money(t1.value-value);
}

std::istream& operator >> (std::istream& is, const money& t)
{
    is>>t.value;
    return is;
}

int main()
{

////////////////////////// - operator overloading ///////////////////////

    money  money1(7),money2(3);
    std::cout<<"The operator - gives you:" <<std::endl;
    std::cout<< money2-money1<<std::endl;

////////////////////////// () operator overloading ///////////////////////

    std::cout<< "The operator () gives you:\n"<<money1()<<std::endl;

//////////////////////// << operator overloading ///////////////////////

    std::cout<< "The operator () << gives you:\n"<< money1<<std::endl;
    
////////////////////// >> operator overloading ///////////////////////
//     getchar();
//     std::cin>> money1;
//     std::cout<< "The operator >> gives you:"<< money1<<std::endl;


/////////////////////////// Assignment operator ///////////////////////

    std::cout<< "===========================Assignment operator======================"<<std::endl;
    money  money3(3);
    money  money4(4);
    std::cout<<"money3 is: " <<money3 <<std::endl;
    std::cout<<"money4 is: " <<money4 <<std::endl;
    
    money4=money3;
    std::cout<<"after money4=money3, money4 is: " <<money4 <<std::endl;


    
/////////////////////////// Copy Constructor ///////////////////////
    std::cout<< "===========================Copy operator======================"<<std::endl;
    
    money  money5=money3;
    money3.data[0]=-1;
    money5.data[2]=-2;    
    std::cout<< "money5 after updating money5.data[2]=-2 : "<< money5<<std::endl;
    std::cout<< "money3 after updating money3.data[0]=-1 : "<<money3 <<std::endl;

}
