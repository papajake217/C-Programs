#include <stdio.h>
#include <math.h>
int main(){ 
    double x,a;
    printf("Enter the value x: ");
    scanf("%lf", &x);
    printf("Enter the positive threshold a: ");
    scanf("%lf", &a);
    int n = 1;
    double sum = 0;
    double divisor = 1;
    int sign = -1;
    double numerator = 1;
    do{
        divisor = 1;
        sign = pow(-1,n-1);
        int exponent = 2 * (n-1);
        numerator = pow(x,exponent);

        int i;
        for(i=1;i<=exponent;i++){
            divisor *= i;
        }
        n += 1;
        numerator *= sign;
        sum += (numerator/divisor);
    } while(fabs((numerator/divisor)) >= a);
    sum -= (numerator/divisor);
    n -= 3;
    printf("The value of cos(x) is %lf \n", cos(x));
    printf("The value of the Taylor expression (%i-th order) is %lf", n,sum);
}