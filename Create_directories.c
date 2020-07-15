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
   return mkdir(s, 0777);
   #endif
}

bool create_directories(char files[])
{
   char temp[1000] = { '\0' };
   int pos = 0;
   const char *p;

   p = files;
   #ifdef _WIN32
   if ((p = strchr(files, ':')) != NULL)
      p++;
   #endif

   p++;
   while(*p != '\0')
   {
      pos = 0;
      while(*p != '\0' && *p != SEP)
      {
         temp[pos++] = *p;
         p++;
      }

      temp[pos++] = '\0';

      if(create_directory(temp) == -1)
      {
         return false;
      }
      else
      {
         p++;
      }
   }

   return true;
}

int main()
{
   char files[10000] = {'\0'};

   scanf("%s", files);

   if(create_directories(s, files))
      printf("Directories Created.");
   else
      printf("Error!");

   return EXIT_SUCCESS;
}