#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct _node {
    char *name;
    struct _node *next;
};
typedef struct _node LINK;

int SCAN(FILE *data){
    printf("\n\nPRINT\n\n");
    int i = 0;
    size_t charCount;
    char *text = NULL;
    while(getline(&text, &charCount, data) != -1){
        i++;
    }
    return i;
    }

int LINK_SEARCH(char name[], LINK *head){
    LINK *current;
        current = head;
    while(current != NULL){
        if(!strcmp(current->name, name)) return 1; //Finds it
        current = current->next;}
    return 0; //Does not find it
}

LINK *LINK_INSERT(char name[], LINK *head){
    LINK *current, *temp;
    if (LINK_SEARCH(name, head) == 1) return head; //Check if name is already in list
    if((temp = (LINK*)malloc(sizeof(LINK))) == NULL){//Adding link to new name
        printf("Error allocating memory");
        exit(0);}
    if((temp = (LINK*)calloc(strlen(name)+1, sizeof(char))) == NULL){//Adding space in link for new name
        printf("Error allocating memory");
        exit(0);}
    strcpy(temp->name, name);
    if(head == NULL){ //Empty list
        head = temp;
        temp->next = NULL;
        return head;}
    current = head;
    /*if(strcmp(current->name, name) > 0){ //Add to front
        temp->next = current;
        head = temp;
        return head;}
    current = head;*/
    while(current != NULL){ //Add to end
        if(current->next == NULL || strcmp(current->next->name, name) > 0){
            temp->next = current->next;
            current->next = temp;
            return head;}
        current = current->next;}}

void LINK_DELETE(char name[], LINK *(*head)){
    LINK *current, *temp;
    if(LINK_SEARCH(name, (*head)) == 0) return;
    current = (*head);
    if(!strcmp((*head)->name, name)){
        current = current->next;
        free((*head));
        (*head) = current;}
    else{
        while(current->next != NULL){
            if(!strcmp(current->next->name, name)){
                temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;}
            current = current->next;}}}

void LINK_DISPLAY(LINK *head){
    LINK *current;
        current = head;
        while(current != NULL){
            printf("%s\n", current->name);
            current = current->next;}}

LINK *LINK_FREE(LINK *head){
    LINK *current, *temp;
    current = head;
    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp->name);
        free(temp);}
    head = NULL;
    return head;}


int main(int argv, char **argc){
    char *text, *op_code, *name;
    size_t charCount;
    FILE *stream;
    LINK *head;
    if(argv == 1){
        printf("*******************************************\n");
        printf("*  You must include a filename to load.   *\n");
        printf("*******************************************\n");
        exit(0);
    }
    if(argv == 2){
        stream = fopen(argc[1], "r");
        }
        head = NULL;
        while(1){
            text = NULL;
            getline(&text, &charCount, stream);
            name = strtok(text, " ");
            op_code = strtok(NULL, "\n");
            if(feof(stream)) break;
            if(op_code[0] == 'a'){
                head = LINK_INSERT(name, head);}
            else if(op_code[0] = 'd'){
                LINK_DELETE(name, &head);}
            free(text);}
            fclose(stream);
            LINK_DISPLAY(head);
            head = LINK_FREE(head);
            head = NULL;
            return 0;
        }

    //if ((BlackBox = (struct _data*)calloc(size, sizeof(struct _data))) == NULL){
