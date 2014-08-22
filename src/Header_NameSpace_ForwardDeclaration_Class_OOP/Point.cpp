///*
// * Point.cpp
// *
// *  Created on: Jan 6, 2012
// *      Author: behnam
// */

#include "Point.h"


int Point::GetXCoordinate(void)const
{
	return Xcoordinate;
}

int Point::GetYCoordinate(void)const
{
	return Ycoordinate;
}

void Point::ChangeCoordinate(int x, int y)
{
	Xcoordinate=x;
	Ycoordinate=y;
}
Point::Point(int x, int y)
{
	Xcoordinate=x;
	Ycoordinate=y;
}
Point::~Point()
{

}
//#include "Point.h"
//
//int Point::GetXCoord(void) const
//{
//	return m_iXCoord;
//}
//
//int Point::GetYCoord(void) const
//{
//	return m_iYCoord;
//}
//void Point::ChangeCoordinates(int iXCoord, int iYCoord)
//{
//	m_iXCoord = iXCoord;
//	m_iYCoord = iYCoord;
//}
