#include <stdio.h>
#include <string.h>
int main(){
    char s[20];
    printf("Enter a string to be reversed: ");
    scanf("%s",&s);
    char* cptr;
    cptr = &s;
    int length = strlen(s);
    char *start = s;
    char *end = s;

    int i;
    for(i = 0;i<length-1;i++){
        end++;
    }

    char letter;
    for(i = 0;i<length/2;i++){
        letter = *end;
        *end = *start;
        *start = letter;

        start++;
        end--;
        
    }
    printf("%s",s);


}