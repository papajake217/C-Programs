#include <stdio.h>

int main() {
    unsigned int value1 = 5;
    unsigned short value2 = 32;
    unsigned char value3 = 10;
    unsigned long value4 = 200;

    printf("The size of the char is %i \n", sizeof(value3));
    printf("The size of the short is %i \n", sizeof(value2));
	printf("The size of the int is %i \n", sizeof(value1));
	printf("The size of the long is %i \n", sizeof(value4));
	
}
