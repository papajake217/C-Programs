#include <stdio.h>

int main(){
	int i;

	for(i=0;i<3;i++){
		printf("Input date (Month/Day/Year): ");
		int day,month,year;
		char date[32],scanfVariable;
		gets(date);
		sscanf(date, "%d/%d/%d", &month, &day, &year);
		printf("Month: %d - Day: %d - Year: %d \n", month, day, year);
	}
	
}
