#include <stdio.h>
// Write a C program to count the number of leading bits 0 in a binary number of length 4 bytes
int main(){
    int size = 32;
    int check = 0;
    char bytes[32];
    int i = 0;
    int countZeros = 0;
    printf("Enter a 4 byte number (no spaces): ");
    scanf("%s", &bytes);
    while(check == 0){
        if (bytes[i] == '0'){
            countZeros += 1;
            i += 1;
        }
        if (bytes[i] == '1'){
            check = 1;
        }
    }
    printf("Number of leading bits 0: %d", countZeros);
}