//Opens, read and writes the data from a file with a given filepath 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef _WIN32
const char SEP = '\\';
#else
const char SEP = '/';
#endif

void read_from_file(char filepath[])
{
   char data[1000] = { '\0' };
   FILE *file_pointer = fopen(filepath, "r");

   fscanf(file_pointer, "%[^\n]", data);
   printf("%s", data);
   fclose(file_pointer);
}

int main()
{
   char filepath[10000] = { '\0' };
   
   scanf("%s", filepath);

   read_from_file(filepath);

   return EXIT_SUCCESS;
}