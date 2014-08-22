#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <math.h>
#include <time.h>
//http://www.yolinux.com/TUTORIALS/LinuxTutorialPosixThreads.html


//	How to run  g++ -lpthread
/*

When you run two programs on an Operating System that offers memory protection, as Windows and UNIX/Linux
do, the two programs are executed as separate processes, which means they are given separate address spaces.
This means that when:
	program #1 modifies the address 0x800A 1234 in its memory space,
	program #2 does not see any change in the contents of its memory at address 0x800A 1234.


Thread
	A thread is a mechanism for splitting the workload into separate execution streams.
	Thread can be initiated faster because there is less for the Operating System to set up.
	The separate address space is what is missing. When a program consists of two or more threads,
	all the threads share a single memory space.


	If one thread modifies the contents of the address 0x800A 1234, then all the other threads immediately
	see a change in the contents of their address 0x800A 1234.

	Stack
		Furthermore, all the threads share a single heap. If one thread allocates (via malloc or new)
		all of the memory available in the heap, then attempts at additional allocations by the other threads will fail.

	Heap
		But each thread is given its own stack.



*/

/*
Advantages of Thread

	What's the advantage? Well, if your computer's hardware offers two processors, then two threads can
	run simultaneously.
	And even on a uni-processor, multi-threading can offer an advantage. Most programs can't perform very
	many statements before they need to access the hard disk.
	This is a very slow operation, and hence the Operating System puts the program to sleep during the wait.
	In fact, the Operating System assigns the computer's hardware resources to somebody else's program during
	the wait. But, if you have written a multi-threaded program, then when one of your threads stalls,
	your other threads can continue.
*/



using namespace std;
void *print_message_function( void *ptr );

int Multithreadingmain()
//int main()
{
     pthread_t thread1, thread2;
     char *message1 = "Thread #1";
     char *message2 = "Thread #2";
     int  iret1, iret2;

    /*

    pthread_create: create a new thread

	int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *), void *arg);
	Arguments:
		thread: returns the thread id.
		attr: Set to NULL if default thread attributes are used.
		void * (*start_routine): pointer to the function to be threaded. Function has a single argument: pointer to void.
		*arg : pointer to argument of function. To pass multiple arguments, send a pointer to a structure.

     */

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);

/*
     Threads terminate by
     	 1)explicitly calling pthread_exit,
     	 2)by letting the function return, or
		 3)by a call to the function exit which will terminate the process including any threads.
*/

/*
     pthread_join - wait for termination of another thread
         int pthread_join(pthread_t th, void **thread_return);

     Arguments:
     	 th: thread suspended until the thread identified by th terminates.
     	 thread_return: If thread_return is not NULL, the return value of th is stored in the location pointed to by thread_return.

*/
     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL);

     printf("Thread 1 returns: %d\n",iret1);
     printf("Thread 2 returns: %d\n",iret2);
     exit(0);

}

void *print_message_function( void *ptr )
{
	struct timespec ts;
	ts.tv_sec = 0;
	ts.tv_nsec = 1000;


	char *message = (char *) ptr;
	for(int i=0;i<10;i++)
	{
		cout<<message <<endl;
		cout<<i <<endl;
//		Make the process sleep for SECONDS seconds, or until a signal arrives and is not ignored
//		sleep(int t);
		nanosleep (&ts, NULL);
	}
}








