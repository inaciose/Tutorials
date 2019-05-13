#include <iostream>
#include <string>

/*
If we dont put mutable before debugCounter, we can't have debugCounter++ in getName() as it is a const function and can't change anything
*/
class student 
{
    int mutable debugCounter;
    std::string name;
public: 
    student(std::string name): name(name), debugCounter(0){}
    void setName(std::string name)
    {
        name=name;
    }
    const std::string getName() const
    {
        debugCounter++;
        return name;
    }
};

int main()
{
    //first example
    student stdObject("jumbo");
    
    
    //second example
    int x=0;
    auto f=[=]() mutable
    {
        x++;
        std::cout<<x <<std::endl;
    };
}
