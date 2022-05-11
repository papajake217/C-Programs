#include<stdio.h>
#include<math.h>

int main(){

    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);
    int i;
    int sum = 0;
    double value;
    for(i=1;i<=n;i++){
        value = pow(10,i) - 1;
        sum += value;
    }
    // largest possible value of n where the sum is correctly computed is 9. 10 and over will be 
    if (n<10){
        printf("The sum is equal to %d", sum);
    } else{
        printf("The sum could not be correctly computed (n is greater than or equal to 10). Computed sum is %d",sum);
    }
}