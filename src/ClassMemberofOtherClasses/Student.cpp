/*
 * Student.cpp
 *
 *  Created on: Mar 19, 2012
 *      Author: behnam
 */
#include "Student.hpp"
#include "Lecture.hpp"

Student::Student(int ID, std::string Name)
{
    this->ID=ID;
    this->Name=Name;
}

Student::Student()
{

}

Student::~Student()
{

}

int Student::getID()
{
	return ID;
}

std::string Student::getName()
{
	return Name;
}


// School::Lecture Student::getCourseName()
// {
// 	return this->Course;
// }

School::Lecture Student::getCourse()
{
	return Course;
}

void Student::setCourse(School::Lecture Course)
{
    this->Course=Course;
}
