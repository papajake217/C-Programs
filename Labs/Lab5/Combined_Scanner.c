#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *inputFile = fopen("inputfile.txt","r");
    FILE *outputFile = fopen("output.txt","w");
    FILE *tempFile = fopen("temp.txt","w");
    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }
    char c = fgetc(inputFile);
    int count = 0;
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
                fprintf(outputFile,"\n");
                
                while((c >= '0' && c <= '9') || c == '.' || (c == 'e')){
                    fprintf(outputFile,"%c", c);
                    fprintf(tempFile,"%c",c);
                    c = getc(inputFile);
                }
                fprintf(outputFile,"\n");
                c = ungetc(c,inputFile);
                count += 1;
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
    fclose(tempFile);

    outputFile = fopen("output.txt","a");
    tempFile = fopen("temp.txt","r");

    double sum = 0;
    int k;
    double average;
    double input;
    for (k=0;k<count;k++){
        fscanf(tempFile,"%lf",&input);
        sum += input;
    }
    average = sum/count;
    if (count > 0){
        fclose(tempFile);
        fprintf(outputFile,"\nSum is %lf\nAverage is %lf",sum,average);
    }

    fclose(outputFile);
    fclose(tempFile);
    remove("temp.txt");
}