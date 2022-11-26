/************************************************************************
CSCI 330
FALL 2022
PROGRAM : HW3
AUTHOR  : Adam Roy
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct info{
    char str1[20];
    float fltV;
    int intV;
    char str2[20];
} temp;

int scan(void) {
    int size = 0;
    FILE *datafile;
    datafile = fopen("./hw3.data", "r");
    while (1) {
        fscanf(datafile, "%s %f %d %s", temp.str1, &temp.fltV, &temp.intV, temp.str2);
        if (feof(datafile)) break;
        size++;
   }
   fclose(datafile);
   return size;
}

struct info load(int size) {
int i;
FILE *datafile;
   datafile = fopen("./hw3.data", "r");
   struct info *fileinfo;
   fileinfo = (struct info*)calloc(size, sizeof(struct info));
   rewind(datafile);
   for (i = 0; i < size; i++) {
      fscanf(datafile, "%s %f %d %s", fileinfo[i].str1, &fileinfo[i].fltV, &fileinfo[i].intV, fileinfo[i].str2);
   }
   fclose(datafile);
   return *fileinfo;
   free(fileinfo);
}

void sortHighLow(int choice, struct info fileinfo[], int size){
    struct info swapped;
    int i, j;
    for(i = 0; i < size; ++i){
        for(j = i + 1; j < size; ++j){
            if(fileinfo[j].fltV == 0){
                break;}
        if(fileinfo[j].fltV == 0){
            break;}
            if (choice == 1){
                if (fileinfo[i].fltV < fileinfo[j].fltV){
                    swapped = fileinfo[i];
                    fileinfo[i] = fileinfo[j];
                    fileinfo[j] = swapped;}}
            if (choice == 3){
                if (fileinfo[i].intV < fileinfo[j].intV){
                    swapped = fileinfo[i];
                    fileinfo[i] = fileinfo[j];
                    fileinfo[j] = swapped;}}
    }}
    for(i = 0; i <= size; ++i){
        printf("%s %f %d %s\n", fileinfo[i].str1, fileinfo[i].fltV, fileinfo[i].intV, fileinfo[i].str2);
        if(fileinfo[i].fltV == 0){
        break;
        }}
    }

void sortLowHigh(int choice, struct info fileinfo[], int size){
    struct info swapped;
    int i, j;
    for(i = 0; i < size; ++i){
        for(j = i + 1; j < size; ++j){
            if(fileinfo[j].fltV == 0){
                break;}
        if(fileinfo[j].fltV == 0){
            break;}
            if(choice == 2){
                if(fileinfo[i].fltV > fileinfo[j].fltV){
                swapped = fileinfo[i];
                fileinfo[i] = fileinfo[j];
                fileinfo[j] = swapped;}}
            if(choice == 4){
                if(fileinfo[i].intV > fileinfo[j].intV){
                swapped = fileinfo[i];
                fileinfo[i] = fileinfo[j];
                fileinfo[j] = swapped;}}
    }}
    for(i = 0; i <= size; ++i){
        printf("%s %f %d %s\n", fileinfo[i].str1, fileinfo[i].fltV, fileinfo[i].intV, fileinfo[i].str2);
        if(fileinfo[i].fltV == 0){
        break;
        }}
    }

int main(void) {
    struct info fileinfo;
    int size, c;
    
do{
    /* Prints Menu */
    printf("\n\nMENU\n");
    printf("1. Sort data by the float value & print high to low\n");
    printf("2. Sort data by the float value & print low to high\n");
    printf("3. Sort data by the int value & print high to low\n");
    printf("4. Sort data by the int value & print low to high\n");
    printf("5. Exit\n\n");
    printf("ENTER YOUR OPTION: ");
	scanf("%d", &c);

    /* Selects a function based on choice */
    if(c == 1){
        size = scan();
        struct info fileinfo = load(size);
        sortHighLow(1, &fileinfo, size);
        }
    else if(c == 2){
        size = scan();
        struct info fileinfo = load(size);
        sortLowHigh(2, &fileinfo, size);
        }
    else if(c == 3){
        size = scan();
        struct info fileinfo = load(size);
        sortHighLow(3, &fileinfo, size);
        }
    else if(c == 4){
        size = scan();
        struct info fileinfo = load(size);
        sortLowHigh(4, &fileinfo, size);
        }
    else if(c == 5){
            printf("Exiting Program\n");
    }
    } while (c != 5);
    return 0;
};
