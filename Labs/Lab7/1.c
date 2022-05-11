#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *inputFile = fopen("in1.txt","r");

    if(inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }

    int i,j;
    double input[5][5];
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            fscanf(inputFile,"%lf",&input[i][j]);
        }
    }

    int rowOne;
    int rowTwo;
    int rowThree;

    printf("Enter 3 rows of the array to be summed together (x,x,x): ");
    scanf("%d,%d,%d",&rowOne,&rowTwo,&rowThree);

    double sum = 0;
    for(j=0;j<5;j++){
        sum += input[rowOne][j];
        sum += input[rowTwo][j];
        sum += input[rowThree][j];
    }
    printf("Sum of selected rows is %lf\n",sum);
    
    printf("\nUpper triangular portion of the array: \n");
    int tracker = 0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (j>=tracker){
                printf("%.4lf ",input[i][j]);
            }
        }
        printf("\n");
        tracker += 1;
    }

    int m;
    int n;
    printf("\nEnter m: ");
    scanf("%d",&m);
    printf("Enter n: ");
    scanf("%d",&n);

    double temp[5];
    
    for(i=0;i<5;i++){
        temp[i] = input[m][i];
        input[m][i] = input[n][i];
        input[n][i] = temp[i]; 
    }

    printf("Swapped array: \n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%.4lf ",input[i][j]);
        }
        printf("\n");
    }
    //unswap array
    for(i=0;i<5;i++){
        temp[i] = input[m][i];
        input[m][i] = input[n][i];
        input[n][i] = temp[i]; 
    }

    //transpose array
    double transposedArray[5][5];
    
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            transposedArray[i][j] = input[j][i];
        }
    }
    //do matrix multiplication
    printf("\nArray multiplied by its transpose: \n");
    double columnSum = 0;
    double adder;
    int k;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            for(k=0;k<5;k++){
                adder = input[i][k] * transposedArray[k][j];
                columnSum += adder;
            }
            printf("%.3lf ",columnSum);
            columnSum = 0;
        }
        printf("\n");
    }

    fclose(inputFile);


}