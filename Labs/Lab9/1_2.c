#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define S7 7
#define END 8


#define M 0
#define U 1
#define R 2
#define S 3
#define EOS 4
#define OTHER 5


int transitionTable[7][6] = {S1,S0,S0,S0,EOS,S0,
                             S1,S2,S0,S0,EOS,S0,
                             S1,S0,S3,S0,EOS,S0,
                             S4,S0,S0,S0,EOS,S0,
                             S1,S5,S0,S0,EOS,S0,
                             S1,S0,S6,S0,EOS,S0,
                             S1,S0,S0,S7,EOS,S0};

int outputTable[7][6] = {0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         0,0,0,0,0,0,
                         0,0,0,1,0,0};



int fsm(){
    int currentState = S0,index,state;
    char input[64],character;

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
                case 'M': state = M; break;
                case 'U': state = U; break;
                case 'R': state = R; break;
                case 'S': state = S; break;
                case '\0': state = EOS; break;
                default: state = OTHER; break;
            }
            if(outputTable[currentState][state] == 1){
                printf("Input string contains murmurs.");
                return 0;
            }
            currentState = transitionTable[currentState][state];
            index++;
        }
        printf("Input string does not contain murmurs.");
    }

}



int main(){
    while(1){
        fsm();
    }
}