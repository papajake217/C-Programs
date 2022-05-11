#include <stdio.h>

int main(){
    unsigned char one = 0x12;
	printf("0x12 in hex: %x \n", one);
	printf("0x12 in decimal: %d \n", one);
	printf("0x12 in character: %c \n", one);
	
	unsigned char two = 0xda;
	
	printf("0xda in hex: %x \n", two);
	printf("0xda in decimal: %d \n", two);
	printf("0xda in character: %c \n", two);
	unsigned char three = 0x3b;
	
	printf("0x3b in hex: %x \n", three);
	printf("0x3b in decimal: %d \n", three);
	printf("0x3b in character: %c \n", three);
	unsigned char four = 0xbe;
	
	printf("0xbe in hex: %x \n", four);
	printf("0xbe in decimal: %d \n", four);
	printf("0xbe in character: %c \n", four);
	
	printf("Each different format specifier changes how the char is represented, it is either represented as hexadecimal, a signed integer, or a character");
	printf("\n");
	
	unsigned char andOne = one & two;
	printf("First two vars compared with AND operatior is %x \n", andOne);
	unsigned char orOne = one | two;
	printf("First two vars compared with OR operator is %x \n", orOne);
	unsigned char exclusiveOrOne = one ^ two;
	printf("First two vars compared with XOR operator is %x \n", exclusiveOrOne);
	unsigned char andLast = three & four;
	unsigned char orLast = three | four;
	unsigned char exclusiveOrLast = three ^ four;
	printf("Last two vars compared with AND operatior is %x \n", andLast);
	printf("Last two vars compared with OR operator is %x \n", orLast);
	printf("Last two vars compared with XOR operator is %x \n", exclusiveOrLast);
	
}