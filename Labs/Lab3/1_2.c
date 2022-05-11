#include <stdio.h>
#include <math.h>

int main(){
    int sum, i, n;
    sum = 0;
    printf("Enter the number of terms: ");
    scanf("%i", &n);

    for (i=1;i<=n;i++){
        double val = pow(10,i);
        val = val - 1;
        sum += val;
    }
    if (n <= 10){
        printf("The sum is computed correctly. It is %i. \n", sum);
    } else{
        printf("The sum is not computed correctly. The computed sum is %i. \n", sum);
    }
    printf("The largest value of n for which the sum can be computed is 10");
}