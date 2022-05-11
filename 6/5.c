#include <stdio.h>
#include <ctype.h>

int countChars(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int main(){
    FILE* inputFile = fopen("input.txt","r");
    char input[26];
    int check;
    int i;
    int occurences[26];
    for(i=0;i<26;i++){
        occurences[i] = 0;
    }

    while(fscanf(inputFile,"%s",input) != EOF){
        check = 1;
        int result = countChars(input);
        for(i=0;i<result;i++){
            if (!(isalpha(input[i]))){
                check = 0;
            }
        }
        if(check == 1){
            occurences[result] += 1;
        }
    }

    for(i=1;i<=25;i++){
        printf("length %d: %d occurrences\n",i,occurences[i]);
    }

}