#include <stdio.h>

int main(){
    unsigned char valueOne,valueTwo, val, placeHolder, mask, compareOne, compareTwo, result;
    int p,n;
    printf("Enter first hexadecimal value: ");
    scanf("%x", &valueOne);
    val = valueOne;
    getchar();
    printf("Enter second hexadecimal value: ");
    scanf("%x", &valueTwo);
    getchar();
    printf("Enter p (int less than 8): ");
    scanf("%d", &p);
    printf("Enter n (in less than 8): ");
    scanf("%d", &n);
    placeHolder = 0xFF;
    mask = 0xFF;
    valueOne = val;
    placeHolder = placeHolder << (8 - n);
    placeHolder = placeHolder >> (7 - p);
    placeHolder = ~placeHolder;
    printf("%x \n", valueOne);
    compareOne = valueOne & placeHolder;
    mask = mask >> 8 - n;
    compareTwo = valueTwo & mask;
    compareTwo = compareTwo << p + 1 - n;
    result = compareOne | compareTwo;
    printf("%x", result);
}
