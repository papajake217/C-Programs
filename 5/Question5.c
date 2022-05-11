#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(){

    FILE *inputFile = fopen("in1.txt","r");
    FILE *outputFile = fopen("out2.txt","w");

    if(inputFile == NULL){
        printf("Error, no input file");
        exit(1);
    }

    int input;
    int inputArray[30];
    int x = 0;
    int elements = 0;
    while(fscanf(inputFile,"%d",&input) != EOF){
        
        inputArray[x] = input;
        x += 1;
        elements += 1;
    }

    int i;
    int j;
    int max = inputArray[0];
    int sum;
    for(i=0;i<elements;i++){
        sum = 0;
        for(j=0;j<elements;j++){
            sum = sum + inputArray[j];
            if(max<sum){
                max = sum;
            }
        }
    }
    
    fprintf(outputFile,"The largest sum of a contiguous subarray is %d",max);

    



}