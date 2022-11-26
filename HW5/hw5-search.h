#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _structure_
#define _structure_
struct _data {
    char *name;
    long number;
};
#endif

void SEARCH(struct _data *, char *, int);