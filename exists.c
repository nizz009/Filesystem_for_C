//Analogous to fs::exists(filepath);
//Extracts the file name from the silepath and checks for the existence of the file. 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef _WIN32
const char SEP = '\\';
#else
const char SEP = '/';
#endif

bool exists(char filepath[])
{
    char *temp;
    char *p = filepath;

    while(*(p + 1) != '\0' && (p = strchr(p + 1, SEP)) != NULL)
    {
        temp = p;
    }
    temp++;
    if( access(filepath, F_OK ) != -1 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char filepath[10000] = {'\0'};
   
    scanf("%s", filepath);

    if(exists(filepath))
        printf("The file exists.\n");
    else
        printf("The file doesn't exist.\n");

    return EXIT_SUCCESS;
}