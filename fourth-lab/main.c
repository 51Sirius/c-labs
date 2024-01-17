#include "stdio.h"

int main() {
    char numb;
    scanf("%d", &numb);
    char st = 76;
    char st1 = 77;
    char st2 = 78;
    char tmp = st ^ numb;
    char tmp2 = st1 ^ numb;
    char tmp3 = st2 ^ numb;
    while (tmp == 0) {
        printf("Yes");
        break;
    }
    while (tmp2 == 0) {
        printf("Yes");
        break;
    }
    while (tmp3 == 0) {
        printf("Yes");
        break;
    }
    int numb1;
    scanf("%d", &numb1);
    int ind= numb1>>6;
    ind = ind&1;
    printf("%d", ind);
    return 0;
}