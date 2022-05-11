#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *inputFile = fopen("inputfile.txt","r");
    FILE *outputFile = fopen("outputPart4.txt","w");
    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }
    char c = fgetc(inputFile);
    char state[10];
    char upper;
    while(c != EOF){
        switch (c){
            case '+':
                c = getc(inputFile);
                if (c == '+'){
                    fprintf(outputFile,"INCREMENT \n");
                } else if (c == '=') {
                    fprintf(outputFile,"ADD ASSIGN \n");
                } else {
                    fprintf(outputFile,"PLUS \n");
                    ungetc(c,inputFile);
                }
                break;
            case '-':
                c = getc(inputFile);
                if (c == '-'){
                    fprintf(outputFile,"DECREMENT \n");
                } else {
                    fprintf(outputFile,"MINUS \n");
                    ungetc(c,inputFile);
                }
                break;
            case '*':
                c = getc(inputFile);
                if (c == '='){
                    fprintf(outputFile,"MULTIPLY ASSIGN \n");
                } else{
                    fprintf(outputFile,"MULTIPLY \n");
                    ungetc(c,inputFile);
                }
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
            case '=':
                c = getc(inputFile);
                if (c == '='){
                    fprintf(outputFile,"EQUAL \n");
                } else{
                    fprintf(outputFile,"ASSIGN \n");
                    ungetc(c,inputFile);
                }
                break;
            case '.':
                fprintf(outputFile,"DOT \n");
                break;
            case ',':
                fprintf(outputFile,"COMMA \n");
                break;
            case ';':
                fprintf(outputFile,"SEMICOLON \n");
                break;
            case ':':
                fprintf(outputFile,"COLON \n");
                break;
            case 'A'...'Z':
                fputc(c,outputFile);
                c = getc(inputFile);
                if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9') || (c == '_')){
                    ungetc(c,inputFile);
                } else {
                    ungetc(c,inputFile);
                    fprintf(outputFile, "\n");
                }
                break;
            case 'a'...'z':
                upper = c - 32;
                fputc(upper,outputFile);
                c = getc(inputFile);
                if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9') || (c == '_')){
                    ungetc(c,inputFile);
                } else {
                    ungetc(c,inputFile);
                    fprintf(outputFile, "\n");
                }
                break;
            case '0'...'9':
                fputc(c,outputFile);
                c = getc(inputFile);
                if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9') || (c == '_')){
                    ungetc(c,inputFile);
                } else {
                    ungetc(c,inputFile);
                    fprintf(outputFile, "\n");
                }
                break;
            case '_':
                fputc(c,outputFile);
                c = getc(inputFile);
                if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9') || (c == '_')){
                    ungetc(c,inputFile);
                } else {
                    ungetc(c,inputFile);
                    fprintf(outputFile, "\n");
                }
                break;
            default:
                break;

        }
        c = getc(inputFile);
    } 

    fclose(inputFile);
    fclose(outputFile);
}