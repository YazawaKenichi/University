#include <stdio.h>

void main()
{
    FILE *filepointer;
    char filename[1024] = "FILEstructuretest.bat";
    filepointer = fopen(&filename[0], "a+");
    fprintf(filepointer, "echo write FILE\n");
    fprintf(filepointer, "type FILEstructuretest.bat\n");
    fclose(filepointer);
    
}
