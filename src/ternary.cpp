#include <iostream>

//ternary, one line if
void ternary()
{
    int a,b;
    a=10;
    b=5;
    //x = (condition) ? (value_if_true) : (value_if_false);
    std::cout <<  ((a>b) ? "a is bigger" :"b is bigger") << std::endl;
}

int main()
{
    ternary();
}
