/*
Adam Roy
CSCI 330
*/

#include "hw8-search.h"

void SEARCH(struct _data *BlackBox, char *name, int size){
    int i = 0;
    int found = 0;
    for(i = 0; i < size; i++){
        if(!strcmp(name, BlackBox[i].name)){
            printf("*****************************************************\n");
            printf("[%s] was found at the %d entry\n",name, i);
            printf("*****************************************************\n");
            found = 1;
            break;}}
    if(found == 0){
        printf("*****************************************************\n");
        printf("[%s] was not found.\n", name);
        printf("*****************************************************\n");}
    printf("\n");
    }
