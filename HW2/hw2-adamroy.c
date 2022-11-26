#include <stdio.h>
#include <stdlib.h>

struct info{
    char str1[20];
    float fltV;
    int intV;
    char str2[20];
};
struct info fileinfo[101];

void openFile(struct info fileinfo[101]){
    FILE *datafile;
    int i = 0;
    datafile = fopen("hw2.data", "r");
    while(fscanf(datafile, "%s %f %d %s", fileinfo[i].str1, &fileinfo[i].fltV, &fileinfo[i].intV, fileinfo[i].str2) != EOF){
        i++;
    }
    fclose(datafile);
}

void sortHighLow(int choice){
    int i, j, temp;
    openFile(fileinfo);
    for(i = 0; i <= 100; i++){
        for(j = i + 1; i < 100; ++j){
            if(fileinfo[j].fltV == 0){
                break;}
        if(fileinfo[j].fltV == 0){
            break;}
            if(choice == 1){
                if(fileinfo[i].fltV < fileinfo[j].fltV){
                    fileinfo[101] = fileinfo[i];
                    fileinfo[i] = fileinfo[j];
                    fileinfo[j] = fileinfo[101];}}
            if(choice == 3){
                if(fileinfo[i].intV < fileinfo[j].intV){
                    fileinfo[101] = fileinfo[i];
                    fileinfo[i] = fileinfo[j];
                    fileinfo[j] = fileinfo[101];}}
    }}
    for(i = 0; i < 100; i++){
        printf("%s %f %d %s\n", fileinfo[i].str1, fileinfo[i].fltV, fileinfo[i].intV, fileinfo[i].str2);
        if(fileinfo[i].fltV == 0){
        break;
        }}
    }

void sortLowHigh(int choice){
    int i, j, temp;
    openFile(fileinfo);
    for(i = 0; i <= 100; i++){
        for(j = i + 1; i < 100; ++j){
            if(fileinfo[j].fltV == 0){
                break;}
        if(fileinfo[j].fltV == 0){
            break;}
            if(choice == 2){
                if(fileinfo[i].fltV > fileinfo[j].fltV){
                fileinfo[101] = fileinfo[i];
                fileinfo[i] = fileinfo[j];
                fileinfo[j] = fileinfo[101];}}
            if(choice == 4){
                if(fileinfo[i].intV > fileinfo[j].intV){
                fileinfo[101] = fileinfo[i];
                fileinfo[i] = fileinfo[j];
                fileinfo[j] = fileinfo[101];}}
    }}
    for(i = 0; i < 100; i++){
        printf("%s %f %d %s\n", fileinfo[i].str1, fileinfo[i].fltV, fileinfo[i].intV, fileinfo[i].str2);
        if(fileinfo[i].fltV == 0){
        break;
        }}
    }

int main(void) {
    int c;
    do{
        /* Prints Menu */
        printf("1. Sort data by the float value & print high to low\n");
        printf("2. Sort data by the float value & print low to high\n");
        printf("3. Sort data by the int value & print high to low\n");
        printf("4. Sort data by the int value & print low to high\n");
        printf("5. Exit\n\n");
        scanf("%d", &c);

        /* Selects a function based on choice */
        if(c == 1){
            sortHighLow(1);
            }
        else if(c == 2){
            sortLowHigh(2);
            }
        else if(c == 3){
            sortHighLow(3);
            }
        else if(c == 4){
            sortLowHigh(4);
            }
        else if(c == 5){
            printf("Exiting Program\n");}
        else{
            printf("Not a valid option\n");}
    } while (c != 5);
    return 0;
};

