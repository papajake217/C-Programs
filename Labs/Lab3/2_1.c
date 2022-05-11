#include <stdio.h>

int main(){
    double input, lastInput;
    int positives, negatives, zeros;
    positives = 0;
    negatives = 0;
    zeros = 0;
    int check = 0;
    while(check == 0){
        printf("Enter a value: ");
        scanf("%lf", &input);
        if (input > 0){
            positives += 1;
        }
        if (input < 0){
            negatives += 1;
        }
        if (input == 0){
            zeros += 1;
        }
        
        printf("Number of positive values: %i \n", positives);
        printf("Number of negative values: %i \n", negatives);
        printf("Number of zeroes: %i \n", zeros);

        if (input == lastInput){
            break;
        }

        lastInput = input;

    }
}