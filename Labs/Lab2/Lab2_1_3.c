#include <stdio.h>

int main(){
    unsigned char a,b;
	printf("Type a hexadecimal in: ");
	scanf("%x", &a);
	b = 0xF;
	a = a|b;
	printf("Output: %x", a);
	
}