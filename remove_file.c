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

int main()
{
   char filepath[10000] = { '\0' };
    
   scanf("%s", filepath);
   remove(filepath);

   return EXIT_SUCCESS;
}