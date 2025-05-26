#include <stdio.h>
#include <stdint.h>
// #include <byteswap.h>

#define NTOHL(n) (((((unsigned int)(n) & 0xFF)) << 24) |    \
				  ((((unsigned int)(n) & 0xFF00)) << 8) |   \
				  ((((unsigned int)(n) & 0xFF0000)) >> 8) | \
				  ((((unsigned int)(n) & 0xFF000000)) >> 24))

typedef struct
{
	char first;
	char second;
	uint32_t size;
} Bitmap;

uint32_t to_little_endian(uint32_t x)
{
	return (x << 24) | ((x << 8) & 0x00ff0000) | ((x >> 8) & 0x0000ff00) | (x >> 24);
}
uint32_t again(uint32_t x)
{
	return ((x >> 24 & 0xff) | ((x << 8) & 0xff0000) | ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000));
}
//! Byte swap unsigned int
uint32_t swap_uint32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

int main()
{

	printf("Hello KURyyyyyWA??\n");

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

	for (int i = 0; i < 8; i++)
		printf("%X, ", (unsigned char)buffer[i]);

	printf("second fread:");
	fclose(input_image_file);

	input_image_file = fopen("lena.bmp", "rb");
	fread(&myLenka, sizeof(Bitmap), 1, input_image_file);

	printf("\nlecimy:\n");
	//	printf("\nsizeof unsiened int is %l\n",  sizeof(unsigned int));
	printf("desc:first=%X\n", (myLenka.first));
	printf("desc:sec=%X\n", (myLenka.second));
	// printf("desc:third=%X", myLenka.third);
	uint32_t someuint = 666;
	printf("testinta = %d\n", 2 * someuint);
	printf("size as hex=%X", myLenka.size);
	printf("size=%d\n", (myLenka.size));
	printf("...?");
	printf("\nExpecting size: 786570...\n");
	printf("size simply is %d\n", myLenka.size);
	printf("blargh is %d\n", ((int32_t)(myLenka.size)));
	printf("size may be... =%d\n", to_little_endian(myLenka.size));
	printf("or may be (macro)... =%d\n", NTOHL(myLenka.size));
	printf("experiment: %d\n", to_little_endian(to_little_endian(myLenka.size)));
	//@	printf("%.4s", buffer);

	// printf("yyy byteswap? =%d\n", __bswap_21(myLenka.size));
	printf("swap: %d", swap_uint32(myLenka.size));
	printf("again:%d", again(myLenka.size));
	fclose(input_image_file);
	return 0;
}
