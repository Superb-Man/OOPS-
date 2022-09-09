/*
	author: M Saifur Rahman
	last modified: December 12, 2020
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

//
// Get length of a file
//
long getFileSize(char *strName) {
    int size = -1;

    FILE* fp = fopen(strName, "r");
    if (!fp)
        return -1;

    int retVal = fseek(fp, 0, SEEK_END);
    if (retVal)
        return -1;
    size = ftell(fp);
    fclose(fp);

    return size;
}

int main(int argc, char *argv[]) {

    char buf[256];
    long int size;
    size_t x;

   while (1) {
        gets(buf);
        printf("Size of %s is: %d\n", buf, getFileSize(buf));
    }
    return 0;
}
