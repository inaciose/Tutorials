#include <iostream>
//https://www.youtube.com/watch?v=IOkgBrXCtfo
//http://thbecker.net/articles/rvalue_references/section_02.html

/*
 * Every c++ expression return either lvalue or rvalue
lvalue: An object that occupies some identifiable address in memory (heap, stack) and not in CPU register. 

rvalue: An object that is not lvalue.
 
*/

int globalvar;

int &golbalValReturn()
{
    return globalvar;
}

class dog
{
public:
    dog operator ()()
    {
        return *this;
    }
};
int sum(int a,int b)
{
    return (a+b);
}

int square(int &x)
{
    return x*x;
}

int squareWorkaround(const int &x)
{
    return x*x;
}

void print(int &x){}
void print(int &&x){}

void lvalue_rvalueExample()
{
    int i=2;//i lvalue
    int *p=&i;// p lvalue
    int x=i+2;//i+2 is rvalue
    int z=x+i;//x+i is rvalue
    //Error, since i+2 is rvalue
    //int *m=&(i+2);
    
    dog d1;
    d1=dog();// dog is rvalue
    
    
    square(x);
    //Error
    //square(10);
    
////////////////////////////Execption/////////////////////////////
    squareWorkaround(10);
    
    
    const int &j=20;
    int &&k=20;
    k++;
    std::cout<<k;
    
    //functions, () and [] opera could be lvalue
    
    golbalValReturn()=10;
    int v[3];
    *(v+2)=3;
    v[1]=4;
    
    
    {
        int i=2;
        
        int *p=&i;//lvalue reference
        int &&m=2; //rvalue reference
        
        //rvalue refernce can be used for function overloading
        print(i);
        print(2);
    }     
     
    
    
}
////////////////////Rvalue Reference -  Moving Semantic////////////////////

/*
https://youtu.be/IOkgBrXCtfo?list=PL5jc9xFGsL8FWtnZBeTqZBbniyw0uHyaH
https://www.bogotobogo.com/cplusplus/C11/5_C11_Move_Semantics_Rvalue_Reference.php


The most usefull place for rvalue reference is overloading copy constructor and copy assignment operator to achive move semantic.

Move constructor and move opera are particularly powerfull where passing be reference and pssing by value are both used.

The move constructor is used instead of the copy constructor, if the object has type "rvalue-reference" (Type &&).
std::move() is a cast that produces an rvalue-reference to an object, to enable moving from it.

When should it be used?
if you're writing application code, you would probably not be messing around a lot with temporary objects created by the compiler. So mainly you would do this in places like constructors, operator methods, standard-library-algorithm-like functions etc. where objects get created and destroyed automagically a lot. Of course, that's just a rule of thumb.

*/
class Vector
{
public:
    int size;
    double * data;
    
    Vector()
    {
      
    }
    
    
    Vector(int size)
    {
        this->size=size;
        data=new double[size];
    }
    
    Vector(const Vector &rhs)//copy constructor
    {
        size=rhs.size;
        data=new double[size];
        for(int i=0;i<rhs.size;i++)
        {
            data[i]=rhs.data[i];
        }
        std::cout<<"copy constructor called" <<std::endl;
    }
    
    Vector(Vector &&rhs)//move constructor
    {
        size=rhs.size;
        data=rhs.data;
        rhs.data=nullptr;
        std::cout<<"move constructor called" <<std::endl;
    }
    
    ~Vector()
    {
        delete[]data;
    }
    
};

Vector createVector(int size )
{
    Vector vetorObject;
    vetorObject.size=size;
    vetorObject.data=new double[size];
    return vetorObject;
}

void vectorConsumer(Vector vetorObject)
{
    
}



void movingSemantic()
{
    int size=10;
    Vector vetorObject=createVector(size);
    
    //this will call costly copy constructor
    vectorConsumer(vetorObject);
    
/*
    If we don't create a move constructor, this will call by value so it will create a temporary object.
    So we create the move constructor
*/ 
    vectorConsumer(createVector(size));
    //this will copy vetorObject by using move constructor
    vectorConsumer(std::move(vetorObject));
    //here vetorObject.data=nullptr 
    std::cout<<"vetorObject.data " <<((vetorObject.data==nullptr) ? "is a nullptr" :"is not a nullptr" )<<std::endl;
    
}

////////////////////Rvalue Reference - Perfect Fowarding////////////////////
/*
https://www.youtube.com/watch?v=0xcCNnWEMgs&list=PL5jc9xFGsL8FWtnZBeTqZBbniyw0uHyaH&index=4
*/

template
<typename T>
void relay(T&& arg)
{
    vectorConsumer(std::forward<T>(arg) );
}


void perfectFowarding()
{
    Vector vectorObject=createVector(10);
    relay(vectorObject);//copy constructor
    relay(createVector(10));//move constructor
}

int main(int argc, char *argv[])
{
    //lvalue_rvalueExample();
    //movingSemantic();
    
    std::remove_reference<int&>::type i;
    return 0;
}

