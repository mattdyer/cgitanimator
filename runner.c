#include <stdio.h>
#include <stdlib.h>


int
main (void)
{
  FILE *output;
  char ch;

  output = popen("git log --pretty=format:%H --follow runner.c", "r");
  
  if (!output)
    {
      fprintf (stderr,
               "incorrect parameters or too many files.\n");
      return EXIT_FAILURE;
    }
  
  while( (ch=fgetc(output)) != EOF){
    putchar(ch);
  }
  
  pclose(output);
    
  return EXIT_SUCCESS;
}