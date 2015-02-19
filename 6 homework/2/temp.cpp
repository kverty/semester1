#include <stdio.h>

void func(FILE *file, int n)
{
    int i;
    fscanf(file, "%d", &i);
    printf("%d ", i);
    if (i != 0)
        func(file, 0);
}
int main()
{
FILE *file;
char* file_name = "file.txt";

file = fopen( file_name, "r" );
func(file, 0);
fclose( file );
}
