#include <stdio.h>

int main(){
    printf("Enter a 4 byte binary number: ");
    int i,countOnes,countZeros,checker;
    char bytes[32];
    scanf("%s", &bytes);
   
    countOnes = 0;
    countZeros = 0;
    for(i=0;i<32;i++){
        if (bytes[i] == '1'){
            countOnes += 1;
        } 
        else {
            countZeros += 1;
        }
    }

    printf("Number of ones: %d. Number of zeros: %d.", countOnes, countZeros);
}