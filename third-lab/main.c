#include "stdio.h"

int main() {
    int numb1;
    int numb2;
    scanf("%x", &numb1);
    printf("10 sys-%d\n", numb1);
    printf("16 sys-%x\n", numb1);
    printf("16 sys with bit sdig 2-%x\n", numb1 >> 2);
    printf("16 sys with-%x\n", numb1);
    printf("16 sys with nonbit-%x\n", ~numb1);
    scanf("%x", &numb2);
    printf("%x and %x-%x\n", numb1, numb2, numb1 & numb2);
    printf("%x or %x-%x\n", numb1, numb2, numb1 | numb2);
    printf("%x xor %x-%x\n", numb1, numb2, numb1 ^ numb2);
    return 0;
}