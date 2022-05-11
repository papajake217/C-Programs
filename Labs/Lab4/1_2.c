#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *inputFile = fopen("inputfile.txt","r");
    FILE *outputFile = fopen("identifierOutput.txt","w");
    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }
    char c = fgetc(inputFile);
    while(c != EOF){
         if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9') || (c == '_')){
            while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9') || (c == '_')){
                fputc(c,outputFile);
                c = getc(inputFile);
            }
            fprintf(outputFile,"\n");
            
        }  else{
            c = getc(inputFile);
        }
    } 

    fclose(inputFile);
    fclose(outputFile);
}