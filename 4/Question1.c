#include <stdio.h>
#include <stdlib.h>
int main(){
    
    FILE *inputFile = fopen("in1.txt","r");

    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }
    int i;
    float positiveSum = 0;
    int positives = 0;
    float negativeSum = 0;
    int negatives = 0;
    float input;
    for(i=0;i<15;i++){
        fscanf(inputFile,"%f",&input);
        if (input > 0){
            positiveSum += input;
            positives +=1;
        } else if (input < 0){
            negativeSum += input;
            negatives += 1;
        }
    }

    float positiveAverage = positiveSum / positives;
    float negativeAverage = negativeSum / negatives;

    printf("Average of positive numbers is: %f\n",positiveAverage);
    printf("Average of negative numbers is: %f",negativeAverage);

    fclose(inputFile);

}