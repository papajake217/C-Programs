#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char wordToGuess[20];
    printf("Enter word to guess: ");
    scanf("%s",&wordToGuess);

    int incorrectGuesses;
    printf("Enter allowed number of incorrect guesses: ");
    scanf("%d", &incorrectGuesses);

    int lengthOfWord = strlen(wordToGuess);
    char guessed[lengthOfWord];
    strcpy(guessed,wordToGuess);

    int i;
    for (i=0;i<sizeof(guessed);i++){
        guessed[i] = '*';
    }

    int incorrectGuessesMade = 0;
    char playerGuess;
    int j;
    int check = 0;
    while(incorrectGuessesMade < incorrectGuesses && strcmp(guessed,wordToGuess) != 0){
        printf("Enter a letter to guess: ");
        getchar();
        scanf("%c",&playerGuess);
        
        for(j=0;j<lengthOfWord;j++){
            if(playerGuess == wordToGuess[j]){
                guessed[j] = playerGuess;
                check = 1;
            }
        }

        if (check != 1){
            incorrectGuessesMade += 1;
        } else {
            check = 0;
        }

        printf("Guess so far: %s \n", guessed);
        printf("Guesses left %d \n", incorrectGuesses - incorrectGuessesMade);

    }

    if(incorrectGuessesMade <= incorrectGuesses && strcmp(guessed,wordToGuess) == 0){
        printf("Word has been guessed, you win");
    } else {
        printf("Word has not been guessed, computer wins");
    }
    
}