#include <math.h>
#include <stdio.h>

int main(){
	int i;
	for(i=0;i<10;i++){
	
		double num;
		char operation;
		double result;
		printf("\nEnter a number: \n");
		scanf("%lf", &num);
	
		printf("Enter an operation (e,/,r,m): \n");
		scanf(" %c", &operation);
	
		if(operation == '/'){
			if (num>0){
				result = log(num);
				printf("Result is %lf", result);
			}
			else{
				printf("Error, can't do ln of a negative number");
			}
		}
		if(operation == 'r'){
			if (num>0){
				result = sqrt(num);
				printf("Result is %lf", result);
			} 
			else {
				printf("Error, can't take square root of negative number");
			}
		}
		if(operation == 'm'){
			result = fabs(num);
			printf("Result is %lf", result);
		}
		if(operation == 'e'){
			if (num>0){
				result = exp(num);
				printf("Result is %lf", result);
			}
			else {
				printf("Error, can't do negatives");
			}
		}

		
	
	}
}
