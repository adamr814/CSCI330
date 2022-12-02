/*
Adam Roy
CSCI 330
*/

#include "hw8-scan.h"

int SCAN(FILE *(*stream)) { //opens file returns int of how many lines there are
    int size = 0;
    size_t charCount;
    char *text;
    if ((*stream = fopen("hw4.data", "r")) == NULL){
        printf("Problem Opening Input File hw4.data\n");
        exit(0);
    }
    while(1){
        text = NULL;
        getline(&text, &charCount, *stream);
        if(feof(*stream)) break;
        size++;
    }
    return size;}