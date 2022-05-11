
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHEROMONE 'P'
#define STARTX 4;
#define STARTY 4;
#define MAX_SIZE 100

int maxEnergy;
int ENERGY;
int memoryStack[MAX_SIZE][2];
int top = -1;
//change if filename is different
char fileName[] = "exampleMaze.txt";
char instructions[100][15];

//can edit these based on starting position
int posX = STARTX;
int posY = STARTY;
char maze[12][12];
//can edit this based on the height and width of the input maze
int mazeHeight = 12;
int mazeWidth = 12;




//STACK FUNCTIONS

//returns 1 if full, 0 if not
int isFull(){
    if(top == MAX_SIZE) return 1;
    return 0;
}

//returns 1 if empty, 0 if not
int isEmpty(){
    if(top == -1) return 1;
    return 0;
}


//Push onto stack
void push(int x, int y){
    if(isFull(memoryStack) == 1){
        printf("Error, memory full\n");
        
    } else{
        top++;
        memoryStack[top][0] = x;
        memoryStack[top][1] = y;
        ENERGY -= 4;
    }
}

//Pop top value, decrement top int
void pop(){
    if(isEmpty(memoryStack) == 1){
        printf("Error, stack is empty. Can't pop\n");
    } else{
        top--;
        ENERGY -= 4;
    }

}

//peek at top x value, returns it
int peekX(){
    if(isEmpty(memoryStack) == 1){
        printf("Error, cant peek stack is empty\n");
        return -1;
    } 
    ENERGY -= 2;
    return memoryStack[top][0];
}  

//peek at top y value, returns it
int peekY(){
    if(isEmpty(memoryStack) == 1){
        printf("Error, cant peek stack is empty\n");
        return -1;
    } 
    ENERGY -= 2;
    return memoryStack[top][1];
}

//clear the stack
void clearMemory(){
    int i;
    for(i = 0;i<MAX_SIZE;i++){
        memoryStack[i][0] = 0;
        memoryStack[i][0] = 0;
    }
    ENERGY -= 2;
    top = -1;
}





//movement functions
//Move Forward (Up on maze)
void MOVE_F(){
    if(maze[posY-1][posX] != '*'){
        posY--;
        ENERGY -= 3;
    }
}

//Move Backwards (Up on maze)
void MOVE_B(){
    if(maze[posY+1][posX] != '*'){
        posY++;
        ENERGY -= 3;
    }
}

void MOVE_L(){
    if(maze[posY][posX-1] != '*'){
        posX--;
        ENERGY -= 3;
    }
}

void MOVE_R(){
    if(maze[posY][posX+1] != '*'){
        posX++;
        ENERGY -= 3;
    }
}

//functions for checking for pheromones, return 0 if no itch (Pheromone exists in path), or x amount away from him
//left
int CWL(){
    int x = posX;
    int y = posY;
    int counter = 0;
    ENERGY -= 1;
    while(maze[posY][posX] != '*'){
        if(maze[posY][posX] == PHEROMONE){
            return 0;
        }
        posX--;
        counter++;
    }
    return counter;
}

//right
int CWR(){
    int x = posX;
    int y = posY;
    ENERGY -= 1;
    int counter = 0;
    while(maze[posY][posX] != '*'){
        if(maze[posY][posX] == PHEROMONE){
            return 0;
        }
        posX++;
        counter++;
    }
    return counter;
}
//Up/Forward
int CWF(){
    int x = posX;
    int y = posY;
    ENERGY -= 1;
    int counter = 0;
    while(maze[posY][posX] != '*'){
        if(maze[posY][posX] == PHEROMONE){
            return 0;
        }
        posY--;
        counter++;
    }
    return counter;
}
//Down/backward
int CWB(){
    int x = posX;
    int y = posY;
    int counter = 0;
    ENERGY -= 1;
    while(maze[posY][posX] != '*'){
        if(maze[posY][posX] == PHEROMONE){
            return 0;
        }
        posY++;
        counter++;
    }
    return counter;
}


//Bold jump for itching, use the return value from CW functions to jump x units. Also needs the direction to jump
void BJFI(int x,char direction){
    if(direction == 'U'){
        posY -= x;
    } else if(direction == 'D'){
        posY += x;
    } else if (direction == 'L'){
        posX -= x;
    } else if(direction == 'R'){
        posX += x;
    }
    ENERGY -= 5;
}

//Cautious Jump for itching, only jumps 1 unit so no need for input x
void CJFI(char direction){
    if(direction == 'U'){
        posY -= 1;
    } else if(direction == 'D'){
        posY += 1;
    } else if (direction == 'L'){
        posX -= 1;
    } else if(direction == 'R'){
        posX += 1;
    }
    ENERGY -= 3;
}

