#include <stdio.h>
#include <stdlib.h>


int
main (void)
{
  FILE *output;
  char ch;
  
  char commit[100];
  
  int count = 0;

  output = popen("git log --pretty=format:%H --follow runner.c", "r");
  
  if (!output)
    {
      fprintf (stderr,
               "incorrect parameters or too many files.\n");
      return EXIT_FAILURE;
    }
  
  while( (ch=fgetc(output)) != EOF){
    putchar(ch);
    commit[count] = ch;
    
    count = count + 1;
  }
  
  pclose(output);
  
  fprintf(stdout, "\n commits: \n%s", commit);
    
  return EXIT_SUCCESS;
}