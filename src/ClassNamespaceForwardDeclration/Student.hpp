/*
 * Student.hpp
 *
 *  Created on: Mar 19, 2012
 *      Author: behnam
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <string>
//#include "Lecture.hpp" if we use University::Lecture  CourseMambo then we have to put this include here
//and below forward declaration is not needed
// this part is a forward declaration for class Lecture
namespace University
{
	class Lecture;
}
namespace People{
class Student
{
private:
	int ID;
	std::string Name;
	University::Lecture*  Course;
//	University::Lecture  CourseMambo;
public:
	Student();
	~Student();
	std::string getName();
	int getID();
};
}

#endif /* STUDENT_HPP_ */
