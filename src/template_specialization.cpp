#include <iostream>
#include <string>


/*
You can specialize your template over different types. If you start with a base case:

*/

template <typename T>
void add(T a, T b)
{
    std::cout<<a+b <<std::endl;

}

/*
You can then declare different behavior for any specific value of T:

*/
template <>
void add (std::string a, std::string b)
{
    std::cout<<a.append(b) <<std::endl;

}
int main(int argc , char ** argv)
{
    add(10,3);
    add(std::string ("a"),std::string ("b"));

}
