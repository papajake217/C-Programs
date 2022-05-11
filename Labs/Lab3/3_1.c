#include <stdio.h>
#include <math.h>
int main(){
    int n = 0;
    double x, a;
    double sum = 1;
    printf("Enter the value x: ");
    scanf("%lf", &x);
    printf("Enter the positive threshold: ");
    scanf("%lf", &a);
    double actual = 1/(1-x);
    if (x < 0){
        sum = 0;
    }
    do {
        if (x > 0){
            n += 1;
        }
        sum += pow(x,n);
        if (x < 0){
            n += 1;
        }

    } while (fabs((pow(x,n))) >= a);
    printf("The value of the Taylor series expression (%i-th order) is: %lf", n,sum);
}