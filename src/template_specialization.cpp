#include <iostream>
#include <string>


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



int main(int argc , char ** argv)
{
    //function template specialization
    add(10,3);
    add(std::string ("a"),std::string ("b"));


    //class template specialization
    foo<double>::read();
    foo<int>::read();

}
