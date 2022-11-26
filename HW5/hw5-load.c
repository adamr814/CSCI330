#include "hw5-load.h"

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