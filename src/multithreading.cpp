#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <unistd.h>// for usleep function

#include <chrono>//for  sleep_for function
#include<mutex>
#include <fstream>

/*
http://www.yolinux.com/TUTORIALS/LinuxTutorialPosixThreads.html
http://www.computersciencelab.com/MultithreadingTut1.htm

When you run two programs on an Operating System that offers memory protection, as Windows and UNIX/Linux
do, the two programs are executed as separate processes, which means they are given separate address spaces.
This means that when:
	program #1 modifies the address 0x800A 1234 in its memory space,
	program #2 does not see any change in the contents of its memory at address 0x800A 1234.


Thread
	A thread is a mechanism for splitting the workload into separate execution streams. Thread can be initiated faster because there is less for the Operating System to set up. The separate address space is what is missing. When a program consists of two or more threads, all the threads share a single memory space. If one thread modifies the contents of the address 0x800A 1234, then all the other threads immediately see a change in the contents of their address 0x800A 1234.

	Heap
		Furthermore, all the threads share a single heap. If one thread allocates (via malloc or new) all of the memory available in the heap, then attempts at additional allocations by the other threads will fail.

	Stack
		But each thread is given its own stack.
		
		
Race Condition

When two or more threads perform a set of operations in parallel, that access the same memory location.  Also, one or more thread out of them modifies the data in that memory location, then this can lead to an unexpected results some times.

*/


void print(int a,int &b)
{
   std::cout<<a<<" "  <<b <<std::endl; 
}

class funcObjClass
{
public:
    void operator()(int a,int &b)
    {
       std::cout<<a <<" " <<b <<std::endl; 
    }
};

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
    //first way
    std::thread threadObj0(print,a,std::ref(b) );
    //second way
    std::thread threadObj1{print,a,std::ref(b)} ;
    
    
//Creating threads with Function Objects

    funcObjClass funcObj;
    std::thread threadObj2(funcObj,a,std::ref(b) );
   
    
    
//Creating threads with Lambda Function
    auto f=[](int a,int &b){ std::cout<<a<<" " <<b <<std::endl;};
    std::thread threadObj3{f,a,std::ref(b)} ;
    
    
    threadObj0.join();
    threadObj1.join();
    threadObj2.join();
    threadObj3.join();
    
}

void differentiatingBetweenThreads()
{
    
    std::thread threadObj([](){std::cout<<"hello";});
    std::thread::id t1_id = threadObj.get_id();
    std::cout<<"ID associted with the given thread is:" <<std::endl;

    std::cout<<t1_id <<std::endl;
    
    std::cout<<"ID associted with the current thread is" <<std::endl;
    std::cout<<std::this_thread::get_id() <<std::endl;
    
    threadObj.join();
}

void sleepingTheThread()
{
    //first way
    unsigned int microseconds=5000000;
    usleep(microseconds);
    
    
    //second way
    unsigned int milliseconds=5000;
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));

}

////////////////////////////////////Join, Detach Threads//////////////////////////////
void joiningThreads()
{
/*
join will pause the current thread unitill the called threads are done, imagine in your main you have 10 threads to load the GUI,...you need to wait until they all done then you can continue. if you don't put join thread, you main function might return before even your threads finish their jobs
*/
    int a=4;
    int b=2;
    std::vector<std::thread> threadList;
    for(int i = 0; i < 10; i++)
    {
        threadList.push_back( std::thread(print,a,std::ref(b) ) );
    }
    // Now wait for all the worker thread to finish i.e.
    // Call join() function on each of the std::thread object
    std::cout<<"wait for all the worker thread to finish"<<std::endl;
    std::for_each(threadList.begin(),threadList.end(), std::mem_fn(&std::thread::join));
    std::cout<<"Exiting from Main Thread"<<std::endl;
    return;


}


void createFile(std::string filename, std::string data)
{

    std::ofstream fileObj(filename, std::ofstream::out);
    fileObj << data;
    fileObj.close();
}

void threadFileWriter()
{        
    unsigned int milliseconds=1000;
    for(std::size_t i=0;i<10;i++)
    {
        createFile(std::to_string(i)+".txt",std::to_string(i));
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
         
}
void detachingThreads()
{
/*
After calling detach(), std::thread object is no longer associated with the actual thread of execution.

In the following example we detach the thread from main, main will terminate, but 
our thread is working in the background and every second create 1 file for 10 seconds.
*/
    std::thread threadObj(threadFileWriter);
    
    std::cout<<std::this_thread::get_id()<<std::endl;
    threadObj.detach();
}

void joinableDetachable()
{
/*
When a join() function is called on an thread object (thread object=main function for instance), then when the join() returns then thread object (main function) has no associated thread with it. In case again join() function is called on such object then it will cause the program to Terminate.
Similarly calling detach() makes the std::thread object not linked with any thread function
*/
    int a,b;
    a=3;
    b=5;
    std::thread threadObj(print,a,std::ref(b) );
    
    if(threadObj.joinable())
    {
        std::cout<<"Detaching Thread "<<std::endl;
        threadObj.detach();
    }
    if(threadObj.joinable())    
    {
        std::cout<<"Detaching Thread "<<std::endl;
        threadObj.detach();
    }
  
 
}

void processTree()
{
    //pstree -p PID    
}

////////////////////////////////////Race Condition, Mutex//////////////////////////////
/*Example 1


*/
class wallet 
{
public:
    int money;
    wallet():money(0){}
    void increaseMoney(int amount)
    {
       money=money+amount; 
    }
};


int racingProblem()
{
    wallet walletObject;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i)
    {
        threads.push_back(std::thread(&wallet::increaseMoney, &walletObject, 10));
    }
    
    for(int i = 0; i < threads.size() ; i++)
    {
        threads.at(i).join();
    }
    return walletObject.money;
 
}


