/*
 * Lecture.cpp
 *
 *  Created on: Mar 19, 2012
 *      Author: behnam
 */
#include "Lecture.hpp"


using namespace School;

int Lecture::getID()
{
	return ID;
}

void Lecture::setID(int id)
{
    this->ID=id;
}

std::string Lecture::getName()
{
	return this->Name;
}

void Lecture::setName(std::string lecturename)
{
    this->Name=lecturename;
}

Lecture::Lecture()
{

}

Lecture::~Lecture()
{

}

