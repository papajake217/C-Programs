#include <stdio.h>
#define max 64

struct queue{
    int front;
    int rear;
    int queuex[max],queuey[max];
}qu;





void clear(){
    qu.rear = 1;
    qu.front = -1;
}


int is_empty(){
    if(qu.rear == -1 && qu.front == -1){
        return 1;
    }
    return 0;
}

int is_full(){
    if(qu.rear == max-1){
        return 1;
    }
    return 0;
}


void add(int x,int y){
    if(is_empty()){
        qu.front++;
    }
    qu.rear++;
    qu.queuex[qu.rear] = x;
    qu.queuey[qu.rear] = y;
}



void remove1(){
    if(is_empty()){
        printf("Unable to remove, queue is empty\n");
    } else{
        if(qu.front == qu.rear){
            printf("(%d, %d) succesfully removed from the queue\n",qu.queuex[qu.front],qu.queuey[qu.front]);
        } else{
            qu.front++;
            printf("(%d, %d) sucessfully removed from the queue\n",qu.queuex[qu.front-1],qu.queuey[qu.front-1]);
        }
    }

}

int main(){
    int a;
    int b;
    int i;
    while(1){
        char input[10];
        printf("add or remove? ");
        scanf("%s",&input);
        getchar();
        if(strcmp("add",input) == 0){

        printf("Enter a point to add: ");
        scanf("(%d,%d)",&a,&b);
        
        add(a,b);
        printf("(%d,%d) added to queue\n",a,b);
        } else{
            remove1();
        }
    }
}