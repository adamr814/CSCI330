//Adam Roy
//HW9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char *word;
    struct node *next;};

struct codex{
    char *word1;
    char *word2;
    struct codex *next;};

struct node* readWords(char *word, struct node* head){
    struct node *current, *tempNode;
    tempNode = (struct node*)malloc(sizeof(struct node));
    tempNode->word = (char *)malloc(sizeof(word));
    strcpy(tempNode->word, word);
    if(head == NULL){
        tempNode->next = NULL;
        head = tempNode;
        return head;}
    else{
        current = head;
        while(current != NULL){
            if(current->next == NULL){
                current->next = tempNode;
                tempNode->next = NULL;
                return head;}
        current = current->next;}}}

struct codex* readCodex(char *word1, char *word2, struct codex* head){
    struct codex *current, *tempCodex;
    tempCodex = (struct codex*)malloc(sizeof(struct codex));
    tempCodex->word1 = (char *)malloc(sizeof(word1));
    tempCodex->word2 = (char *)malloc(sizeof(word2));
    strcpy(tempCodex->word1, word1);
    strcpy(tempCodex->word2, word2);
    if(head == NULL){
        tempCodex->next = NULL;
        head = tempCodex;
        return head;}
    else{
        current = head;
        while(current != NULL){
            if(current->next == NULL){
                current->next = tempCodex;
                tempCodex->next = NULL;
                return head;}
        current = current->next;}}}

struct node* swapFunc(struct node* main, struct codex* headCodex){
    struct node *head;
    struct codex *swap;
    head = main;
    swap = headCodex;
    while(head->next != NULL){
        while(1){
            if(strcmp(swap->word1, head->word) == 0){
                if(strcmp(swap->word2, "skip") == 0){
                    head->word = "";
                    break;}
                head->word = swap->word2;
                break;}
            if(swap->next == NULL){
                break;}
            swap = swap->next;}
        if(head->next == NULL){
            break;}
        head = head->next;
        swap = headCodex;}
    return main;}

void printFunc(struct node* head){
    struct node *current, *toPrint;
    current = head;
    while(current->next != NULL /*1*/){
        toPrint = current;
        if(strcmp(toPrint->next->word, ",") == 0 || strcmp(toPrint->next->word, ".") == 0){
            printf("%s%s\n", toPrint->word, toPrint->next->word);
            current = current->next;}
        else{
            printf("%s ", toPrint->word);}
        //if(current->next == NULL){
            //break;}
        current = current->next;}}

void freeFunc(struct node* wordList, struct codex* codexList){
    struct node *currentA, *nextA;
    struct codex *currentB, *nextB;
    currentA = wordList;
    while(currentA != NULL){
        nextA = currentA->next;
        free(currentA);
        currentA = nextA;}
    currentB = codexList;
    while(currentB != NULL){
        nextB = currentB->next;
        currentB = nextB;}}

int main(void){
    struct codex *headCodex;
    char *text, *word1, *word2, *wordCheck, *chr;
    size_t chrCount;
    headCodex = NULL;
    FILE *codex, *data;
    wordCheck = malloc(sizeof(char));
    word1 = malloc(sizeof(char));
    word2 = malloc(sizeof(char));
    chr = malloc(sizeof(char));
    struct node *headNode;
    headNode = NULL;
    data = fopen("./hw9data.txt", "r");
    while(!feof(data)){
        fscanf(data, "%s", wordCheck);
        if(wordCheck[strlen(wordCheck)-1] == '.'){
            strcpy(chr, ".\0");
            wordCheck[strlen(wordCheck)-1] = '\0';
            headNode = readWords(wordCheck, headNode);
            headNode = readWords(chr, headNode);}
        else if(wordCheck[strlen(wordCheck)-1] == ','){
            strcpy(chr, ",\0");
            wordCheck[strlen(wordCheck)-1] = '\0';
            headNode = readWords(wordCheck, headNode);
            headNode = readWords(chr, headNode);}
        else{
        headNode = readWords(wordCheck, headNode);}}
fclose(data);
codex = fopen("./hw9codex.txt", "r");
while(!feof(codex)){
    fscanf(codex, "%s %s", word1, word2);
    headCodex = readCodex(word1, word2, headCodex);}
fclose(codex);
headNode = swapFunc(headNode, headCodex);
printFunc(headNode);
free(wordCheck);
free(word1);
free(word2);
free(chr);
freeFunc(headNode, headCodex);
return 0;}