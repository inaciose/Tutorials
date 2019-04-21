/*
 * StringCpp.cpp
 *
 *  Created on: Jan 4, 2012
 *      Author: behnam
 */
#include <iostream>
#include <string.h>//c style api
#include <string>//c++ style api
#include <sstream>
#include <iterator>
#include <vector>


void splitingByDelimiter()
{
    std::vector<std::string> spilitedString;
    std::string s = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        //std::cout << token << std::endl;
        spilitedString.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    for(std::size_t i=0;i<spilitedString.size();i++)
        std::cout << spilitedString[i] << std::endl;
}


//string to number and number to string
void stringNumberConversion()
{
    std::string strNumber=std::to_string(10.3);
    float f=std::atof(strNumber.c_str());//10.3
    int i =std::stoi(strNumber.c_str());//10
    double d =std::stod(strNumber.c_str() );//10.3
}


void cStyle()
{

    char * cstr, *p;
    std::string str ("Please split this phrase into tokens");

    cstr = new char [str.size()+1];
    strcpy (cstr, str.c_str());

    // cstr now contains a c-string copy of str

    p=strtok (cstr," ");
    while (p!=NULL)
    {
        std::cout << p << std::endl;
        p=strtok(NULL," ");
    }

    delete[] cstr;
}
int main()
{

    //stringNumberConversion();
    splitingByDelimiter();

	return 0;
}




