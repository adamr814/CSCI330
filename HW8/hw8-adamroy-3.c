/*
Adam Roy
CSCI 330
*/

#include "hw8-scan.h"
#include "hw8-load.h"
#include "hw8-search.h"
#include "hw8-free.h"
#include <dlfcn.h>

int main(int argv, char **argc){
    int size;
    void *handle;
    FILE *stream;
    int (*SCAN)(FILE *(*));
    struct _data *(*LOAD)(FILE *, int);
    void (*SEARCH)(struct _data *, char *, int);
    void (*FREE)(struct _data *, int);
    struct _data *BlackBox;
    handle = dlopen("./hw8-lib-adamroy.so", RTLD_LAZY);
    if (!handle) printf("%s\n", dlerror());
    SCAN = dlsym(handle, "SCAN");
    LOAD = dlsym(handle, "LOAD");
    SEARCH = dlsym(handle, "SEARCH");
    FREE = dlsym(handle, "FREE");
    if(argv == 1){
        printf("*****************************************************\n");
        printf("*  You must include a name to search for.           *\n");
        printf("*****************************************************\n");}
    if(argv == 2){
        size = SCAN(&stream);
        BlackBox = LOAD(stream, size);
        SEARCH(BlackBox, argc[1], size);
        FREE(BlackBox, size);}
    dlclose(handle);}