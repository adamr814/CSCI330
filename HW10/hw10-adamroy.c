//Adam Roy
//CSCI 330
//HW10

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Clear PGM (XV) comments (This is pasted code from assignment sheet) */
void pgmCommentClear(FILE *disk){
unsigned char ch;
   fread(&ch, 1, 1, disk);
   if (ch != '#') {
      fseek(disk, -1, SEEK_CUR);
      return;
   }
   do {
      while (ch != '\n') fread(&ch, 1, 1, disk);
   } while (ch == '#');
   pgmCommentClear(disk);}

/* Read PGM formatted image (1D array) (This is pasted code from assignment sheet) */
unsigned char *PGM_FILE_READ_1D(char *FileName, int *Width, int *Height, int *color) { 
int   pmax;
char  ch;
char  type[3];
unsigned char *Image;
FILE *disk;
   if ((disk = fopen(FileName, "rb")) == NULL) {
      return NULL;
   }
   fscanf(disk, "%s", type);
   if (!strcmp(type, "P6")) *color = 1;
                       else *color = 0;
   fread(&ch, 1, 1, disk); 
   pgmCommentClear(disk);
   fscanf(disk, "%d", Width);
   fscanf(disk, "%d", Height);
   fscanf(disk, "%d", &pmax);
   fread(&ch, 1, 1, disk);
   if (*color == 1) {
      Image = (unsigned char *)calloc(*Height * *Width * 3, sizeof(unsigned char));
      fread(Image, 1, (*Height * *Width * 3), disk);
   } else {
      Image = (unsigned char *)calloc(*Height * *Width, sizeof(unsigned char));
      fread(Image, 1, (*Height * *Width), disk);
  }
   fclose(disk);
   return Image;
}

int main(void){
    char *file = "hw10.pgm";
    int width, height, colorCode, size, array[8], Count=0;
    unsigned char *Image;
    Image = PGM_FILE_READ_1D(file, &width, &height, &colorCode);
    size = ((height*width)/100);
    for(int i=0; i<size/8; i++){
        int bitCollect=0;
        if(Count>2){break;}
        for(int k=0; k<8; k++){
            bitCollect = (bitCollect << 1)+(Image[i*8+k] & 1);
            if(bitCollect == 'x'){
                Count++;}}
        printf("%c", bitCollect);
    }
    printf("\n");
    return 0;}