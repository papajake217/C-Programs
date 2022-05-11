#include <stdio.h>
#include <stdlib.h>
struct queue{
    int queuestarted;
    int front;
    int rear;
    int queuex[64];
    int queuey[64];
}qu;

struct parent{
    int parents[8][8];
    int parentx[8][8];
    int parenty[8][8];
}pa;

void intqueue(){
    qu.front = -1;
    qu.rear = -1;
}

void dequeue(){
    if(is_empty()){
        printf("Unable to remove, queue is empty\n");
    } else{
        if(qu.front == qu.rear){
        } else{
            qu.front++;
        }
    }
}

void enqueue(int x,int y){
    if(is_empty()){
        qu.front++;
    }
    qu.rear++;
    qu.queuex[qu.rear] = x;
    qu.queuey[qu.rear] = y;
}

int is_empty(){
    if(qu.rear == -1 && qu.front == -1){
        return 1;
    }
    return 0;
}

int checkwall(int x,int y, char maze[8][8]){
    if(maze[x][y] == '*'){
        return 1;
    } 
    return 0;
}

int checkNeighbor(int x, int y, char maze[8][8]){
    int valid = 0;
    if(maze[x-1][y] != '*'){
        valid = 1;
        if(pa.parents[x-1][y] == -1){
            pa.parentx[x-1][y] = x;
            pa.parenty[x-1][y] = y;
            enqueue(x-1,y);
        }
    }

    if(valid != 1){
        printf("No way out");
        return 0;
    }
    return 1;
}

int main(){
    FILE *inputFile = fopen("maze.txt","r");
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            pa.parentx[i][j] = -1;
            pa.parenty[i][j] = -1;
            
        }
    }

    int startX, startY;
    printf("Input starting location coordinates (x,y): ");
    scanf("(%d,%d)",&startX,&startY);
    intqueue();
    enqueue(startX,startY);
    int posx = startX;
    int posy = startY;
    char maze[8][8];
    char c;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            fscanf(inputFile,"%c",&c);
            maze[i][j] = c;
        }
    }

    

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }


   
}