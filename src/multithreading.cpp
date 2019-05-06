#include <iostream>
#include <thread>

void doWork()
{
    
}


void function2()
{
    //for(std::size_t i=0;i<10000000;i++)
    while(1)
        std::cout<<"thread 2 is running"<<std::endl;
}


void function1()
{
    //for(std::size_t i=0;i<10000000;i++)
    while(1)
        std::cout<<"thread 1 is running"<<std::endl;
}
//pstree -p PID
//int main()
// {   
//         //std::thread worker(doWork);
//     
//     std::thread thread1(function1);
//     std::thread thread2(function2);
//     
//     thread1.join();
//     thread2.join();
//     
//     //std::cin.get();
// }
// 


void thread_function()
{
    for(int i = 0; i < 1; i++)
    {
        std::cout<<std::this_thread::get_id()<<std::endl;
        
        std::cout<<"thread function Executing"<<std::endl;
    }
        
}

void print(int a,int &b)
{
   std::cout<<a <<b <<std::endl; 
}

void creatingThreads()
{
/*
    We can attach a callback with the std::thread object, that will be executed when this new thread starts. These callbacks can be,

    1.) Function Pointer
    2.) Function Objects
    3.) Lambda functions

    New Thread will start just after the creation of new object and will execute the passed callback in parallel to thread that has started it
*/

//Creating threads with Function Pointer
    int a,b;
    a=1;
    b=2;
    std::thread(print,a,std::ref(b) );

}
int main()  
{
  

    std::cout<<std::this_thread::get_id()<<std::endl;

    std::thread threadObj(thread_function);
    std::cout<<threadObj.get_id()<<std::endl;
    
    for(int i = 0; i < 1; i++)
    {
        std::cout<<"Display From MainThread"<<std::endl;
    }
        
    threadObj.join();    
    std::cout<<"Exit of Main function"<<std::endl;
/*
join will pause the current thread unitill the called threads are done, imagine in your main you have 10 threads to load the GUI,...you need to wait until they all done then you can continue.

*/
return 0;
}


