/*
 * StringToNumberConvertor.cpp
 *
 *  Created on: Jul 11, 2012
 *      Author: behnam
 */


#include <iostream>
#include <sstream>
using namespace std;

template<typename to, typename from>
to lexical_cast(from const &x)
{
	std::stringstream os;
	to ret;
	os << x;
	os >> ret;
	return ret;
}

int StringToNumberConvertor()
//int main()
{
	int iVar;
	float fVar;
	std::string strVar="14.3";

	fVar=lexical_cast<float>(strVar);
	cout<<"Conversion from string to float: " <<fVar<<endl;

	iVar=lexical_cast<int>(strVar);
	cout<<"Conversion from string to int: " <<iVar<<endl;

	fVar=12.43;
	strVar=lexical_cast<std::string>(fVar);
	cout<<"Conversion from float to string: " <<strVar+":)"<<endl;



//	cout<<"Conversion from string to float: " <<fVar<<endl;
//	cout<<"Conversion from string to float: " <<fVar<<endl;
	return 0;
}
