
//Mark Droessler

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *word;
    struct node *next;
};

struct codex {
    char *word1;
    char *word2;
    struct codex *next;
};

//Function to read the words of hw8data.txt
struct node* readPoem(char *word, struct node* head){
    struct node *current, *tempNode;
    tempNode = (struct node*)malloc(sizeof(struct node));
    tempNode->word = (char *)malloc(sizeof(word));
    strcpy(tempNode->word, word);
    if (head == NULL) {
        tempNode->next = NULL;
        head = tempNode;
        return head;
    }
    else {
        current = head;
        while(current != NULL) {
            if(current->next == NULL){ 
                current->next = tempNode;
                tempNode->next = NULL;
                return head;
            }
            current = current->next;
        }
    }
}

//Function to read the wrods of hw8codex.txt
struct codex* allocateCodex(char *word1, char *word2, struct codex* head){
    struct codex *current, *tempCodex;
    tempCodex = (struct codex*)malloc(sizeof(struct codex));
    tempCodex->word1 = (char *)malloc(sizeof(word1));
    tempCodex->word2 = (char *)malloc(sizeof(word2));
    strcpy(tempCodex->word1, word1);
    strcpy(tempCodex->word2, word2);    
    if(head == NULL) {
        tempCodex->next = NULL;            
        head = tempCodex;
        return head;
    }
    else {
        current = head;
        while(current != NULL){
            if(current->next == NULL){
                current->next = tempCodex;
                tempCodex->next = NULL;
                //printf("Successfully added to the codex linked list\n");
                return head;
            }
            current = current->next;
        }    
    }
}
//Function to replace the words from hw8data.txt with hw8codex.txt list
struct node* replacementFunction(struct node* main, struct codex* headCodex) {
    struct node *head;
    struct codex *replacement;
    head = main;
    replacement = headCodex;
    while(head->next != NULL) {
        while (1) {
            if (strcmp(replacement->word1, head->word) == 0) {
                if (strcmp(replacement->word2, "skip") == 0) {
                    head->word = "";
                    break;
                }
                head->word = replacement->word2;
                break;
            }
            if (replacement->next == NULL) {
                break;
            }
            replacement = replacement->next;
        }
        if (head->next == NULL) {
            break;
        }
        head = head->next;
        replacement = headCodex;
    }
    return main;
}
//Function to print the poem 
void printPoem(struct node* head) {
    struct node *current, *toBePrinted;
    current = head;
    while(1) {
        toBePrinted = current;
        if (strcmp(toBePrinted->next->word, ",") == 0 || strcmp(toBePrinted->next->word, ".") == 0) {
            printf("%s%s\n", toBePrinted->word, toBePrinted->next->word);
            current = current->next;
        }
        else {
            printf("%s ", toBePrinted->word);
        }
        if (current->next == NULL) {
            break;
        }
        current = current->next;
    }
}
//Function to free the linked lists
void freeFunc(struct node* list1, struct codex* list2) {
    struct node *current, *next;
    struct codex *currentC, *nextC;
    current = list1;
    while (current != NULL){   
        next = current->next;
        free(current);
        current = next;
    }
    currentC = list2;
    while (currentC != NULL){   
        nextC = currentC->next;
        free(currentC);
        currentC = nextC;
    }
}    


int main(void){
    struct codex *headCodex;
    char *text, *word1, *word2, *wordTest, *chr;
    size_t chrCount;
    headCodex = NULL;    
    FILE *codex, *data;
    wordTest = malloc(sizeof(char));    
    word1 = malloc(sizeof(char));
    word2 = malloc(sizeof(char));
    chr = malloc(sizeof(char));
    //Reading the data file and making linked list
    struct node *headNode;
    headNode = NULL;     
    data = fopen("./hw9data.txt", "r");
    while(!feof(data)) {        
        fscanf(data, "%s", wordTest);
        if(wordTest[strlen(wordTest)-1] == '.') {
            strcpy(chr, ".\0");
            wordTest[strlen(wordTest)-1] = '\0';
            headNode = readPoem(wordTest, headNode);
            headNode = readPoem(chr, headNode);
        }
        else if(wordTest[strlen(wordTest)-1] == ',') {
            strcpy(chr, ",\0");
            wordTest[strlen(wordTest)-1] = '\0';
            headNode = readPoem(wordTest, headNode);
            headNode = readPoem(chr, headNode);
        }
        else {
            headNode = readPoem(wordTest, headNode);
        }
    }
    fclose(data);
    //Reading the codex file and making the linked list
    codex = fopen("./hw9codex.txt", "r");   
    while(!feof(codex)) {        
        fscanf(codex, "%s %s", word1, word2);     
        headCodex = allocateCodex(word1, word2, headCodex);
    }
    fclose(codex);
    headNode = replacementFunction(headNode, headCodex);
    printPoem(headNode);
    free(wordTest);
    free(word1);
    free(word2);
    free(chr);
    freeFunc(headNode, headCodex);
    return 0;
}