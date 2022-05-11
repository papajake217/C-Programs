#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *inputFile = fopen("in4.txt","r");

    if(inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }

    double matrix[6][6];
    int row;
    int column;
    for(column=0;column<6;column++){
        for(row=0;row<6;row++){
            fscanf(inputFile,"%lf",&matrix[row][column]);
        }
    }

    int positives = 0;
    int negatives = 0;
    int zeroes = 0;
    int i,j;

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(matrix[i][j] > 0){
                positives += 1;
            } else if (matrix[i][j] < 0){
                negatives += 1;
            } else if (matrix[i][j] == 0){
                zeroes += 1;
            }
        }
    }

    printf("Number of positive numbers: %d\nNumber of negative numbers: %d\nNumber of zeroes: %d ",positives,negatives,zeroes);

    fclose(inputFile);
}