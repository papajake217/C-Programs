#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    FILE *inputFile = fopen("in1.txt","r");
    FILE *outputFile = fopen("out1.txt","w");

    char string[100];
    char final[100];
    fgets(string,100,inputFile);
    int length = strlen(string) - 1;
    int i;
    for (i=0;i<=length;i++){
        final[i] = string[length-i];
    }

    length = strlen(final);
    length -= 1;
    int j;
    for(j=length;j>=0;j--){
        if(final[j] == ' '){
            final[j] = '\0';
            fprintf(outputFile,"%s ", &(final[j]) + 1);
        }
    }
    fprintf(outputFile,"%s", final);

    fclose(inputFile);
    fclose(outputFile);
}

