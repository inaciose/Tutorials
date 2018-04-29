/*
 * OOExample.cpp
 *
 *  Created on: Jan 6, 2012
 *      Author: behnam
 */
#include <iostream>
#include "Point.h"

using namespace std;

int OOExamplemain()
{
	Point FirstPoint(2,3);

	cout<<FirstPoint.GetXCoordinate()<<endl;
	cout<<FirstPoint.GetYCoordinate()<<endl;
	FirstPoint.ChangeCoordinate(10,12);
	cout<<FirstPoint.GetXCoordinate()<<endl;
	cout<<FirstPoint.GetYCoordinate()<<endl;

	return 0;
}



