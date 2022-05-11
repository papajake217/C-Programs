#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ESE999 5 Marshmello 2

struct Course{
        char title[20];
        int credits;
        char instructor[15];
        int sequence;
    }course[10],temp;

int main(){
    
    int count = 0;
    FILE *inputFile = fopen("input.txt","r");
    if(inputFile == NULL){
        printf("Error no input file");
        exit(1);
    }
    
    char input[50];
    int num;
    while(fscanf(inputFile,"%s",&input) != EOF){
        strcpy(course[count].title,input);
        fscanf(inputFile,"%d",&num);
        course[count].credits = num;
        fscanf(inputFile,"%s",&input);
        strcpy(course[count].instructor,input);
        fscanf(inputFile,"%d",&num);
        course[count].sequence = num;
        count++;
    }

    printf("The contents of the array are: \n");
    int i;
    for(i =0;i<count;i++){
        printf("%s %d %s %d\n",course[i].title,course[i].credits,course[i].instructor,course[i].sequence);
    }
    int j;
    
    for(int i=0;i<count;i++){
        for(int j=0;j<count-1;j++){
            if(strcmp(course[j].title,course[j+1].title)>0){
                temp = course[j];
                course[j] = course[j+1];
                course[j+1] = temp;
            }
        }
    }

    printf("\nSorted by course title alphabetically: \n");
    for(int i=0;i<count;i++){
        printf("%s %d %s %d\n",course[i].title,course[i].credits,course[i].instructor,course[i].sequence);
    }   

    printf("Enter how many credits can be taken per year: ");
    int maxCredits;
    scanf("%d",&maxCredits);
    getchar();

     for(int i=0;i<count;i++){
        for(int j=0;j<count-1;j++){
            if(course[j].sequence > course[j+1].sequence){
                temp = course[j];
                course[j] = course[j+1];
                course[j+1] = temp;
            }
        }
    }
    int c[count];
    for(i = 0;i<count;i++){
        c[i] = 0;
    }
    int fulfilled = 0;
    int year = 1;
    int credits = 0;
    while(fulfilled == 0){
        credits = 0;
        printf("Year %d:\n",year);
        for(i=0;i<count;i++){
            if(course[i].sequence == year && credits + course[i].credits <= maxCredits && c[i] == 0){
                printf("%s %d %s %d\n",course[i].title,course[i].credits,course[i].instructor,course[i].sequence);
                c[i] = 1;
                credits += course[i].credits;
            }
        }
        if(credits < maxCredits){
            for(i=0;i<count;i++){
                if(course[i].sequence - year == 1 && credits + course[i].credits <= maxCredits && c[i] == 0){
                    printf("%s %d %s %d\n",course[i].title,course[i].credits,course[i].instructor,course[i].sequence);
                    c[i] = 1;
                    credits += course[i].credits;
                }
            }
        }
        year++;
        int sum = 0;
        for(int i=0;i<count;i++){
            if(c[i] == 1){
                sum++;
            }
        }
        if(sum == count){
            fulfilled = 1;
        }
    }
}