//convert maze to array

void mazeToArray(char maze[12][12], char fileName[]){
    int height = 13;
    int width = 12;

    FILE *inputFile = fopen(fileName,"r");
    if(inputFile == NULL){
        printf("Error, no input file");
        exit(1);
    }
    
    int i,j;
    char c;

    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            fscanf(inputFile,"%c",&c);
            maze[i][j] = c;
        }
    }

    

}

//returns how many pots are left in the maze, used to check if he should still keep going or not.
int getNumberOfPots(){
    int i,j,numPots=0;
    for(i=0;i<mazeHeight;i++){
        for(j=0;j<mazeWidth;j++){
            if(maze[i][j] == '@'){
                numPots++;
            }
        }    
    }

    return numPots;
}


//places pheromone ('P') at maze coordinates of the Ant
void placeMarker(){
    maze[posY][posX] = PHEROMONE;
    ENERGY -= 3;
}

//displays the current maze and the ant
void displayCurrentMaze(){
    maze[12][11] = ' ';
    int i,j;
    for(i=0;i<=mazeHeight;i++){
        for(j=0;j<mazeWidth;j++){
            //possible issue with posX not displaying correctly, might need change
            if(posX == j && posY == i){
                printf("A");
            } else{
                printf("%c",maze[i][j]);
            }
        }
    }
}

//write how much energy was used and the moves made in an output file
void writeResults(int pots){

    FILE *outputFile = fopen("out.txt","w");
    
    fprintf(outputFile,"Energy Consumed: %d\n",maxEnergy - ENERGY);
    fprintf(outputFile,"Sequence of moves: ");
    
    int i;
    //reads from memory stack until the top and displays the coordinates in the format (x,y);
    for(i=0;i<top;i++){
        fprintf(outputFile,"(%d,%d)\n",memoryStack[i][0],memoryStack[i][1]);
    }
    
    fprintf(outputFile,"Pots collected: %d",pots);
    fclose(outputFile);
}

void printResults(int pots){
    printf("Energy Consumed: %d\n",maxEnergy - ENERGY);
    printf("Sequence of moves: ");
    int i;
    for(i=0;i<top;i++){
        printf("(%d,%d)\n",memoryStack[i][0],memoryStack[i][1]);
    }

    printf("Pots collected: %d",pots);
    
}




int main(){   
    
    mazeToArray(maze,fileName);
    int i=0;
    int potsCollected = 0;
    char action[15];
    int en;
    //open intel file and get max energy displayed at the top
    FILE *Intelligence = fopen("intel.txt","r");
    fscanf(Intelligence,"%d",&en);
    ENERGY = en;
    maxEnergy = en;
    int track = 0;
    printf("Enter starting position: (x,y): ");
    scanf("(%d,%d)",&posX,&posY);
    //scans intel file for actions line by line and performs them
    while(fscanf(Intelligence,"%s",&action) != EOF && ENERGY > 0 && getNumberOfPots() > 0){
        if(strcmp(action,"MOVEF") == 0){
            MOVE_F();
            push(posX,posY);
        } else if(strcmp(action,"MOVEB") == 0) {
            MOVE_B();
            push(posX,posY);
        } else if(strcmp(action,"MOVER") == 0){
            MOVE_R();
            push(posX,posY);
        } else if(strcmp(action, "MOVEL") == 0){
            MOVE_L();
            push(posX,posY);
        } else if(strcmp(action,"BJFIF") == 0){
            int x = CWF();
            BJFI(x,'U');
            push(posX,posY);
        } else if(strcmp(action, "BJFIB") == 0){
            int x = CWB();
            BJFI(x,'D');
            push(posX,posY);
        } else if(strcmp(action,"BJFIR") == 0){
            int x = CWR();
            BJFI(x,'R');
            push(posX,posY);
        } else if(strcmp(action,"BJFIL") == 0){
            int x = CWL();
            BJFI(x,'L');
            push(posX,posY);
        } else if(strcmp(action,"CJFIF") == 0){
            CJFI('U');
            push(posX,posY);
        } else if(strcmp(action,"CJFIB") == 0){
            CJFI('D');
            push(posX,posY);
        } else if(strcmp(action,"CJFIR") == 0){
            CJFI('R');
            push(posX,posY);
        } else if(strcmp(action,"CJFIL") == 0){
            CJFI('L');
            push(posX,posY);
        } else if(strcmp(action,"PLACEMARKER") == 0){
            placeMarker();
        }

        if(maze[posY][posX] == '@'){
            maze[posY][posX] = ' ';
            potsCollected++;
        }

    }

    writeResults(potsCollected);
    printResults(potsCollected);



    
    

    
    
    
}