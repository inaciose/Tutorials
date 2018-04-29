/*
 * TemplateClassExample.cpp
 *
 *  Created on: Jan 7, 2012
 *      Author: behnam
 *
 *      http://www.iis.sinica.edu.tw/~kathy/vcstl/templates.htm
 */
#include <iostream>
#include "TemplateClass.h"
using namespace std;

//TemplateClassExamplemain()
int TemplateClassExamplemain()
{
	Array<int> anArray(12);
	Array<double> adArray(12);

	for (int nCount = 0; nCount < 12; nCount++)
	{
		anArray[nCount] = nCount;
		adArray[nCount] = nCount + 0.5;
	}

	for (int nCount = 11; nCount >= 0; nCount--)
		std::cout << anArray[nCount] << "\t" << adArray[nCount] << std::endl;
	return 0;
}


