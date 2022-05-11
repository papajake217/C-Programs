#include <stdio.h>

#define IDLE 0
#define KEY1 1
#define KEY2 2
#define KEY3 3
#define KEY4 4
#define KEY5 5
//01011 
int transitionTable[5][2] = {KEY1,IDLE,
					         IDLE,KEY2,
							 KEY3,IDLE,
							 IDLE,KEY4,
							 IDLE,KEY5};

int outputTable[5][2] = {0,0,
						 0,0,
						 0,0,
						 0,0,
						 0,1};

void FSM(){
	int currentState = IDLE;
	int input;
	int state;
	while(1){

		printf("Enter 0 or 1 to unlock the lock: ");
		scanf("%d",&input);
			if(input == 0 || input == 1){
			if(outputTable[currentState][input] == 1){
				break;
			}
		
			currentState = transitionTable[currentState][input];
			switch(currentState){
				case 1: printf("Input is right, 4 keys left.");break;
				case 2: printf("Input is right, 3 keys left.");break;
				case 3: printf("Input is right, 2 keys left.");break;
				case 4: printf("Input is right, 1 key left.");break;
				default: printf("Input is incorrect, 5 keys left.");break;
			}
			printf("\n");
		} else{
			printf("Input invalid\n");
		}
	}
	printf("Unlocked!");
}


int main(){
	FSM();
}