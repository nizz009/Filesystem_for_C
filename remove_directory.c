//Analogous to fs::remove_all(filepath);
//Deletes the folder using its filepath including all its contents.
//Uses recursion to tranverse the folder tree and deletes them on the order of their sequence. 

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

bool remove_directory(char filepath[])
{
    DIR *folder;
    struct dirent *entry;
    //To show the name of the directory to be created(temp) and the path(dir)
    char *temp;
    char dir[1000] = { '\0' };
    int posdir = 0, postemp = 0;
    const char *p;
    const char *q;

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

    folder = opendir(filepath);
    while( (entry=readdir(folder)) )
    {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
        {
            continue;
        }
        else
        {
            q = entry->d_name;
        
            // determinate a full path of an entry
            temp = calloc(strlen(filepath) + strlen(entry->d_name) + 1, sizeof(char));
            strcpy(temp, filepath);
            #ifdef _WIN32
            strcat(temp, "\\");
            #else
            strcat(temp, "/");
            #endif
            strcat(temp, entry->d_name);

            //if the content is a folder
            if((q = strchr(entry->d_name, '.')) == NULL)
            {
                remove_directory(temp);
            }
            //content is a file
            else
            {
                remove(temp);
            }
        }
    }

    rmdir(filepath);
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
