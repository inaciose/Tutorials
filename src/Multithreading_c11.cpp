#include <thread>
#include <iostream>



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


//detach: when detached thread rech end of it execution its memry cleaned up right away,
//join: they stick around till an other thread join them
int stdThreadJoinDetach()
{

    std::thread thread1(function1);


    std::thread thread2(function2);
//    thread2.detach();


    for(std::size_t i=0;i<100;i++)
        std::cout<<"main thread is running"<<std::endl;


    thread1.join();
    thread2.join();
    return 0;

}


void *function1(void *)
{

//    while(1)
    for(std::size_t i=0;i<1000;i++)
        std::cout<<"thread 1 is running"<<std::endl;
}



void *function2(void *)
{

//    while(1)
    for(std::size_t i=0;i<1000;i++)
        std::cout<<"thread 2 is running"<<std::endl;
}


int pthreadmain()
{
    pthread_t th1,th2;
    pthread_create(&th1,NULL, function1,NULL);
    pthread_create(&th2,NULL,function2,NULL);




    std::cout<<"done"<<std::endl;
//    pthread_detach(th1);
//    pthread_detach(th2);

    pthread_join(th1,NULL);//th1 will join main thread
    pthread_join(th2,NULL);

}
//The std::thread library is implemented on top of pthreads
int main()
{
//    stdThreadJoinDetach();
    pthreadmain();
}




