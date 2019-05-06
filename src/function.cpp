#include <iostream>
#include <functional>

/*
Class template std::function is a general-purpose polymorphic function wrapper. Instances of std::function can store, copy, and invoke any Callable target:

functions
lambda expressions
bind expressions
functors

*/
// template<typename T>
// void print(T value)
void print(int value)
{
    std::cout<< value<<std::endl;
}

int main()
{
    //storing a functions
    {   
        std::function<void(int)> funcPrint=print;
        print(3);
    }

    //store a bind expressions
    {
        std::function<void (int)> funcPrint=std::bind(&print,std::placeholders::_1);
        
        std::function<void (int)> f(funcPrint);
        f(3);
    }

    
    //store lambda expressions
    {
        auto lambda=[](int value){std::cout<< value<<std::endl;};
        std::function<void(int)>f(lambda);
        f(3);
    }

    //store a functors
    {
        void (*printfunctor)(int);
        printfunctor=print;
        std::function<void(int)>f(printfunctor);
        f(3);
    }
    
}
