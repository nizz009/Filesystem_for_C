//Opens and writes data into a file with a given filepath
//Creates one if the file or any of the directories don't exist. 

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

bool create_directory(char s[])
{
   #ifdef _WIN32
   return _mkdir(s);
   #else
   return mkdir(s, 0755);
   #endif
}

bool write_to_file(char filepath[], char data[])
{
   //To show the name of the directory to be created(temp) and the path(dir)
   char temp[1000] = { '\0' };
   char dir[1000] = { '\0' };
   int posdir = 0, postemp = 0, flag = 0;
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
      postemp = 0;
      while(*p != '\0' && *p != SEP)
      {
         temp[postemp++] = *p;
         if(*p == '.')
         {
            flag = 1;
         }
         p++;
      }

      temp[postemp++] = '\0';

      chdir(dir);
      if(!flag)
      {
         if(create_directory(temp) == -1)
         {
            return false;
         }
         else
         {
            p++;
         }

         dir[posdir++] = SEP;

         for(postemp = 0; temp[postemp] != '\0'; postemp++)
         {
            dir[posdir++] = temp[postemp];
         }
         dir[posdir + 1] = '\0';
      }

      else
      {
         FILE *file_pointer = fopen(temp, "w");
         fprintf(file_pointer, "%s", data);
      }
   }

   return true;
}

int main()
{
   char filepath[10000] = {'\0'};
   char data[1000] = { '\0' };
   
   scanf("%s %s", filepath, data);

   write_to_file(filepath, data);

   return EXIT_SUCCESS;
}