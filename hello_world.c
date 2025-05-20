#include <stdio.h>
#include <stdint.h>


typedef struct{
char first;
char second;
int32_t size;
} Bitmap;

int main(){

	printf("Hello World\n");

	int value = 4;

	int hexValue = 0xA;

	printf("2+2 = %d\n", hexValue);


	// reading file:

	unsigned char buffer[8];

	Bitmap myLenka;

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

	input_image_file = fopen("lena.bmp", "rb");
	fread(&myLenka, sizeof(Bitmap), 1, input_image_file);

	printf("\nlecimy:\n");
//	printf("\nsizeof unsiened int is %l\n",  sizeof(unsigned int));
	printf("desc:first=%X\n",(myLenka.first));
	printf("desc:sec=%X\n",(myLenka.second));
	int32_t someuint = 66631;
	printf("testinta = %d\n", someuint);
	printf("size=%d\n",(myLenka.size));
	printf("...?");
//@	printf("%.4s", buffer);

	fclose(input_image_file);
	return 0;
}

