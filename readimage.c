#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
	
	char ch;
	
	char buffer[100];
	
	char file_name[25] = "new_image.gif";
	FILE *fp;
	FILE *wp;
	size_t chunk_size = 1;
	int byte_count = 0;
	
	int image_data_position = 0;
	
	//int image_bytes[11] = {0x00, 0x51, 0xFC, 0x1B, 0x28, 0x70, 0xA0, 0xC1, 0x83, 0x01, 0x01};
	int image_bytes[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	fp = fopen(file_name, "r"); // read mode
	wp = fopen("result3.gif", "w");

	if (fp == NULL){
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	printf("The contents of %s file are:\n", file_name);
	
	//printf("%lu", fread(buffer, chunk_size, 1, fp));

	while((fread(buffer, chunk_size, 1, fp)) == chunk_size){
		
		if(byte_count >= 57 && byte_count <= 64){
			buffer[0] = image_bytes[image_data_position];
			image_data_position = image_data_position + 1;
		}
		
		//00 51 FC 1B 28 70 A0 C1 83 01 01
		// 55 - 65 - image data
		
		
		if(byte_count < 1000){
			printf("%i.", byte_count);
			printf("%x: %x\n", byte_count, buffer[0]);
		}
		
		fwrite(buffer, chunk_size, 1, wp);
		
		
		byte_count = byte_count + 1;
	}

	fclose(fp);
	fclose(wp);
	
	return EXIT_SUCCESS;
}