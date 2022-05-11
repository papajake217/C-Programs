#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STATE_0 0
#define STATE_1 1
#define STATE_2 2
#define STATE_3 3
#define END 4


#define F 0
#define R 1
#define O 2
#define G 3
#define EOS 4
#define OTHER 5


int transitionTable[4][6] = {STATE_1,STATE_0,STATE_0,STATE_0,END,STATE_0,
                            STATE_1,STATE_2,STATE_0,STATE_0,END,STATE_0,
                            STATE_1,STATE_0,STATE_3,STATE_0,END,STATE_0,
                            STATE_1,STATE_0,STATE_0,STATE_0,END,STATE_0};

int outputTable[4][6] = {0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         0,0,0,1,0,0};




int frogFSM(){
    int currentState = STATE_0;
    char input[64];
    char character;
    int index;
    int state;

    while(1){
        printf("\nInput a string: ");
        scanf("%s",&input);
        index = 0;
        state = OTHER;
        currentState = 0;
        while(state != EOS){
            character = input[index];
            character = toupper(character);
            switch(character){
                case 'F': state = F; break;
                case 'R': state = R; break;
                case 'O': state = O; break;
                case 'G': state = G; break;
                case '\0': state = EOS;break;
                default: state = OTHER; break;
                
            }
            
            
            if(outputTable[currentState][state] == 1){
                printf("Input string contains frog");
                return 0;
            }
            currentState = transitionTable[currentState][state];
            index++;
        }
        printf("Input string does not contain frog");
    }
      
}





int main(){
    while(1){
        frogFSM();
    }
}