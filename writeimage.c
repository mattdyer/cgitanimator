#include <stdio.h>
#include <stdlib.h>

void
writeBytes(int bytestowrite[], int size, FILE* stream){
	
	size_t chunk_size = 1;
	
	for (int i = 0; i < size; ++i){
		
		printf("%i\n", i);
		
		fwrite(&bytestowrite[i], chunk_size, 1, stream);
	}
}

int
main (void)
{
	
	char file_name[25] = "new_image.gif";
	FILE *wp;
	
	int header_bytes[6] = {
		0x47,
		0x49,
		0x46,
		0x38,
		0x37,
		0x61
	};
	
	int image_size_bytes[4] = {
		0x03,
		0x00,
		0x0a,
		0x00
	};
	
	int image_color_bytes[40] = {
		0xa2,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x65,
		0x65,
		0x65,
		0x8f,
		0x8f,
		0x8f,
		0xed,
		0xed,
		0xed,
		0xf5,
		0xf5,
		0xf5,
		0xff,
		0xff,
		0xff,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x21,
		0xf9,
		0x04,
		0x09,
		0x00,
		0x00,
		0x06,
		0x00,
		0x2c,
		0x00,
		0x00,
		0x00,
		0x00
	};
	
	//size bytes written again here
	
	int data_info_bytes[3] = {0x00, 0x03, 0x10};
	
	int image_data_bytes[16] = {
		0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00
	};
	
	int footer_bytes[3] = {0x00, 0x3b};
	
	//int image_bytes[11] = {0x00, 0x51, 0xFC, 0x1B, 0x28, 0x70, 0xA0, 0xC1, 0x83, 0x01, 0x01};
	
	wp = fopen(file_name, "w");

	if (wp == NULL){
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	
	writeBytes(header_bytes, sizeof(header_bytes) / sizeof(header_bytes[0]), wp);
	writeBytes(image_size_bytes, sizeof(image_size_bytes) / sizeof(image_size_bytes[0]), wp);
	writeBytes(image_color_bytes, sizeof(image_color_bytes) / sizeof(image_color_bytes[0]), wp);
	writeBytes(image_size_bytes, sizeof(image_size_bytes) / sizeof(image_size_bytes[0]), wp);
	writeBytes(data_info_bytes, sizeof(data_info_bytes) / sizeof(data_info_bytes[0]), wp);
	writeBytes(image_data_bytes, sizeof(image_data_bytes) / sizeof(image_data_bytes[0]), wp);
	writeBytes(footer_bytes, sizeof(footer_bytes) / sizeof(footer_bytes[0]), wp);
	
	fclose(wp);
	
	return EXIT_SUCCESS;
}