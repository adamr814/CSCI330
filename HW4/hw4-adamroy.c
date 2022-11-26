/************************************************************************
CSCI 330
FALL 2022
PROGRAM : HW4
AUTHOR  : Adam Roy
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct _data{
    char *name;
    long number;
};

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

struct _data *LOAD(FILE *stream, int size){ //just pass stream by value since its not being edited
    int i;
    size_t charCount;
    char *text, *phoneNum, *name;
    struct _data *BlackBox;
    if ((BlackBox = (struct _data*)calloc(size, sizeof(struct _data))) == NULL){
        printf("Error Allocating Memeory");
        exit(0);}
    rewind(stream);
    for(i = 0; i < size; i++) {
        text = NULL;
        getline(&text, &charCount, stream);
        name = strtok(text, " ");
        phoneNum = strtok(NULL, "\n");
        if ((BlackBox[i].name = (char*)calloc(strlen(name) + 1, sizeof(char))) == NULL){
            printf("Error Allocating Memory");
            exit(0);
        }
        strcpy(BlackBox[i].name, name);
        BlackBox[i].number = atol(phoneNum);
        free(text);
    }
    return BlackBox;
    fclose(stream);}


void SEARCH(struct _data *BlackBox, char *name, int size){
    int i = 0;
    int found = 0;
    for(i = 0; i < size; i++){
        if(!strcmp(name, BlackBox[i].name)){
            printf("The Name Was Found at location: %d\n", i);
            found = 1;
            break;}}
    if(found == 0){
        printf("The Name Was Not Found\n");}}

void FREE(struct _data *BlackBox, int size){
    int i;
    for(i = 0; i < size; i++){
        free(BlackBox[i].name);
    }
    free(BlackBox);
    BlackBox = NULL;}

int main(int argv, char **argc){
    int size;
    FILE *stream;
    struct _data *BlackBox;
    if(argv == 1){
        printf("You must provide a Name to search for\n");}
    if(argv == 2){
        size = SCAN(&stream);
        BlackBox = LOAD(stream, size);
        SEARCH(BlackBox, argc[1], size);
        FREE(BlackBox, size);
    }}
