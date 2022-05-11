#include <stdio.h>
    /*1)	Write a C program that reads a hexadecimal value from the keyboard and then stores the value into an unsigned 
    char variable. Read two int values p and n from the keyboard, where the values are less than 8. Change the initial 
    hexadecimal value in the following way: Shift the n bits starting at position p, so that they form the n least significant 
    bits of the result. The remaining bits of the result are set to 0. Display the result using printf %x. */
int main(){
    unsigned char val;
    int p,n;
    printf("Enter a hexadecimal value: ");
    scanf("%x", &val);
    printf("Enter p (int less than 8): ");
    scanf("%d", &p);
    printf("Enter n (int less than 8): ");
    scanf("%d", &n);
    p = 7 - p;
    n = 8 - n;
    val = val << p;
    val = val >> n;
    printf("Output: %x", val);
    
}