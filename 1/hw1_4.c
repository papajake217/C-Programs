#include <stdio.h>
/*Write a C program that checks if an integer number is prime or not. Identify and display the factors
of the number. */ 

int main(){
    int input, i,factors;
    printf("Enter an integer: ");
    scanf("%i", &input);
    printf("The factors are: \n");
    factors = 0;
    for(i=1;i<input + 1;i++){
        if(input % i == 0){
            printf("%d \n", i);
            factors += 1;
        }

    }
    if (factors == 2){
        printf("%d is a prime number.", input);
    }
    else {
        printf("%d is not a prime number.", input);
    }
}