#include <iostream>
#include <string>
using namespace std;
/*
http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part-1

Templates are of two types:

1)Function Templates
2)Class Templates

It is not required to use typename keyword if a function returning something.
For template programming, these two keywords are very much the same.

However, there are instances where you can only use the newer keyword - typename.


template<class TYPE>

	tells the compiler that this is a function-template. The actual meaning of TYPE would be deduced by compiler depending on
	the argument passed to this function.
	When you attach template with a generic function, compiler would compile only for required set of data-types!.

________________________________________________________________________________________________________________________________

I)Pointers, References and Arrays with Templates

	*/
	template<class T>
	double GetAverage(T tArray[], int nElements)
	{

	/*
	this line:
		T tSum = T();

	This is not template specific code - this comes under C++ language itself.
	It essentially means: Call the default constructor for this datatype. For int, it would be:

		int tSum = int();

	Which effectively initializes the variable with 0. Similarly, for float, it would set this variable to 0.0f.
	Though not covered yet, if a user defined class type comes from T, it would call the default constructor of
	that class (If callable, otherwise relevant error).
	As you can understand that T might be any data-type, we cannot initialize tSum simply with an integer zero (0).
	In real case, it may be a some string class, which initializes it with empty string ("").
	*/

		T tSum = T(); // tSum = 0

		for (int nIndex = 0; nIndex < nElements; ++nIndex)
		{
			tSum += tArray[nIndex];
		}

		// Whatever type of T is, convert to double
		return double(tSum) / nElements;
	}

	/*

	template<class T>
	void GetAverage(T* tArray, int nElements){}


	template<class T>
	void TwiceIt(T& tData){}

	 At this point, you now clearly understand that template parameter type T may be inferred from T&, T* or T[].
	 */



//2) Multiple Types with Function Templates

	template<class T1, class T2>
	void PrintNumbers(const T1& t1Data, const T2& t2Data)
	{
		 cout << "First value:" << t1Data;
		 cout << "Second value:" << t2Data;
	}

	/*

	And we can simply call it as:

		PrintNumbers(10, 100);    // int, int
		PrintNumbers(14, 14.5);   // int, double
		PrintNumbers(59.66, 150); // double, int
	 */


//3) Explicit Template Argument Specification
	/*
		PrintNumbers<double, double>(10, 100);
		PrintNumbers<double, double>(14, 14.5);
		PrintNumbers<double, double>(59.66, 150);
	*/


//4) Function Template - Template Function

//5)Default Arguments with Function Templates
	/*
	 The default-ness may only go from right to left, meaning, if nth argument is required to be default,
	 (n+1)th must also be default, and so on till last argument of function.


	 */



//6)Class Templates

/*
When working with templates, you need to have the full definition in the header.
In practice it means implementation inside .h file.

http://www.bgsu.edu/departments/compsci/docs/templates.html

There is never an implementation file (*.cpp) for a template class.
All of the member functions should be declared in the header file
*/

	template<class T>
	class Item
	{
	    T Data;
	public:
	    Item() : Data( T() )
	    {}

	    void SetData(T nValue)
	    {
	        Data = nValue;
	    }

	    T GetData() const
	    {
	        return Data;
	    }

	    void PrintData()
	    {
	        cout << Data;
	    }
	};

	/*
		And usage as also quite simple:

		Item<int> item1;
		item1.SetData(120);
		item1.PrintData();



		Item<float> item2;
		float n = item2.GetData();


	*/


//int TemplatesFunctionmain()


template<class TYPE>
void PrintTwice(TYPE data)
{
    cout<<"Twice: " << data * 2 << endl;
}

template<class T>
T Add(T n1, T n2)
{
    return n1 + n2;
}

////////////////////////////////Template Specialization////////////////////////////////	

//An Example Program for function template specialization


template <typename T>
void add(T a, T b)
{
    std::cout<<a+b <<std::endl;

}
template <>
void add (std::string a, std::string b)
{
    std::cout<<a.append(b) <<std::endl;
}

//An Example Program for class template specialization
template <typename T>
class foo
{
public:
    static void read()
    {std::cout<<"general"<<"\n";}
};


template<>
class foo<int>
{
    public:
    static void read()
    {
      std::cout<<"special"<<"\n";
    }
};



int main()
{
//	For the first call of GetAverage, where IntArray is passed, compiler would instantiate this function as:
//	double GetAverage(int tArray[], int nElements);

	int  IntArray[5] = {100, 200, 400, 500, 1000};
	float FloatArray[3] = { 1.55f, 5.44f, 12.36f};
	cout << GetAverage(IntArray, 5);
	cout << GetAverage(FloatArray, 3);




////////////////////////////////Template Specialization////////////////////////////////	
    //function template specialization
    add(10,3);
    add(std::string ("a"),std::string ("b"));


    //class template specialization
    foo<double>::read();
    foo<int>::read();

	return 0;
}
