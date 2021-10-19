#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
	
	char ch;
	
	char buffer[100];
	
	char file_name[25] = "test_image.gif";
	FILE *fp;
	FILE *wp;
	size_t chunk_size = 1;

	fp = fopen(file_name, "r"); // read mode
	wp = fopen("result.gif", "w");

	if (fp == NULL){
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	printf("The contents of %s file are:\n", file_name);
	
	//printf("%lu", fread(buffer, chunk_size, 1, fp));

	while((fread(buffer, chunk_size, 1, fp)) == chunk_size){
		
		fwrite(buffer, chunk_size, 1, wp);
		
	}

	fclose(fp);
	
	return EXIT_SUCCESS;
}