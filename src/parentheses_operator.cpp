//http://www.dreamincode.net/forums/topic/180096-a-guide-to-function-objects/

#include <iostream>
using namespace std;

class HelloWorld
{
public:
    void operator()();
    
};

void HelloWorld::operator()()
{
    cout << "Hello World" << endl;
}

int main()
{
    HelloWorld hw;

    hw();
}

