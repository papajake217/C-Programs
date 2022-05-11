#include <stdio.h>

int main(){
    int check = 1;
    int evenSum = 0;
    int oddSum = 0;
    int value;
    char character;
    while (check == 1){
        printf("Enter an integer: ");
        scanf("%d", &value);
        scanf("%c", &character);
        if(character == '#'){
            check = 2;
        }
        else{
            if(value % 2 == 0){
                evenSum += value;
            }
            else {
                oddSum += value;
            }
        }
    }
    printf("Sum of even numbers: %d. Sum of odd numbers: %d.", evenSum, oddSum);
}