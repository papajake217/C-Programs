#include <stdio.h>
#include <string.h>
int my_strcmp(char* stringOne,char* stringTwo){
    int i = 0;
    int checker = 0;
    while(stringOne[i] != '\0'){
        if(stringOne[i] == stringTwo[i]){
            checker += 1;
        }
        i += 1;
    }

    if(checker == i){
        return 0;
    } else{
        return 1;
    }
}

int my_strncmp(char* stringOne,char* stringTwo, int n){
    int i;
    int checker = 0;
    for(i=0;i<n;i++){
        if(stringOne[i] == stringTwo[i]){
            checker += 1;
        }
    }
    
    if(checker == n){
        return 0;
    } else{
        return 1;
    }

}

int my_strcpy(char *string1,char *string2){
    int i;
    
    for(i=0;string2[i] != '\0';i++){
        string1[i] = string2[i];
    }
    string1[i] = '\0';
    return string1;
}

int my_strncpy(char* string1,char* string2, int n){
    int i;

    for(i=0;i<n;i++){
        string1[i] = string2[i];
    }
    string1[i] = '\0';

    return string1;
}

int my_strcat(char* string1,char* string2){
    int i;
    int length = strlen(string1) + strlen(string2);
    int x = 0;
    for(i=strlen(string1);i<length;i++){
        string1[i] = string2[x];
        x++;
    }
    string1[i] = '\0';
    return string1;
}

int my_reverse(char* dest,char* src){
    int i;
    int x = 0;
    for(i=(strlen(src)-1);i>=0;i--){
        dest[x] = src[i];
        x++;
    }

    return dest;
}


int main(){
    printf("Strcmp: \n");
    char String1[10] = "Hello";
    char String2[10] = "Hi";    
    printf("%s and %s: %c\n",String1,String2,my_strcmp(String1,String2));
    char s1[10] = "Hello";
    char s2[10] = "Hello";
    printf("%s and %s: %c\n",s1,s2,my_strcmp(s1,s1));

    printf("Strncmp:\n");
    char a[10] = "Hello";
    char b[10] = "Hi";
    printf("%s and %s n=2: %d\n",a,b,my_strncmp(a,b,2));
    printf("%s and %s n=1: %d\n",a,b,my_strncmp(a,b,1));

    printf("Strcpy: \n");
    char dest[128];
    char src[10] = "hellow";
    int address = my_strcpy(dest,src);
    printf("Copied String: %s , Address: %d\n",dest,address);
    char copy[128];
    char inputString[10] = "copy me";
    address = my_strcpy(copy,inputString);
    printf("Copied String: %s, Address: %d\n",copy,address);

    printf("Strncpy: \n");
    char destination[128];
    char source[10] = "hellow";
    int n = 5;
    address = my_strncpy(destination,source,n);
    printf("Copied String n=5: %s , Address: %d\n",destination,address);
    char str[128];
    char copyThis[10] = "ESE 124";
    address = my_strncpy(str,copyThis,3);
    printf("Copied String n=3: %s , Address: %d\n",str,address);

    printf("Strcat:\n");
    char str1[4] = "hi";
    char str2[15] = "newyork";
    address = my_strcat(str1,str2);
    printf("New string: %s  Address: %d\n",str1,address);
    char str3[10] = "Hello ";
    char str4[6] = "Jake";
    address = my_strcat(str3,str4);
    printf("New string: %s  Address: %d\n",str3,address);

    printf("Reverse:\n");
    char ogString[10] = "hellow";
    char reversed[10];
    address = my_reverse(reversed,ogString);
    printf("Reversed string: %s  Address: %d\n",reversed,address);
    char originalString[10] = "ESE 124";
    char reverseThis[10];
    int addy = my_reverse(reverseThis,originalString);
    printf("Reversed string: %s %d \n",reverseThis,addy);


    
}
