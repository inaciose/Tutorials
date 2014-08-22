//http://www.yolinux.com/TUTORIALS/ForkExecProcesses.html

/*
The fork() system call will spawn a new child process which is an identical process to the parent except
that has a new system process ID. The process is copied in memory from the parent
*/
#include <iostream>
#include <string>

// Required by for routine
#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>   // Declaration for exit()

using namespace std;

int globalVariable = 2;

int forkmain()
//int main()
{
   cout<<"once" <<endl;
	string sIdentifier;
   int    iStackVariable = 20;

   pid_t pID = fork();
//   after calling fork function, the below code would be executed by both process, parent and child
//   to discriminet which process should do what, we check pID
   if (pID == 0)                // child
   {
      // Code only executed by child process

      sIdentifier = "Child Process: ";
      globalVariable++;
      iStackVariable++;
    }
    else if (pID < 0)            // failed to fork
    {
        cerr << "Failed to fork" << endl;
        exit(1);
        // Throw exception
    }
    else                                   // parent
    {
      // Code only executed by parent process

      sIdentifier = "Parent Process:";
    }

    // Code executed by both parent and child.

    cout << sIdentifier;
    cout << " Global variable: " << globalVariable;
    cout << " Stack variable: "  << iStackVariable << endl;
}
