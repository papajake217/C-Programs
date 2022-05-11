#include <stdio.h>

int my_isalpha(char input){
    if((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z') ){
        return 1;
    } else{
        return 0; 
    }
}

int my_isdigit(char input){
    if(input >= '0' && input <= '9'){
        return 1;
    } else{
        return 0;
    }

}

int my_alnum(char input){
    if(my_isalpha(input) == 1 || my_isdigit(input) == 1){
        return 1;
    } else{
        return 0;
    }
}

int my_is_upper(char input){
    if(input >= 'A' && input <= 'Z'){
        return 1;
    } else{
        return 0;
    }
}

int my_is_lower(char input){
    if(input >= 'a' && input <= 'z'){
        return 1;
    } else{
        return 0;
    }
}

char my_to_upper(char input){
    if(my_is_lower(input) == 1){
        input -= 32;
        return input;
    } else{
        return input;
    }
}

char my_to_lower(char input){
    if(my_is_upper(input) == 1){
        input += 32;
        return input;
    } else{
        return input;
    }
}

int main(){
    printf("my_isalpha:\n");
    int check = my_isalpha('Z');
    printf("Z: %d\n",check);
    check = my_isalpha('5');
    printf("5: %d\n",check);

    printf("my_isdigit:\n");
    check = my_isdigit('A');
    printf("A: %d\n",check);
    check = my_isdigit('9');
    printf("9: %d\n",check);
    
    printf("my_alnum:\n");
    check = my_alnum('A');
    printf("A: %d\n",check);
    check = my_alnum('9');
    printf("9: %d\n",check);

    printf("my_is_upper:\n");
    check = my_is_upper('A');
    printf("A: %d\n",check);
    check = my_is_upper('a');
    printf("a: %d\n",check);

    printf("my_is_lower:\n");
    check = my_is_lower('A');
    printf("A: %d\n",check);
    check = my_is_lower('a');
    printf("a: %d\n",check);  

    printf("my_to_upper:\n");
    char letter = my_to_upper('a');
    printf("a -> %c\n",letter);
    letter = my_to_upper('A');
    printf("A -> %c\n",letter);

    printf("my_to_lower:\n");
    letter = my_to_lower('A');
    printf("A -> %c\n",letter);
    letter = my_to_lower('a');
    printf("a -> %c\n",letter);

}