#include <stdio.h>
#include <ctype.h>
int main(){
    char vowels[5] = {'a','e','i','o','u'};
    char input;
    int check = 1;
    int vowelCheck;
    while (check > 0){
        int i;
        vowelCheck = 0;
        printf("Enter a letter (# to end): ");
        scanf("%c", &input);
        getchar();
        if (input == '#'){
            break;
        }
        if (isalpha(input)){
            for (i=0;i<5;i++){
                if (input == vowels[i]){
                    vowelCheck = 1;
                }
            }
        
            if (vowelCheck == 1){
            printf("The character is a vowel \n");
            } else {
                printf("The character is a consonant \n");
            }
        } else {
            printf("Error, character is not a letter \n");
        }
    }
}
