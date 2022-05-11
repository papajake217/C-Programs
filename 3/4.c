#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    FILE *inputFile = fopen("in1.txt","r");
    FILE *outputFile = fopen("out1.txt","w");
    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }
    char c = fgetc(inputFile);
    while(c != EOF){
         if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                if (c >= 'A' && c <= 'Z'){
                    c = tolower(c);
                }
                if (c != 'a' && c != 'e' && c !='i' && c != 'o' && c!= 'u'){
                    fputc(c,outputFile);
                }
                    c = getc(inputFile);
                }
            fprintf(outputFile,"\n");
            } else{
            c = getc(inputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    
}