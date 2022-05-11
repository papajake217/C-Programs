#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *inputFile = fopen("in1.txt","r");
    FILE *outputFile = fopen("out1.txt","w");

    if(inputFile == NULL){
        printf("Error, no input file");
        exit(1);
    }

    char c = fgetc(inputFile);
    int x = 0;
    char nums[100];
    double sum = 0;
    double average;
    int count = 0;

    while (c != EOF){
        if (c >= '0' && c <= '9'){
            while((c >= '0' && c <= '9') || c == '.'){
                fprintf(outputFile,"%c", c);
                c = getc(inputFile);
            }
            fprintf(outputFile,"\n");
            count += 1;
        } else if (c == '-' ){
            fprintf(outputFile,"%c",c);
            c = getc(inputFile);
            while((c >= '0' && c <= '9') || c == '.'){
                fprintf(outputFile,"%c", c);
                c = getc(inputFile);
            }
            fprintf(outputFile,"\n");
            count += 1;
        } else {
            c = getc(inputFile);
        }
    }
    fclose(outputFile);
    outputFile = fopen("out1.txt","r");

    int k;
    double input;
    for (k=0;k<count;k++){
        fscanf(outputFile,"%lf",&input);
        sum += input;
    }
    average = sum/count;

    fclose(outputFile);
    outputFile = fopen("out1.txt","a");
    fprintf(outputFile,"\nSum is %lf\nAverage is %lf",sum,average);

    
    fclose(inputFile);
    fclose(outputFile);
}