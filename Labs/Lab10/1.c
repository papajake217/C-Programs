#include <stdio.h>
#include <math.h>


float* function(float *input){

    
}


float squareRoot(float leftLimit,float rightLimit,float points){
    float count = 0, sum = 0;
    float i;

    for(i=leftLimit;i<=rightLimit;i+=((rightLimit-leftLimit)/points)){
        if(count == 0 || count == points){
            sum += sqrt(i);
        } else{
            sum += 2*(sqrt(i));
        }
        count++;
    }
    sum *= ((rightLimit-leftLimit)/(2*points));
    return sum;
}

float ln(float leftLimit, float rightLimit, float points){
    float count = 0,sum = 0;
    float i;
    for(i=leftLimit;i<=rightLimit;i+=((rightLimit-leftLimit)/points)){
        if(count == 0 || count == points){
            sum += log(i);
        } else{
            sum += 2*(log(i));
        }
        count++;
    }
    sum *= ((rightLimit-leftLimit)/(2*points));
    return sum;
    
}

float exponential(float leftLimit, float rightLimit, float points){
    float count = 0,sum = 0;
    float i;
    for(i=leftLimit;i<=rightLimit;i+=((rightLimit-leftLimit)/points)){
        if(count == 0 || count == points){
            sum += exp(i);
        } else{
            sum += 2*exp(i);
        }
        count++;
    }
    sum *= ((rightLimit-leftLimit)/(2*points));
    return sum;
    
}


float square(float leftLimit, float rightLimit, float points){
    float count = 0,sum = 0;
    float i;
    for(i=leftLimit;i<=rightLimit;i+=((rightLimit-leftLimit)/points)){
        if(count == 0 || count == points){
            sum += pow(i,2);
        } else{
            sum += 2*(pow(i,2));
        }
        count++;
    }
    sum *= ((rightLimit-leftLimit)/(2*points));
    return sum;
    
}

float cube(float leftLimit, float rightLimit, float points){
    float count = 0,sum = 0;
    float i;
    for(i=leftLimit;i<=rightLimit;i+=((rightLimit-leftLimit)/points)){
        if(count == 0 || count == points){
            sum += pow(i,3);
        } else{
            sum += 2*(pow(i,3));
        }
        count++;
    }
    sum *= ((rightLimit-leftLimit)/(2*points));
    return sum;
}

float error(float actual, float calc){
    float num = calc-actual;
    float error = 0;
    if(num>0){
        num *= -1;
    }
    if(actual > 0){
        actual *= -1;
    }

    error = num/actual;

    error = (1.00000-error) * 100.00000;
    return error;
}

int main(){
    printf("The integral for square root from 0 to 1 (with 100 discretization points) is %f\n", squareRoot(0,1,100));
    printf("The integral for ln from 0.01 to 1 (with 100 discretization points) is %f\n", ln(0.01,1,100));
    printf("The integral for exponential from 0 to 1 (with 100 discretization points) is %f\n", exponential(0,1,100));
    printf("The integral for square from 0 to 1 (with 100 discretization points) is %f\n", square(0,1,100));
    printf("The integral for cubic from 0 to 1 (with 100 discretization points) is %f\n", cube(0,1,100));

    printf("The function of the computed integrals the function square with 3, 5, 10, 50, 100 discretization points:\n");
    printf("From 0 to 1: %f%%,  %f%%,  %f%%,  %f%%,  %f%% \n", error(square(0,1,100),square(0,1,3)),error(square(0,1,100),square(0,1,5)),error(square(0,1,100),square(0,1,10)),error(square(0,1,100),square(0,1,50)),error(square(0,1,100),square(0,1,100)));
    // change the actual points from 100 to 1000
}