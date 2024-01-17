#include <stdio.h>
#include <string.h>

void gen_massive(int n, int arr[], char str[]){
    for (int i=0;i<n;i++){
        arr[i]=(int)str[i]-48;
    }
}
int nod(int a, int b){
    int i = a;
    int j = b;
    while (i!=j){
        if (i > j){
            i -= j;
        } else {
            j -= i;
        }
    }
    return i;
}


int nok(int a, int b){
    return (a*b)/ nod(a,b);
}




int main(){
    int n1;
    int n2;
    scanf("%d %d", &n1, &n2);
    printf("NOD:%d\n", nod(n1, n2));
    printf("NOK:%d\n", nok(n1, n2));
    char n[1000];
    scanf("%s", &n);
    int count = strlen(n);
    int arr[count];
    gen_massive(count, arr, n);
    for (int i = 0; i < count; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}