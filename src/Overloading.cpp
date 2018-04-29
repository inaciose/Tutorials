#include <iostream>

class OverLoadingClass
{
private:
	int x;
public:



    OverLoadingClass(int value)
    {
        this->x=value;
    }
    void operator() ()
	{
		std::cout<< x <<std::endl;
	}


};



int main (int argc, char** argv)
{

    OverLoadingClass my_OverLoadingClass(10);
     my_OverLoadingClass();
}
