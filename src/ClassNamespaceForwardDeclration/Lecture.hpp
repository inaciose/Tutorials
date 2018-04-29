/*
 * Lecture.hpp
 *
 *  Created on: Mar 19, 2012
 *      Author: behnam
 */

#ifndef LECTURE_HPP_
#define LECTURE_HPP_


#include <string>

namespace University
{
	class Lecture
	{
	private:
		int ID;
		std::string Name;
	public:
		int getID();
		void setID();
		std::string getName();
		void setName();
		Lecture();
		~Lecture();
	};
}

#endif /* LECTURE_HPP_ */
