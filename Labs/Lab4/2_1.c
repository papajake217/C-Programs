#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *inputFile = fopen("inputfile.txt","r");
    FILE *outputFile = fopen("identifierOutputSymbols.txt","w");
    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }
    char c = fgetc(inputFile);
    char state[10];
    while(c != EOF){
        switch (c){
            case '+':
                fprintf(outputFile,"PLUS \n");
                break;
            case '-':
                fprintf(outputFile,"MINUS \n");
                break;
            case '*':
                fprintf(outputFile,"MULTIPLY \n");
                break;
            case '/':
                fprintf(outputFile,"DIVIDE \n");
                break;
            case '%':
                fprintf(outputFile,"MODULO \n");
                break;
            case '@':
                fprintf(outputFile,"AT \n");
                break;
            case '&':
                fprintf(outputFile,"BITWISE AND \n");
                break;
            case '^':
                fprintf(outputFile,"BITWISE XOR \n");
                break;
            default: 
                break;

        }
        c = getc(inputFile);
    } 

    fclose(inputFile);
    fclose(outputFile);
}