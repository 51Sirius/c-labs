#include "stdio.h"
#include <stdlib.h>

//1 6 8 10 12
void str_plus_str(char str1[], char str2[], char str3[], int n1, int n2) {
    for (int i = 0; i < n1; ++i) {
        str3[i] = str1[i];
    }
    for (int i = 0; i < n2; ++i) {
        str3[n1 + i] = str2[i];
    }
}

void copy_to(char str1[], char str4[], int n4) {
    for (int i = 0; i < n4; ++i) {
        str4[i] = str1[i];
    }
}

int search_first(char str1[], int n1, char s) {
    for (int i = 0; i < n1; ++i) {
        if (s == str1[i]) {
            return i + 1;
        } else if (i == n1 - 1) {
            return 0;
        }
    }
}

int count_symb(char str1[], char str2[],int n1, int n2){
    int tmp = n1;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            if (str1[i] == str2[j]) {
                tmp--;
                break;
            }
        }
        printf("%c", str1[i]);
    }
    return tmp;
}

int main() {
    int n1;
    int n2;
    printf("Enter len your string 1:");
    scanf("%d", &n1);
    printf("Enter len your string 2:");
    scanf("%d", &n2);
    char str1[n1];
    char str2[n2];
    fflush(stdin);
    fgets(str1, n1 + 1, stdin);
    fflush(stdin);
    fgets(str2, n2 + 1, stdin);
    int n3 = n1 + n2;
    char *str3 = malloc(n3);
    str_plus_str(str1, str2, str3, n1, n2);
    printf("str1+str2=");
    for (int i = 0; i < n3; ++i) {
        printf("%c", str3[i]);
    }
    int n4;
    printf("\nEnter how much symbol you want to copy:");
    scanf("%d", &n4);
    char *str4 = malloc(n4);
    copy_to(str1, str4, n4);
    printf("Your copy str=");
    for (int i = 0; i < n4; ++i) {
        printf("%c", str4[i]);
    }
    char s;
    fflush(stdin);
    printf("\nEnter symbol which you want search:");
    scanf("%c", &s);
    printf("Your symbol on %d place", search_first(str1, n1, s));
    s = str2[0];
    printf("\nsymbol - %c on %d place", s, search_first(str1, n1, s));
    printf("\nLen of line without symbols which was in second str: %d", count_symb(str1,str2, n1, n2));
    return 0;
}