#include <stdio.h>
#include <math.h>
int main(){
    double x = 0;
    int terms;
    printf("Enter x value within the range (0,2]: ");
    while (x <= 0 || x > 2){
        scanf("%lf", &x);
        if (x < 0){
            printf("Error, x cannot be less than 0. Enter a new number: ");
        } else if (x == 0){
            printf("Error, x cannot be 0. Enter a new number: ");
        } else if (x > 2){
            printf("Error, x cannot be greater than 2. Enter a new number: ");
        }
    }
    
    printf("Enter number of terms to calculate to: ");
    scanf("%i", &terms);

    int i = 1;
    double numerator, denominator;
    int sign = 1;
    double sum = 0;
    double result = 0;
    do{
        numerator = pow((x-1),i);
        denominator = i;
        sign = pow(-1,i+1);
        result = numerator/denominator;
        result *= sign;
        sum += result;
        i += 1;
    } while(i<= terms);

    printf("Result is %lf", sum);
}