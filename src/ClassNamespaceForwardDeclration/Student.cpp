/*
 * Student.cpp
 *
 *  Created on: Mar 19, 2012
 *      Author: behnam
 */
#include "Student.hpp"
#include "Lecture.hpp"

using namespace People;

Student::Student()
{
	//mpMessageDriver = new message_driver::MessageDriver();
	Course=new University::Lecture();
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




