#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j;
    FILE *inputFile = fopen("in1.txt","r");
    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }
    int positives = 0;
    int negatives = 0;
    int zeroes = 0;
    float input;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            fscanf(inputFile,"%f",&input);
            if (input > 0 ){
                positives += 1;
            } else if(input < 0){
                negatives += 1;
            } else if (input == 0){
                zeroes += 1;
            }
        }
    }
    printf("Number of positive decimals: %d\nNumber of negative decimals: %d\nNumber of zeroes: %d",positives,negatives,zeroes);
}