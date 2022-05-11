#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int stack[8];
int top = -1;
bool check = false;



int is_Empty(){
    if(top == -1){
        return 1;
    } 
    return 0;
}

int is_Full(){
    if(top == 8){
        return 1;
    }
    return 0;
}

void pop(){
    int value;

    if(is_Empty() == 0){
        value = stack[top];
        top--;
    }else{
        check = true;
    }
}

void push(int val){
    if(is_Full() == 0){
        top++;
        stack[top] = val;
    } else{
        printf("Error, stack is full, could not push input");
    }
}


int main(){
    FILE *inputFile = fopen("in1.txt","r");
    char c;
    if(inputFile == NULL){
        printf("Error no file");
        exit(1);
    }

    while(fscanf(inputFile,"%c",&c) != EOF){
        if(c == '['){
            push(1);
        } else if(c == ']'){
            pop();
        }
    }

    if(is_Full() == 0 && check == false){
        printf("Sequence of characters is balanced");
    } else {
        printf("Sequence of characters is unbalanced");
    }

    /* #2
    c and d cannot occur because in the process of pushing onto the stack and popping off of it, 
    there is an error where you cannot get a certain number without popping one that you are not supposed to.
    This error occurs at 7 in c, and 0 in d. In the sequences for c and d, the numbers are not in the correct order in 
    which the integers can be successfully pushed onto the stack. 
    Inversely, for a and b, after pushing and popping, the stacks can be perfectly pushed and popped, resulting in no errors.
    a and b exist as possible sequences where 0-9 can be pushed and popped successfully.
        *\
}
