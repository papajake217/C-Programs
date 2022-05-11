#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main(){

    FILE *inputFile = fopen("in1.txt","r");
    FILE *outputFile = fopen("out1.txt","w");
    if (inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }

    int start;
    int increment;
    int end;
    char c = fgetc(inputFile);
    int counter = 0;
    while (c != EOF){
        if (isdigit(c)){
            if (counter == 0){
                start = c;
                counter += 1;
            } else if (counter == 1){
                increment = c;
                counter += 1;
            } else if (counter == 2){
                end = c;
                counter += 1;
            }
        }
        c = getc(inputFile);
    }
    start -= 48;
    increment -= 48;
    end -= 48;
    double altitude, velocity;
    int i;
    for (i=start;i<=end;i+=increment){
        altitude = (-0.12 * pow(i,4) ) + (12 * pow(i,3)) + (-380 * pow(i,2)) + (4100 * i) + 220;
        velocity = (-0.48 * pow(i,3)) + (36 * pow(i,2)) + (-760 * i) + 4100;
        printf("time: %i altitude: %.3f velocity: %.3f \n",i,altitude,velocity);
    }

    fclose(inputFile);

}