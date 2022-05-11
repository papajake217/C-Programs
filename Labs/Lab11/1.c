#include <stdio.h>
#include <string.h>
int main(){
    char  str[20], *p;	
    printf("Input about 10 characters of string\n");
    scanf("%s",str);
    
    p = &str;
    int i,j;
    for(i=0;i<strlen(str);i++){
        printf("%s",p);
        p += 1;
        printf("\n");
    }
}