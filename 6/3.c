#include <stdio.h>

int * fibonacciSeries(int series[]){
    

    series[0] = 0;
    series[1] = 1;
    int i;
    for(i=2;i<30;i++){
        series[i] = series[i-1] + series[i-2];
    }
    return series;

}

void printArray(int arr[]){
    int i;
    for(i=0;i<30;i++){
        printf("F(%d) = %d\n",i,arr[i]);
    }
}

int main(){
    int series[30];
    fibonacciSeries(series);
    printArray(series);

}