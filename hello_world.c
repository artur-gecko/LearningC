#include <stdio.h>

int main(){

	printf("Hello World\n");

	int value = 4;

	int hexValue = 0xA;

	printf("2+2 = %d\n", hexValue);


	// reading file:

	unsigned char buffer[8];
	FILE *input_image_file;

	input_image_file = fopen("lena.bmp", "rb");

	fread(buffer, sizeof(buffer), 1, input_image_file);
	
	printf("Here are the first few bytes\n");
	printf("%.4s", buffer);

	printf("\nAs ints:\n");

	for(int i = 0; i<8;i++)
		printf("%X, ", (unsigned char)buffer[i]);
	
	printf("second fread:");
	fclose(input_image_file);
	fread(buffer, sizeof(buffer), 1, input_image_file);

	printf("\n\lecimy:\n");

	printf("%.4s", buffer);

	return 0;
}

