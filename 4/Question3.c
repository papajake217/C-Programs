#include <stdio.h>
#include <stdlib.h>
int main(){
    
    FILE *inputFile = fopen("in1.txt","r");

    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }
    float numberSet[20];
    int i;
    float input;
    float smallest = __FLT_MAX__;
    float secondSmallest = __FLT_MAX__;
    float thirdSmallest = __FLT_MAX__;
    for(i=0;i<20;i++){
        fscanf(inputFile,"%f",&input);
        if (input < smallest){
            thirdSmallest = secondSmallest;
            secondSmallest = smallest;
            smallest = input;
        } else if (input < secondSmallest){
            thirdSmallest = secondSmallest;
            secondSmallest = input;
        } else if (input < thirdSmallest){
            thirdSmallest = input;
        }
    }

    printf("The smallest number is %f\n", smallest);
    printf("The second smallest number is %f\n",secondSmallest);
    printf("The third smallest number is %f",thirdSmallest);
}