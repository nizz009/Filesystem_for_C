#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


bool create_directory(char s[], char filepath[])
{
   #ifdef _WIN32
   return _mkdir(s, filepath);
   #else
   return mkdir(s, filepath, 0777);
   #endif
}

int main()
{
   char s[1000] = {'\0'};
   char filepath[10000] = {'\0'};

   scanf("%s %s", s, filepath);

   if(!create_directory(s, filepath))
      printf("Directory Created.");
   else
      printf("Error!");

   return EXIT_SUCCESS;
}