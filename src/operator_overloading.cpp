/*

In this example we gonna overload the following operators:
()
-
<<
= deep copy

*/

#include <iostream>
#include<cstring>

class money
{

public:
    double value;
    double *data;

money(double value)
{
    this->value=value;
    data=new double [10];
    std::cout<< "constructor money with value: "<< this->value<<std::endl;
}


//Rule of three (C++ programming)

//first implementation
money(const money &other)
{
    //other is pointing to the object that we want to copy from
   data=new double [10];
   //memcpy(dst,src)
   memcpy(data,other.data,10 );
   value=other.value;
}

//second implementation
//money(const money &other)
//{
//    //other is pointing to the object that we want to copy from
//    data=new double [10];
//    memcpy(this, &other,sizeof(other));
//}


//if we want disable copying
//money(const money &other)= delete;

~money()
{
    std::cout<< "destructor money with value: "<< this->value <<std::endl;
    delete []data;
}

double operator ()()
{
    return value;
}

friend money operator - (const money &t1,const money &t2);
friend money operator -(const money &t1, int value);
friend std::ostream& operator<<(std::ostream& os, const money& t);
};


money operator - (const money &t1,const money &t2)
{
    return money(t1.value-t2.value);
}

std::ostream& operator<<(std::ostream& os, const money& t)
{
    os << t.value;
    return os;
}

money operator -(const money &t1, int value)
{
    return money(t1.value-value);
}

int main()
{

////////////////////////// - operator overloading ///////////////////////

    money  money1(10),money2(15);
    std::cout<<"money2-money1" <<std::endl;
    std::cout<< money2-money1<<std::endl;

////////////////////////// () operator overloading ///////////////////////

    std::cout<< "money1()"<<money1()<<std::endl;

////////////////////////// << operator overloading ///////////////////////

    std::cout<< "money1 gives you:"<< money1<<std::endl;

/////////////////////////// = overloading (deep copy) ///////////////////////

    std::cout<< "===========================deep copy======================"<<std::endl;
    money  money3(3);
    money3.data[0]=1.0;
    money  money4=money3;
    std::cout<< "money4: "<< money4<<std::endl;
    std::cout<< money3.data[0]<<std::endl;
    std::cout<< money4.data[0]<<std::endl;
    std::cout<< "after updating money3.data[0]=5.0 "<<std::endl;
    money3.data[0]=5.0;
    std::cout<< money3.data[0]<<std::endl;
    std::cout<< money4.data[0]<<std::endl;
}
