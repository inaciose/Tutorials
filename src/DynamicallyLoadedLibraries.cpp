#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>



int main(int argc, char ** argv)
{
    void *handle;
    int (*adder_fn_ptr)(int, int);
    char *error;

    handle = dlopen ("/home/basadi/workspace/Tutorial/build/libadd.so", RTLD_LAZY);
    if (!handle)
    {
        fputs (dlerror(), stderr);
        exit(1);
    }

    adder_fn_ptr = (int (*)(int, int))  dlsym(handle, "add");
    if ((error = dlerror()) != NULL)
    {
        fputs(error, stderr);
        exit(1);
    }

//    printf ("%d\n", (*adder_fn_ptr)(2,3));
    printf ("%d\n", adder_fn_ptr(2,3));
    dlclose(handle);
    return 0;
}
