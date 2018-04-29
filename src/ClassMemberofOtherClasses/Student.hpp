/*
 * Student.hpp
 *
 *  Created on: Mar 19, 2012
 *      Author: behnam
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <string>
#include "Lecture.hpp"


class Student
{
private:
	int ID;
	std::string Name;
	// here we can not put University::Lecture  Course
	//because  Course is NOT primary type so it need constructor  initialization which is costly so it is avoided.
	//message_driver::MessageDriver* mpMessageDriver;
	School::Lecture  Course;
public:
	Student(int ID,	std::string Name);
	Student();
	~Student();
	std::string getName();
	int getID();
	void setCourse(School::Lecture Course);
	School::Lecture getCourse();
};


#endif /* STUDENT_HPP_ */
