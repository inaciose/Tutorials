/*
 * TemplateClass.h
 *
 *  Created on: Jan 8, 2012
 *      Author: behnam
 */
#ifndef ARRAY_H
#define ARRAY_H

#include <assert.h> // for assert()

/*When working with templates, you need to have the full definition in the header.
In practice it means implementation inside .h file.


http://www.bgsu.edu/departments/compsci/docs/templates.html

There is never an implementation file (*.cpp) for a template class.
All of the member functions should be declared in the header file (in this case, table.h).
*/
template <typename T>
class Array
{
private:
    int m_nLength;
    T *m_ptData;

public:
    T x;
    typedef int bamboo;
    Array()
    {
        m_nLength = 0;
        m_ptData = 0;
    }

    Array(int nLength)
    {
        m_ptData= new T[nLength];
        m_nLength = nLength;
    }

    ~Array()
    {
        delete[] m_ptData;
    }

    void Erase()
    {
        delete[] m_ptData;
        // We need to make sure we set m_pnData to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_ptData= 0;
        m_nLength = 0;
    }

    T& operator[](int nIndex)
    {
        assert(nIndex >= 0 && nIndex < m_nLength);
        return m_ptData[nIndex];
    }

    // The length of the array is always an integer
    // It does not depend on the data type of the array
    int GetLength(); // templated GetLength() function defined below
};

template <typename T>
int Array<T>::GetLength() { return m_nLength; }

#endif



