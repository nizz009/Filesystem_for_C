//Creates a single directory in the same filepath as that of the program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


bool create_directory(char s[])
{
   #ifdef _WIN32
   return _mkdir(s);
   #else
   return mkdir(s, 0777);
   #endif
}

int main()
{
   char s[1000] = {'\0'};

   scanf("%s", s);

   if(!create_directory(s))
      printf("Directory Created Successfully.");
   else
      printf("Error!");

   return EXIT_SUCCESS;
}
