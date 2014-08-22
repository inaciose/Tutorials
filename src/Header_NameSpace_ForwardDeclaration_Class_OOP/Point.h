/*
 * Point.h
 *
 *  Created on: Jan 6, 2012
 *      Author: behnam
 */

#ifndef POINT_H_
#define POINT_H_

class Point
{
private:
	int Xcoordinate;
	int Ycoordinate;

public:
	Point(int x, int y);
	~Point();
	int GetXCoordinate(void)const;//Keyword const ensures that the methods can’t change the object.
	int GetYCoordinate(void)const;
	void ChangeCoordinate(int x, int y);
};

#endif /* POINT_H_ */

//#ifndef POINT_H
//#define POINT_H
//class Point
//{
//public:
//	int GetXCoord(void) const;// Keyword const ensures that the methods can’t change the object.
//	int GetYCoord(void) const;// The data can be changed only by this method
//	void ChangeCoordinates(int iXCoord, int iYCoord);
//private:
//	int m_iXCoord;
//	int m_iYCoord;
//};
//#endif // POINT_H
