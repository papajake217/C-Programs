#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Enter the character to be searched: ");
    char search;
    scanf("%c", &search);
    printf("Enter a string: ");
    char string[100];
    scanf("%s", &string);

    int i,count = 0;
    for (i=0;i<100;i++){
        if (string[i] == search){
            count += 1;
        }
    }
    printf("The character %c occurs %i times", search, count);
}