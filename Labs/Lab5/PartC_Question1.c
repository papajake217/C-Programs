#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    FILE *inputFile = fopen("in1.txt","r");
    FILE *outputFile = fopen("out1.txt","w");

    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }
    int count = 0;
    char string[15];
    char c = fgetc(inputFile);
    while (c != EOF){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9') || (c == '_') || (c == '-') || (c == '.')){
            while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9') || (c == '_') || (c == '-') || (c == '.')){
                fprintf(outputFile,"%c",c);
                c = getc(inputFile);
            }
            fprintf(outputFile,"\n");
            
        } 
        c = getc(inputFile);
    }

    
    fclose(inputFile);
    fclose(outputFile);

    inputFile = fopen("out1.txt","r");
    char line[15];
    char *end;
    double initialX;
    double initialY;
    double left = 0;
    double right = 0;
    double up = 0;
    double down = 0;
    double adder;
    while(fscanf(inputFile,"%s",&line) != EOF){
        if (strcmp(line,"INITIAL") == 0 ){
            fscanf(inputFile,"%s",&line);
            initialX = strtod(line,&end);
            fscanf(inputFile,"%s",&line);
            initialY = strtod(line,&end);
        } else if (strcmp(line,"LEFT") == 0){
            fscanf(inputFile,"%s",&line);
            adder = strtod(line,&end);
            left += adder;
        } else if (strcmp(line,"RIGHT") == 0){
            fscanf(inputFile,"%s",&line);
            adder = strtod(line,&end);
            right += adder;
        } else if ((strcmp(line,"UP") == 0)){
            fscanf(inputFile,"%s",&line);
            adder = strtod(line,&end);
            up += adder;
        } else if ((strcmp(line,"DOWN") == 0)){
            fscanf(inputFile,"%s",&line);
            adder = strtod(line,&end);
            down += adder;
        }
    }
    double finalX = initialX + right - left;
    double finalY = initialY + up - down;

    fclose(inputFile);
    outputFile = fopen("out1.txt","w");

    fprintf(outputFile,"Final position (%.2lf,%.2lf)",finalX,finalY);

    fclose(outputFile);

}