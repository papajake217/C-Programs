#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4

#define A 0
#define OTHER 1




int transitionTable[5][2] = {S1,S0,
                             S2,S1,
                             S3,S2,
                             S4,S3,
                             S4,S4};

int outputTable[5][2] = {0,0,
                         0,0,
                         0,0,
                         1,1,
                         0,0};


int fsm(){
    int currentState = S0;
    int index;
    int state;
    char input[64];
    char character;
    while(1){
        printf("\nInput a string: ");
        scanf("%s",&input);
        index = 0;
        state = OTHER;
        currentState = 0;
        
        while(index<strlen(input)){
            character = input[index];
            character = toupper(character);
            switch(character){
                case 'A': state = A; break;
                default: state = OTHER; break;
            }
            currentState = transitionTable[currentState][state];
            
            index++;
        }
        if(outputTable[currentState][state] == 1){
            printf("Input contains exactly 3 A's");
        } else{
            printf("Input does not contain exactly 3 A's");
        }
    }
}


int main(){
    while(1){
        fsm();
    }
}