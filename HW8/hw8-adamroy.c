/*
Adam Roy
CSCI 330
*/

#include "./hw8-scan.h"
#include "./hw8-load.h"
#include "./hw8-search.h"
#include "./hw8-free.h"

int main(int argv, char **argc){
    int size;
    FILE *stream;
    struct _data *BlackBox;
    if(argv == 1){
        printf("*****************************************************\n");
        printf("*  You must include a name to search for.           *\n");
        printf("*****************************************************\n");}
    if(argv == 2){
        size = SCAN(&stream);
        BlackBox = LOAD(stream, size);
        SEARCH(BlackBox, argc[1], size);
        FREE(BlackBox, size);
    }}