#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *toPigLatin(char word[]){

    char letter = word[0];
    int upper = 0;
    if(letter >= 65 && letter<=90){
        upper = 1;
    }
    letter = tolower(letter);
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter =='o' || letter == 'u'){
        strcat(word,"way");
    } else{
        int length = strlen(word);
        int i = 0;
        if(letter =='y'){
            word[length] = letter;
            i += 1;
            letter = word[i];
            length+=1;
        }
        while(letter != 'a' && letter != 'e' && letter != 'i' && letter != 'o' && letter != 'u' && letter != 'y'){
            word[length] = letter;
            i += 1;
            letter = word[i];
            length+=1;
        }
        
        
        word[length] = 'a';
        word[length+1] = 'y';
        strncpy(word,word+i,strlen(word));
        if(upper == 1){
            word[0] = toupper(word[0]);
        }
        word[length+1] = '\0';
    }
    int x;
    for(x=1;x<strlen(word);x++){
        word[x] = tolower(word[x]);
    }

    return word;
}

int main(){
    
    int i;
    char word[100];
    printf("Enter 5 words: ");
    for(i=0;i<5;i++){
     scanf("%s",&word);
     toPigLatin(word);
     printf("%s ",word);
    }
}
