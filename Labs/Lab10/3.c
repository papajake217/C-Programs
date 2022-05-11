#include <stdio.h>
#define SIZE 100

int front = -1;
int rear = -1;

int isFull(int items[], int x){
    if(front == rear+1 || (front == 0 && rear == x-1)) {
        return 1;
    }
    return 0;
}

int isEmpty(int items[], int x){
    if(front == 1){
        return 1;
    }
    return 0;
}

void enQueue(int element, int items[], int x){
    if((front == rear+1) || (front == 0 && rear == 1)){
        printf("");
    } else{
        if(front == -1){
            front = 0;
        }
        rear = (rear+1)%x;
        items[rear] = element;
    }
}

int deQueue(int items[], int x){
    int element;
    if(front == -1){
        printf("");
        return (-1);
    } else{
        element = items[front];
        if(front == rear){
            front = -1;
            rear = -1;
        } else{
            front = (front+1)%x;
        }

        return element;
    }
}

int main(){
    int n,k,i=0,count=1,x,zeroCounter=0,y,flag=0,num=1;
    printf("Enter n and k: ");
    scanf("%d %d",&n,&k);

    int arr[n];
    int sol[n];
    deQueue(arr,n);
    count = n-1;
    int person = 1;
    while(count != 0){
        
        if(k==0 || k==1){
            flag = 1;
            break;
        }

    for(i=0;i<k-1;i++){
        enQueue(deQueue(arr,n),arr,n);
        
    }
    num = deQueue(arr,0);
    
    count--;
     
    }

    
    

}