void racingProblemExample()
{
    int val = 0;
    for(int k = 0; k < 10000; k++)
    {
        if((val = racingProblem()) != 50)
        {
            std::cout << "Error at count = "<<k<<" Money in Wallet = "<<val << std::endl;
        }
    }
}

class walletMutex 
{
public:
    int money;
    std::mutex mutex;
    walletMutex():money(0){}
    
    
    void increaseMoney(int amount)
    {
        mutex.lock();
        money=money+amount;
        mutex.unlock();
    }
};


int fixingRaceConditions()
{
    walletMutex walletObject;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i)
    {
        threads.push_back(std::thread(&walletMutex::increaseMoney, &walletObject, 10));
    }
    
    for(int i = 0; i < threads.size() ; i++)
    {
        threads.at(i).join();
    }
    return walletObject.money;
}

void fixingRaceConditionsExample()
{
    int val = 0;
    for(int k = 0; k < 10000; k++)
    {
        if((val = fixingRaceConditions()) != 50)
        {
            std::cout << "Error at count = "<<k<<" Money in Wallet = "<<val << std::endl;
        }
    }
}


/*Example 2
In this example both threads race for accessing shared resource std::cout
*/
void function2()
{
    unsigned int sleepTime=1;//milliseconds
    for(std::size_t i=0;i<100;i++)
    {
        std::cout<<i<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime) );

    }
}


void function1()
{
    unsigned int sleepTime=1;//milliseconds
    for(int i=0;i>-100;i--)
    {
        std::cout<<i<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime) );
    }
}

void sharedResourceRacing()
{
    std::thread threadObj1(function1);
    function2();
    threadObj1.join();
}

void sharedPrinterMutex(int i)
{   std::mutex mutex;
    mutex.lock();
    std::cout<<i<<std::endl;
    mutex.unlock();
}


void function2Mutex()
{
    unsigned int sleepTime=10;//milliseconds
    for(std::size_t i=0;i<100;i++)
    {
        sharedPrinterMutex(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime) );
    }
}


void function1Mutex()
{
    unsigned int sleepTime=10;//milliseconds
    for(int i=0;i>-100;i--)
    {
        sharedPrinterMutex(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime) );
    }
}

void sharedResourceRacingFixedUsingMutex()
{
    std::thread threadObj1(function1Mutex);
    function2Mutex();
    threadObj1.join();
}


//Example 3
/*
If anything goes wrong during the mutex lock, like an exception, the code will be locked for ever so we often use gaurd.
Whenever guard goes out of scope, the mutex will be unlocked


Never return fileObj outside of LogFile
*/

class LogFile
{
    std::mutex mutex;
    //RAII (Resource acquisition is initialization)
public:
    std::ofstream fileObj;
    LogFile(std::string logFile="Log.txt")
    {
        fileObj.open(logFile,std::ofstream::out);
    }
    
    void sharedPrinter(int i)
    {   std::lock_guard<std::mutex> gaurd(mutex);
        fileObj << i<<"\n";
        
    }
    ~LogFile()
    {
        fileObj.close();
    }
    
};

void function1Log(LogFile &log)
{
    unsigned int sleepTime=10;//milliseconds
    for(int i=0;i>-100;i--)
    {
        log.sharedPrinter(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime) );
    }
}

void sharedResourceRacingFixedUsingGaurd()
{   
    LogFile log;
    
    std::thread threadObj1(function1Log,std::ref(log));
    unsigned int sleepTime=10;//milliseconds
    for(int i=0;i<100;i++)
    {
        log.sharedPrinter(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime) );
    }
    threadObj1.join();
    
}

int main()  
{
//     creatingThreads();
//     differentiatingBetweenThreads();
//     sleepingTheThread();
//     joiningThreads();
//     detachingThreads();
//     joinableDetachable();
//     racingProblemExample();
//     fixingRaceConditionsExample();    
//     sharedResourceRacing();
//     sharedResourceRacingFixedUsingMutex();
    sharedResourceRacingFixedUsingGaurd();
    
    
//     std::ofstream f("tmp.txt",std::ofstream::app);
//     f<<11;
//     f<<"ss";
//     f.close();
    
    return 0;
}





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




