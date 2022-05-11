#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    FILE *inputFile = fopen("in1.txt","r");
    if(inputFile == NULL){
        printf("Error no input file");
        exit(1);
    }
    char input[25];
    int counts[25][1];
    int i;
    for(i=0;i<25;i++){
        counts[i][0] = 0;
    }
    int length;
    int a;
    while(fscanf(inputFile,"%s",&input) != EOF){
        length = strlen(input);
        a = length;
        // compensates for strings with non-letter characters
        for(i=0;i<a;i++){
            if(isalpha(input[i]) == 0){
                length--;
            }
        }
        counts[length][0] += 1;
    }

    for(i=1;i<25;i++){
        printf("length %d : %d occurrences\n",i,counts[i][0]);
    }
}