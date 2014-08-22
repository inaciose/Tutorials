/*
 * main.cpp
 *
 *  Created on: Mar 19, 2012
 *      Author: behnam
 */
#include <iostream>
#include "Student.hpp"

using namespace People;

int ClassNamespaceForwardDeclrationmain()
{

	Student john;
	//if you use john() then compiler would think john is a function
	john.getID();
}


