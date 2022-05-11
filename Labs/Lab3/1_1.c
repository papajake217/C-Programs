#include <stdio.h>

int main(){
    double positiveSum,positives,negativeSum,negatives, num, positiveAverage,negativeAverage;
    positiveSum = 0;
    negativeSum = 0;
    int i;
    for (i=1;i<=15;i++){
        printf("Enter the %d-th number: ", i);
        scanf("%lf", &num);
        if (num > 0){
            positiveSum += num;
            positives += 1;
        } 
        if (num < 0){
            negativeSum += num;
            negatives += 1;
        }
    }

    positiveAverage = positiveSum / positives;
    negativeAverage = negativeSum / negatives;

    printf("The average of the positive numbers is %lf \n", positiveAverage);
    printf("The average of the negative numbers is %lf", negativeAverage);

    
}