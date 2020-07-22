//Analogous to fs::create_directories(filepath)
//Creates multiple directies (Nested) without the use of recursion

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

bool remove_directory(char filepath[])
{
    //To show the name of the directory to be created(temp) and the path(dir)
    char temp[1000] = { '\0' };
    char dir[1000] = { '\0' };
    int posdir = 0, postemp = 0;
    const char *p;

    p = filepath;
    dir[posdir++] = *p;
    #ifdef _WIN32
    if ((p = strchr(filepath, ':')) != NULL)
    {
        dir[posdir++] = *p;
        p++;
    }
    #endif
   
    dir[posdir++] = *p;
    dir[posdir + 1] = '\0';
    p++;

    while(*p != '\0')
    {
        
    }

    return true;
}

int main()
{
    char filepath[10000] = {'\0'};
   
    scanf("%s", filepath);

    if(remove_directory(filepath))
        printf("Directories Removed.");
    else
        printf("Error!");

    return EXIT_SUCCESS;
}