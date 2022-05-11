#include <stdio.h>

int main(){
	
	// adds numbers together, edit i<5 for different amount of numbers in the sum
	float ye, result = 0.0;
	int i;
	for(i=0; i<5; i++){
		printf("Enter a number: ");
		scanf("%f", &ye);
		
		result += ye;
		printf("Sum is: %0.3f", result);
		printf("\n");
	}	 
}
