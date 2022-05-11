#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *inputFile = fopen("in2.txt","r");
    FILE *outputFile = fopen("out2.txt","w");

    if(inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }

    char temp = ' ';
    char c = fgetc(inputFile);
    while(c != EOF){
        if(c != temp){
            fputc(c,outputFile);
        }
        temp = c;
        c = getc(inputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}