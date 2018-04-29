/*
 * main.cpp
 *
 *  Created on: Mar 19, 2012
 *      Author: behnam
 */
#include <iostream>
#include "Student.hpp"
#include "Lecture.hpp"

/*
class A{...};
class B{
   public:
    A a, aa;//declare members

    B() // constructors are called here
        : a(...), aa(...) {
    }
};
*/

//int ClassMemberofOtherClassesmain()

int main()
{
    std::string lecturename="physic";
    School::Lecture mylecture;
    mylecture.setName(lecturename);
    mylecture.setID(12);
    
    
    Student john;
    //if you use john() then compiler would think john is a function

    john.setCourse(mylecture);
    std::cout<< john.getCourse().getName()<<std::endl;
    
    Student paul(1,"paul");
    paul.setCourse(mylecture);
    std::cout<< paul.getCourse().getName()<<std::endl;

}
