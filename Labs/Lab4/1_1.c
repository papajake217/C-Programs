#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *inputFile = fopen("inputfile.txt","r");
    FILE *outputFile = fopen("outputfile.txt","w");
    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    } else{ 
        char out[100];
        fscanf(inputFile,"%s", &out);
        fprintf(outputFile, "%s",out);
    }
}