#include <stdio.h>



double *getMax(double arr[],double numOfElements){
    double *max;
    double length = numOfElements;
    double x = 1;
    int i;
    max = arr;
    *max = *arr;
    for(i=1;i<length;i++){
        if(*(arr+i) > *max){
            *max = *(arr+i);
            x = i+1;
        }
    }
    
    return max;
}

int main(){
    double arr[5];
    printf("Enter 5 double values: ");
    int i;
    for(i=0;i<5;i++){
        scanf("%lf",&arr[i]);
    }
    double* pointer = getMax(arr,5);
    printf("Pointer: %p\n",pointer);
    printf("Max Value: %lf",*pointer);
    
}