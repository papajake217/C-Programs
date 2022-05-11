#include <stdio.h>

int main(){
    unsigned int val;
    int p,n;
    // Since its an unsigned int, if 1f in decimal is entered (31), it will produce 7. This is the same result as part 1 except using decimal numbers instead.
    printf("Enter a value: ");
    scanf("%d", &val);
    getchar();
    printf("Enter p (int less than 8): ");
    scanf("%d", &p);
    printf("Enter n (int less than 8): ");
    scanf("%d", &n);
    p = 7 - p;
    n = 8 - n;
    val = val << p;
    val = val >> n;
    printf("Output: %x", val);
    

}
