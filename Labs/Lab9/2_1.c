#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6

#define C 0
#define Y 1
#define B 2
#define O 3
#define T 4
#define OTHER 5

int transitionTable[7][6] = {S1,S6,S6,S6,S6,S6,
                             S6,S2,S6,S6,S6,S6,
                             S6,S6,S3,S6,S6,S6,
                             S6,S6,S6,S4,S6,S6,
                             S6,S6,S6,S6,S5,S6,
                             S5,S5,S5,S5,S5,S5,
                             S6,S6,S6,S6,S6,S6};

int outputTable[7][6] = {0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         1,1,1,1,1,1,
                         0,0,0,0,0,0};


void fsm(){
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
            switch(character){
                case 'C': state = C; break;
                case 'Y': state = Y; break;
                case 'B': state = B; break;
                case 'O': state = O; break;
                case 'T': state = T; break;
                default: state = OTHER; break;
            }
            currentState = transitionTable[currentState][state];
            
            index++;
        }
        if(outputTable[currentState][state] == 1){
            printf("Input is CYBOT followed by characters");
        } else{
            printf("Input is NOT contain CYBOT followed by characters");
        }
    }
}


int main(){
    fsm();
}