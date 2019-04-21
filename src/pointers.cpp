/*
 * pointers.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class person
{
public:
    std::string name;
    int id;
    person()
    {
        std::cout<<"person constructed" <<std::endl;
        id=-1;
    }
    person(int id)
    {
        this->id=id;
        std::cout<<"person with id "<< id<<" constructed" <<std::endl;
    }
    ~person()
    {
        std::cout<< ((id>-1)? std::string("person with ") + std::to_string(this->id)  +std::string(" destructed"):"person destructed"   )<<std::endl;
    }




};

class employee: public person
{
public:
    int id;
};

class manager:public person
{
public:
    std::vector<int> listOfDepartments;
};

void pointerExample()
{


/*	here we define a pointer variable, it is located somewhere in the memory that we don't know the value of that,
    it has some random value
*/
    int *pnPtr;
    // is a new keyword introduced in C++11. nullptr is meant as a replacement to NULL
    pnPtr=nullptr;

	int nValue = 5;
/*	here during compliation time, nValue get address and we assign  that address to our pointer variable */
	pnPtr = &nValue;
    std::cout<<pnPtr<<std::endl;
    std::cout<<*pnPtr<<std::endl;


/*
    The size of a pointer is dependent upon the architecture of the computer — a 32-bit computer uses 32-bit memory
    addresses — consequently, a pointer on a 32-bit machine is 32 bits (4 bytes). On a 64-bit machine, a pointer
    would be 64 bits (8 bytes).this is true regardless of what is being pointed to
*/


    std::cout<<"sizeof(char *)= " << sizeof(char *)<<std::endl;
    std::cout<<"sizeof(int *)= " <<sizeof(int *)<<std::endl;
    std::cout<<"sizeof(void *)= " <<sizeof(void *)<<std::endl;
    std::cout<<"sizeof(double *)= " <<sizeof(double *)<<std::endl;
    std::cout<<"sizeof(person *)= " <<sizeof(person *)<<std::endl;
    std::cout<<"sizeof(employee *)= " <<sizeof(employee *)<<std::endl;


    manager *coe=new manager;
    delete coe;

    employee* postEmployees=new employee[10];
    std::cout<<"sizeof(postEmployees[0])= " <<sizeof(postEmployees[0])<<std::endl;
    delete[] postEmployees;



    return;
}

void autoPointerExqmple()
{

}

void weakPointerExample()
{
    //weak pointer, it doens't increase the ref count

    std::shared_ptr<person> person0;
    {
        std::shared_ptr<person> sharedEntity0(new person(0));
        person0=sharedEntity0;
    }
    std::cout<<"sharedEntity0 is still alive because of person0=sharedEntity0" <<std::endl;

    //if we change teh above code to the following the object will die after the {} block

    std::weak_ptr<person> person1;
    {
        std::shared_ptr<person> sharedEntity1(new person(1));
        person1=sharedEntity1;
    }
    std::cout<<"sharedEntity1 died befor reaching here since person1 is a weak_ptr" <<std::endl;
}

void uniquePointerExample()
{
    //unique pointer, they have less overhead

    {

        //first way
        //std::unique_ptr<person> entity=std::unique_ptr<person>(new person);

        //second way(recommended) for exception safety
        std::unique_ptr<person> entity=std::make_unique<person>();

        //thsi will fail because it is a unique pointer, it can not be copied
        //std::unique_ptr<person> secondentity=entity;
    }
    //before we got here our "entity" has been freed.
    std::cout<<"end of fucntion call" <<std::endl;


}

void sharedPointerExample()
{
    //one line
    std::shared_ptr<manager> ceo=std::shared_ptr<manager>(new manager);
    std::shared_ptr<manager> ceo1(new manager);


    //multi line:
    std::shared_ptr<manager> cto;
    cto.reset(new manager);

    //prefered way
    std::shared_ptr<manager> boss=std::make_shared<manager>();


/*  when  you erase items in a vector the occupied space will be freed, but if you have stored pointers inside a vector
 you have to manualy call delete function to free the space.

 The destructor for std::vector<T> ensures that the destructor for T is called for every element stored in the vector.
*/

// (A) create a container of CSample pointers:
    std::vector<std::shared_ptr<manager> > vecOfCTOs;

// (B) add two elements
    std::cout<<"adding three elements to a vector...\n"<<std::endl;
    vecOfCTOs.push_back(std::shared_ptr<manager>(new manager));
    vecOfCTOs.push_back(std::shared_ptr<manager>(new manager));
    vecOfCTOs.push_back(std::shared_ptr<manager>(new manager));


    vecOfCTOs[0]->name="first CTO";
    vecOfCTOs[1]->name="second CTO";
    vecOfCTOs[2]->name="third CTO";

// (C) "keep" a pointer to the second:
    std::cout<<"keeping a reference to the second...\n"<<std::endl;
    std::shared_ptr<manager> anElement = vecOfCTOs[1];

// (D) destroy the vector:
    std::cout<<"destroying the vector releases it's elements...\n"<<std::endl;
    vecOfCTOs.clear();

// (E) the second element still exists
    std::cout<<"referenced elements still exist, however...\n"<<std::endl;
    std::cout<<anElement->name<<std::endl;
    std::cout<<"done. cleanup is automatic\n"<<std::endl;





}

void makesharedExampel()
{
    //shared pointer from normal pointer and exsiting variables

    int *a=new int;
    std::shared_ptr<int> a_ptr(a);



    int b=9;
    std::shared_ptr<int> b_ptr=std::make_shared<int>(b);
}

void pointerCasting()
{
//    std::shared_ptr<Base> b(new Base());
//    std::shared_ptr<Derived> d = std::static_pointer_cast<Derived>(b);

    std::shared_ptr<person> b(new person());
    std::shared_ptr<manager> d = std::static_pointer_cast<manager>(b);
}


int main()
{
    //pointerExample();
    //sharedPointerExample();
    //unique_pointerExample();
    //weak_pointerExample();
}


