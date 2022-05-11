#include <stdio.h>
#include <limits.h>

int main(){ 
    int n, check = 0;
    double val, smallest, secondSmallest, thirdSmallest, largest;
    largest = INT_MIN;
    smallest = INT_MAX;
    secondSmallest = INT_MAX;
    thirdSmallest = INT_MAX;
    printf("Enter the value of n: ");
    scanf("%i", &n);

    while (check < n){
        printf("Enter a decimal value: ");
        scanf("%lf", &val);
        if (val < smallest){
            thirdSmallest = secondSmallest;
            secondSmallest = smallest;
            smallest = val;
        } else if (val < secondSmallest){
            thirdSmallest = secondSmallest;
            secondSmallest = val;
        } else if (val < thirdSmallest){
            thirdSmallest = val;
        }
        if (secondSmallest == INT_MAX && thirdSmallest == INT_MAX){
            printf("The set of the smallest, second smallest, and third smallest numbers is {%lf, /, /} \n", smallest);

        } else if (thirdSmallest == INT_MAX){
            printf("The set of the smallest, second smallest, and third smallest numbers is {%lf, %lf, /} \n", smallest, secondSmallest);
        } else{
            printf("The set of the smallest, second smallest, and third smallest numbers is {%lf, %lf, %lf} \n", smallest, secondSmallest, thirdSmallest);
        }

        if (largest > val){
            check += 1;
        } else {
            largest = val;
            check = 0;
        }
    }

    
}