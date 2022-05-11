#include <stdio.h>

int main(){
    unsigned char val, mask;
    int p, n;
    printf("Enter a hexadecimal value: ");
    scanf("%x", &val);
    printf("Enter p (int less than 8): ");
    scanf("%d", &p);
    printf("Enter n (int less than 8): ");
    scanf("%d", &n);
    unsigned char letter;
    
    while (letter != 'Q'){
        printf("Enter a command: S, R, F, D, I: (Q to quit) ");
        getchar();
        scanf("%c", &letter);
        if (letter == 'S'){
            mask = 0xFF;
            mask = mask << (8 - n);
            mask = mask >> (7 - p);
            unsigned char result = val | mask;
            printf("Result is %x \n", result);
        } 
        if (letter == 'R'){
            mask = 0xFF;
            mask = mask << (8 - n);
            mask = mask >> (7 - p);
            mask = ~mask;
            unsigned char result = val & mask;
            printf("Result is %x \n", result);
        }
        if (letter == 'F'){
            mask = 0xFF;
            mask = mask << (8 - n);
            mask = mask >> (7 - p);
            unsigned char result = val ^ mask;
            printf("Result is %x \n", result);
        }
        if (letter == 'D'){
            printf("Value of the variable is %d \n", val);
        }
        if (letter == 'I'){
            printf("Enter a new hex value: ");
            scanf("%x", &val);
        }
    }

}
