/*
 * AccessFunctionsandEncapsulation.cpp
 *
 *  Created on: Feb 14, 2012
 *      Author: behnam
 */
#include <iostream>
using namespace std;

class Date
{
private:
    int m_nMonth;

    int m_nYear;

public:
    int m_nDay;
    // Getters
    int GetMonth() { return m_nMonth; }
    int GetDay() { return m_nDay; }
    int GetYear() { return m_nYear; }

    // Setters
    void SetMonth(int nMonth) { m_nMonth = nMonth; }
    void SetDay(int nDay) { m_nDay = nDay; }
    void SetYear(int nYear) { m_nYear = nYear; }
};

int AccessFunctionsandEncapsulationmain()
//int main()
{
	Date CurrentDate;
	CurrentDate.m_nDay=10;
//  now if we change the name of the variable m_nDay in the code of our class, then we have to find
//	all the instance objects of Date class and make the changes as well, but we use CurrentDate.GetDay()
//	any changes would be hidden from instances
	CurrentDate.GetDay();
	return 0;

}



