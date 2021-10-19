#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
print_results(char commit[200]){
  
  FILE *fileOutput;
  char chinner;
  char command[200];
  
  command[0] = '\0';
      
  fprintf(stdout, "\n commits: \n%s", commit);
  
  strcat(command, "git show ");
  strcat(command, commit);
  strcat(command, ":runner.c");
  
  
  printf("\n\n\n%s\n\n", command);
  
  fileOutput = popen(command, "r");
  
  while( (chinner=fgetc(fileOutput)) != EOF){
    putchar(chinner); 
  }
  
  
  printf("\n\n\n");
}

int
main (void)
{
  FILE *output;
  char ch;
  
  
  char commit[200];
  
  
  int count = 0;

  output = popen("git log --pretty=format:%H --follow runner.c", "r");
  
  if (!output)
    {
      fprintf (stderr,
               "incorrect parameters or too many files.\n");
      return EXIT_FAILURE;
    }
  
  while( (ch=fgetc(output)) != EOF){
    //putchar(ch);
    
    if(ch != '\n'){
      commit[count] = ch;
      count = count + 1;
    }else{
      
      print_results(commit);
      count = 0;
      
    }
    
    
  }
  
  
  //git show 8b1de9809962e034d934ed48bebf9362e00d5f40:runner.c
  
  pclose(output);
  
  print_results(commit);  
  
  return EXIT_SUCCESS;
}