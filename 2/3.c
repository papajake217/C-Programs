#include <stdio.h>

int main(){
    int one, two;

    printf("Enter integer 1: ");
    scanf("%d", &one);
    printf("Enter integer 2: ");
    scanf("%d", &two);
    int bigger, smaller;
    if (one > two){
        bigger = one;
        smaller = two;
    } else {
        bigger = two;
        smaller = one;
    }
    int i;
    int result = 0;
    for(i = 1;i<=smaller;i++){
        if(smaller % i == 0 && bigger % i == 0){
            result = i;
        }
    }
    printf("The greatest common divider of the two numbers is %d", result);

}