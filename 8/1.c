#include <stdio.h>


#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define END 4

#define t 0
#define e 1
#define EOS 2
#define OTHER 3


int transitionTable[4][4] = {S1,S0,END,OTHER,
                             S1,S2,END,OTHER,
                             S3,S0,END,OTHER,
                             S1,S0,END,OTHER};

int outputTable[4][4] = {0,0,0,0,
                         0,0,0,0,
                         0,0,0,0,
                         0,1,0,0};

void FSM(){
    int currentState = S0;
    char input[64];
    char character;
    int index;
    int state;

    while(1){
        printf("\nEnter a string: ");
        scanf("%s",&input);
        index = 0;
        state = OTHER;
        currentState = 0;
        int counter = 0;
        while(state != EOS){
            character = input[index];
            switch(character){
                case 't': state = t;break;
                case 'e': state = e;break;
                case '\0': state = EOS;break;
                default: state = OTHER;break;
            }

            if(outputTable[currentState][state] == 1){
                counter++;
            } 
            currentState = transitionTable[currentState][state];
            index++;
        }
        counter--;
        if(counter > 0){
            printf("String tete occurs %d times",counter);
        } else{
            printf("String tete does not occur in input.");
        }
    }
}


int main(){
    FSM();
}