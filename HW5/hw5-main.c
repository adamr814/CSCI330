#include "hw5-scan.h"
#include "hw5-load.h"
#include "hw5-search.h"
#include "hw5-free.h"

int main(int argv, char **argc){
    int size;
    FILE *stream;
    struct _data *BlackBox;
    if(argv == 1){
        printf("*******************************************\n");
        printf("*  You must provide a Name to search for  *\n");
        printf("*******************************************\n");}
    if(argv == 2){
        size = SCAN(&stream);
        BlackBox = LOAD(stream, size);
        SEARCH(BlackBox, argc[1], size);
        FREE(BlackBox, size);
    }}
