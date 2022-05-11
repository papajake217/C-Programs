#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int rows;
struct Person
    {
        char firstName[10];
        char lastName[15];
        int zipcode;
        int age;
        float gpa;

    };


void displayInfo(struct Person info[]){
    int i;
    for(i=0;i<rows;i++){
        printf("%s %s %d %d %0.3f\n",info[i].firstName,info[i].lastName,info[i].zipcode,info[i].age,info[i].gpa);
    }
}

void readFile(FILE *inputFile,struct Person Persons[]){
    
    int i;
    for(i=0;i<rows;i++){
        fscanf(inputFile,"%s %s %d %d %f",&Persons[i].firstName,&Persons[i].lastName,&Persons[i].zipcode,&Persons[i].age,&Persons[i].gpa);
    }
    
    
}

void gpaOrder(struct Person Persons[]){
    int i,j;
    char tempFirstName[10];
    char tempLastName[15];
    int tempZipcode;
    int tempAge;
    float tempGPA;
    for(i=0;i<rows;i++){
        for(j=0;j<rows-1;j++){
            if(Persons[j].gpa < Persons[j+1].gpa){
                strcpy(tempFirstName,Persons[j].firstName);
                strcpy(tempLastName,Persons[j].lastName);
                tempZipcode = Persons[j].zipcode;
                tempAge = Persons[j].age;
                tempGPA = Persons[j].gpa;
                strcpy(Persons[j].firstName,Persons[j+1].firstName);
                strcpy(Persons[j].lastName,Persons[j+1].lastName);
                Persons[j].zipcode = Persons[j+1].zipcode;
                Persons[j].age = Persons[j+1].age;
                Persons[j].gpa = Persons[j+1].gpa;
                strcpy(Persons[j+1].firstName,tempFirstName);
                strcpy(Persons[j+1].lastName,tempLastName);
                Persons[j+1].zipcode = tempZipcode;
                Persons[j+1].age = tempAge;
                Persons[j+1].gpa = tempGPA;
            }
        }
    }
}
void lastNameOrder(struct Person Persons[]){
    int i,j;
    char tempFirstName[10];
    char tempLastName[15];
    int tempZipcode;
    int tempAge;
    float tempGPA;
    for(i=0;i<rows;i++){
        for(j=0;j<rows-1;j++){
            if(strcmp(Persons[j].lastName,Persons[j+1].lastName) > 0){
                strcpy(tempFirstName,Persons[j].firstName);
                strcpy(tempLastName,Persons[j].lastName);
                tempZipcode = Persons[j].zipcode;
                tempAge = Persons[j].age;
                tempGPA = Persons[j].gpa;
                strcpy(Persons[j].firstName,Persons[j+1].firstName);
                strcpy(Persons[j].lastName,Persons[j+1].lastName);
                Persons[j].zipcode = Persons[j+1].zipcode;
                Persons[j].age = Persons[j+1].age;
                Persons[j].gpa = Persons[j+1].gpa;
                strcpy(Persons[j+1].firstName,tempFirstName);
                strcpy(Persons[j+1].lastName,tempLastName);
                Persons[j+1].zipcode = tempZipcode;
                Persons[j+1].age = tempAge;
                Persons[j+1].gpa = tempGPA;
            }
        }
    }
}

void matchZipcode(struct Person Persons[]){
    int inputZipcode;
    printf("Enter a zipcode to match: ");
    scanf("%d",&inputZipcode);

    int i;
    printf("People with matching zipcode: \n");
    for(i=0;i<rows;i++){
        if(Persons[i].zipcode == inputZipcode){
            printf("%s %s %d %d %0.3f\n",Persons[i].firstName,Persons[i].lastName,Persons[i].zipcode,Persons[i].age,Persons[i].gpa);
        }
    }
}

int main(){
    FILE *inputFile = fopen("in1.txt","r");
    if(inputFile == NULL){
        printf("Error, no input file");
        exit(1);
    }
    char command = 'a';
    fscanf(inputFile,"%d",&rows);
    struct Person Persons[rows];
    readFile(inputFile,Persons);
    
    while(command != 'E'){
        printf("Enter a command (E to exit):\n");
        scanf("%c",&command);
        getchar();
        switch(command){
            case 'D':
                displayInfo(Persons);
                break;
            case 'O':
                gpaOrder(Persons);
                displayInfo(Persons);
                break;
            case 'A':
                lastNameOrder(Persons);
                displayInfo(Persons);
                break;
            case 'Z':
                matchZipcode(Persons);
                break;
            case 'E':
                command = 'E';
                break;
            default:
                printf("Invalid command");
                break;
        }
        printf("\n");
    }


}