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

bool create_directory(char s[])
{
   #ifdef _WIN32
   return _mkdir(s);
   #else
   return mkdir(s, 0755);
   #endif
}

bool create_directories(char filepath[])
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
      postemp = 0;
      while(*p != '\0' && *p != SEP)
      {
         temp[postemp++] = *p;
         p++;
      }

      temp[postemp++] = '\0';

      chdir(dir);
      if(create_directory(temp) == -1)
         return false;
      else
         p++;

      dir[posdir++] = SEP;

      for(postemp = 0; temp[postemp] != '\0'; postemp++)
         dir[posdir++] = temp[postemp];
      
      dir[posdir + 1] = '\0';
   }

   return true;
}

int main()
{
   char filepath[10000] = {'\0'};
   
   scanf("%s", filepath);

   if(create_directories(filepath))
      printf("Directories Created.");
   else
      printf("Error!");

   return EXIT_SUCCESS;
}
