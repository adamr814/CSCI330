//Adam Roy
//CSCI 330
//HW7

#include <stdio.h>
#include <stdlib.h>

struct Tree{
    int val;
    struct Tree *right, *left, *next;};

struct Node{
    struct Node *next;
    struct Tree *tree;};

void TREE_INSERT(struct Tree *(*tree), struct Tree *item){
    if (!(*tree)){
        *tree = item;
        return;
    }
    if(item->val < (*tree)->val) TREE_INSERT(&(*tree)->left, item);
    else if(item-> val > (*tree)->val) TREE_INSERT(&(*tree)->right, item);}

void Sort_Array(int input[], int first, int last, int output[]){
    int middle;
    static int count = 0;
    if(first > last) return;
    middle = (first + last)/2;
    output[count] = input[middle];
    count++;
    Sort_Array(input, first, middle - 1, output);
    Sort_Array(input, middle + 1, last, output);}

void TRAVERSE_PREORDER(struct Tree *tree){
    printf("%3d ", tree->val);
    if(tree->left != NULL) TRAVERSE_PREORDER(tree->left);
    if(tree->right != NULL) TRAVERSE_PREORDER(tree->right);}

void TRAVERSE_INORDER(struct Tree *tree){
    if(tree->left != NULL) TRAVERSE_INORDER(tree->left);
    printf("%3d ", tree->val);
    if(tree->right != NULL) TRAVERSE_INORDER(tree->right);}

void TRAVERSE_POSTORDER(struct Tree *tree){
    if(tree->left != NULL) TRAVERSE_POSTORDER(tree->left);
    if(tree->right != NULL) TRAVERSE_POSTORDER(tree->right);
    printf("%3d ", tree->val);}

void TRAVERSE_LIST(struct Node *list){ //Extra values due to pointers pointing to same position in tree
    struct Node *current;
    current = list;
    while(current != NULL){
        printf("%d ", current->tree->val);
        current = current->next;}}

void FREE(struct Node *head){
    struct Node *current, *temp;
    current = head;
    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp->tree);
        free(temp);}}

int main(void){
FILE *data;
data = fopen("hw7.data", "r");
int *dataArray, n, temp, *array, *dataVal, mid, *sorted;
int size = 0, i = 0;
struct Tree *current, *root;
struct Node *ptr, *head;
root = NULL;
head = NULL;
dataVal = (int*)malloc(sizeof(int));
while(1){
    fscanf(data, "%d", dataVal);
    if(feof(data)) break;
    size++;}
rewind(data);
dataArray = (int*)malloc(size*sizeof(int));
while(1){
    fscanf(data, "%d", dataVal);
    if(feof(data)) break;
    dataArray[i] = *dataVal;
    i++;}
fclose(data);
for(i=0; i < size; i++){
    for(int j = 0; j < size; j++){
        if(dataArray[j] > dataArray[j + 1]){
            temp = dataArray[j];
            dataArray[j] = dataArray[j + 1];
            dataArray[j + 1] = temp;}}}
sorted = (int*)calloc(size, sizeof(int));
Sort_Array(dataArray, 0, size, sorted);
for(i = 0; i < size; i++){
    current = (struct Tree *)malloc(sizeof(struct Tree)); //Build Tree
    current->left = current->right = NULL;
    current->val = sorted[i];
    TREE_INSERT(&root, current);
    ptr = (struct Node *)malloc(sizeof(struct Node)); //Build linked list pointing to tree nodes
    ptr->tree = current;
    ptr->next = head;
    head = ptr;}
    free(dataArray);
    printf("Print Preorder: \n");
    TRAVERSE_PREORDER(root);
    printf("\n\nPrint Inorder: \n");
    TRAVERSE_INORDER(root);
    printf("\n\nPrint Postorder: \n");
    TRAVERSE_POSTORDER(root);
    printf("\n\nPrint List: \n");
    TRAVERSE_LIST(head);
    FREE(head);
    return 0;
}