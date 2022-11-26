/*
Adam Roy
CSCI 330
*/

#include "hw5-free.h"

void FREE(struct _data *BlackBox, int size){
    int i;
    for(i = 0; i < size; i++){
        free(BlackBox[i].name);
    }
    free(BlackBox);
    BlackBox = NULL;}