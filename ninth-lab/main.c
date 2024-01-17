#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    char chislition[10][10] = {"zero", "one", "two", "three", "four", "five", "six",
                               "seven", "eight", "nine"};
    gets(str);
    int n = strlen(str);
    int count_bukvki = 0;
    int count_numbers = 0;
    for (int i = 0; i < n; i++) {
        int ids = (int) str[i];
        if (48 <= ids && ids <= 57) {
            count_numbers++;
        }
        if (65 <= ids && ids <= 122) {
            count_bukvki++;
        }
    }
    printf("Count of bukovki: %d\nCount of numbers: %d\n", count_bukvki, count_numbers);
    int numb;
    scanf("%d", &numb);
    printf("This is your number in chislition: %s", chislition[numb]);
    return 0;
}