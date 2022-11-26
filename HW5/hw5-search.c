/*
Adam Roy
CSCI 330
*/

#include "hw5-search.h"

void SEARCH(struct _data *BlackBox, char *name, int size){
    int i = 0;
    int found = 0;
    for(i = 0; i < size; i++){
        if(!strcmp(name, BlackBox[i].name)){
            printf("*******************************************");
            printf("The Name Was Found at the %d entry\n", i);
            printf("*******************************************");
            found = 1;
            break;}}
    if(found == 0){
        printf("*******************************************\n");
        printf("*          The Name Was Not Found         *\n");
        printf("*******************************************\n");}
    printf("\n");
    }
