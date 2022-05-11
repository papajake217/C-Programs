#include <stdio.h>

int main(){
    printf("Enter a hexadecimal value: ");
    unsigned char hex;
    scanf("%x", &hex);
    printf("The decimal value is %i", hex);
}