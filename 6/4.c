#include <stdio.h>

double average(FILE* inputFile){
    
    double input;
    double sum = 0;
    double terms = 0;
    while(fscanf(inputFile,"%lf",&input) != EOF){
        sum += input;
        terms++;
    }

    return (sum/terms);
}


int main(){
    FILE* inputFile = fopen("in1.txt","r");
    double result = average(inputFile);
    printf("The average of the bi-dimensional array is: %lf",result);
}