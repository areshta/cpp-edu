#include <iostream>
#include <dlfcn.h>
#include "main.h"

using namespace std;

int main()
{

    void *lib_handle;
    typedef void (*inpType)(int *, int *);
    inpType fnInput;

    char *error;
    lib_handle = dlopen("./lib/libctest.so", RTLD_LAZY);
    if (!lib_handle)
    {
	      cerr << dlerror() << endl;
	      exit(1);
    }

    fnInput = (inpType)dlsym(lib_handle, "inputer");
    if ((error = dlerror()) != NULL) 
    {
        cerr << error << endl;
        exit(1);
    }

    typedef int (*summType)(int , int );
    summType fnSummator;
    fnSummator = (summType)dlsym(lib_handle, "summator");
    if ((error = dlerror()) != NULL) 
    {
        cerr << error << endl;
        exit(1);
    }


    int a = 0;
    int b = 0;
    (*fnInput)(&a, &b);
    cout << (*fnSummator)(a, b) << endl;


    return 0;
}

