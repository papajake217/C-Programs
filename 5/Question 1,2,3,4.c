#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *inputFile = fopen("in1.txt","r");
    FILE *outputFile = fopen("out1.txt","w");

    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }

    int i,j;
    double input;
    double outputArray[6][6];
    double inputArray[6][6];
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            fscanf(inputFile,"%lf",&input);
            outputArray[j][i] = input;
            inputArray[i][j] = input;
        }
    }

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            fprintf(outputFile,"%.4lf ",outputArray[i][j]);
        }
        fprintf(outputFile,"\n");
    }
    
    double longArray[36];
    int x = 0;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            longArray[x] = inputArray[i][j];
            x += 1;
        }
    }

    for(i=0;i<36;i++){
        for(j=0;j<35;j++){
            if(longArray[j] < longArray[j+1]){
                double temp = longArray[j];
                longArray[j] = longArray[j+1];
                longArray[j+1] = temp;
            }
        }
    }

    int duplicates = 0;
    for(i=0;i<36;i++){
        if(longArray[i] == longArray[i+1]){
            duplicates += 1;
            while(longArray[i] == longArray[i+1]){
                duplicates += 1;
                i += 1;
            }
        }
    }


    printf("Number of duplicates: %d", duplicates);
    fprintf(outputFile,"\nElement Frequency: \n");
    int tracker = 1;
    for(i=0;i<36;i++){
        tracker = 1;
        fprintf(outputFile,"%.4lf ",longArray[i]);
        if(longArray[i] == longArray[i+1]){
            while(longArray[i] == longArray[i+1]){
                tracker += 1;
                i += 1;
            }
        }

        fprintf(outputFile,"%d", tracker);
        fprintf(outputFile,"\n");

    }



    fprintf(outputFile,"\nPositive Array: \n");
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(inputArray[i][j] > 0){
                fprintf(outputFile,"%.4lf ",inputArray[i][j]);
            }
        }
    }
    fprintf(outputFile,"\nNegative Array: \n");
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(inputArray[i][j] < 0){
                fprintf(outputFile,"%.4lf ",inputArray[i][j]);
            }
        }
    }



    fclose(inputFile);
    fclose(outputFile);
}